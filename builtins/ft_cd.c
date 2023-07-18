/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:19:37 by mmuriloj          #+#    #+#             */
/*   Updated: 2023/07/18 18:36:27 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(char *dir, char **env)
{
	char	*homepath;

	homepath = get_env(env, "$HOME");
	if (!dir || ft_strncmp(dir, "~", 1) == 0)
		chdir(homepath);
	else
		chdir(dir);
	ft_pwd();
	// if (args[0] == "cd")
	// {
	// 	if (!args[1])
	// 		chdir(homepath);
	// }
	// else
	// 	return ;
}