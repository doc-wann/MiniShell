/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:19:37 by mmuriloj          #+#    #+#             */
/*   Updated: 2023/08/02 15:24:25 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	chdir_home(void);

void	chdir_path(char *path)
{
	char	*pwd;
	char	buf[2048];

	if (ft_strncmp(path, "~/", 2) == 0)
	{
		chdir_home();
		path = path + 2;
	}
	pwd = ht_search(g_minishell.env, "PWD")->value;
	if (chdir(path) == 0)
	{
		if (ht_search(g_minishell.env, "OLDPWD"))
			ht_delete(g_minishell.env, "OLDPWD");
		ht_insert(g_minishell.env, "OLDPWD", pwd);
		pwd = getcwd(buf, 2048);
		ht_delete(g_minishell.env, "PWD");
		ht_insert(g_minishell.env, "PWD", pwd);
	}
}

static void	chdir_oldpwd(void)
{
	if (ht_search(g_minishell.env, "OLDPWD"))
		chdir_path(ht_search(g_minishell.env, "OLDPWD")->value);
	else
	{
		write(1, "bash: cd: OLDPWD not set\n", 26);
		return ;
	}

}

static void	chdir_home(void)
{
	char	*home_path;

	home_path = ft_strdup(ht_search(g_minishell.env, "HOME")->value);
	chdir_path(home_path);
	free(home_path);
}

void	ft_cd(char *dir)
{

	if (!dir || ft_strcmp(dir, "~") == 0)
		chdir_home();
	else if (ft_strcmp(dir, "-") == 0)
		chdir_oldpwd();
	else
		chdir_path(dir);
}
