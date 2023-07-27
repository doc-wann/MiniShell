/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:19:37 by mmuriloj          #+#    #+#             */
/*   Updated: 2023/07/27 20:06:50 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	chdir_path(char *path)
{
	char	*pwd;
	char	buf[2048];

	pwd = ht_search("PWD")->value;
	if (chdir(path) == 0)
	{
		if (ht_search("OLDPWD"))
			ht_delete(g_minishell.env, "OLDPWD");
		ht_insert(g_minishell.env, "OLDPWD", pwd);
		pwd = getcwd(buf, 2048);
		ht_delete(g_minishell.env, "PWD");
		ht_insert(g_minishell.env, "PWD", pwd);
	}
}

// void	chdir_path(char *path)
// {
// 	char	*pwd;
// 	char	buf[2048];

// 	pwd = getcwd(buf, 2048);
// 	if (ht_search("PWD"))
// 	{
// 		ht_delete(g_minishell.env, "OLDPWD");
// 		ht_insert(g_minishell.env, "OLDPWD", pwd);
// 		chdir(path);
// 		pwd = getcwd(buf, 2048);
// 		ht_delete(g_minishell.env, "PWD");
// 		ht_insert(g_minishell.env, "PWD", pwd);
// 	}
// }

static void	chdir_oldpwd(void)
{
	if (ht_search("OLDPWD"))
		chdir_path(ht_search("OLDPWD")->value);
	else
	{
		write(1, "bash: cd: OLDPWD not set\n", 26);
		return ;
	}

}

// static void	chdir_home()
// {
// 
// }

void	ft_cd(char *dir)
{

	if (!dir || ft_strcmp(dir, "~") == 0)
		chdir_path("~");
	else if (ft_strcmp(dir, "-") == 0)
		chdir_oldpwd();
	else
		chdir_path(dir);
}
