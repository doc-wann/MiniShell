/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:19:37 by mmuriloj          #+#    #+#             */
/*   Updated: 2023/08/29 19:36:48 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *ft_backtrack(char *track);

void	ft_cd(char **args, char **envs)
{
	char *homepath;
	char *compare;

	int test;

	compare = ft_strdup("cd");

	homepath = get_env(envs, "$HOME");
	if(ft_strncmp(args[0], "cd ", 2) == 0)
	{
		if (ft_strncmp(args[1], "$", 1) == 0)
			args[1] = get_env(envs, args[1]);
		compare = "..";
		if(!args[1])
		{
			if (chdir(ft_strjoin("/",homepath)) != 0)
				printf("error when taking you home\n");
		}
		else if (args[1])
		{
			if (ft_strncmp(args[1], "..\0", 3) == 0)
			{
				chdir(ft_backtrack(getcwd(NULL, 100)));
			}
			else if (ft_strncmp(args[1], "../", 3) == 0)
			{
				chdir(ft_backtrack(getcwd(NULL, 100)));
				args[1] += 3;
				ft_cd(args, envs);
			}
			else if(chdir(ft_strjoin(getcwd(NULL, 100), path_parser(args[1]))) != 0)
				write(1, ft_strjoin(ft_strjoin("cd: no such file or directory: ", args[1]), "\n"), 31 + ft_strlen(args[1]) + 1);
		}
	}
	else
		return ;
}

//maynotbeneeded :(
char *ft_backtrack(char *track)
{
	int i;

	i = 0;
	while(track[i])
		i++;
	while(i > 0 && track[i] != '/')
		i--;
	if (i > 0 && i < ft_strlen(track))
		return (ft_strncpy(track, i));
	else
		return (track);
	
}