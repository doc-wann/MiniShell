/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:19:37 by mmuriloj          #+#    #+#             */
/*   Updated: 2023/07/17 18:04:23 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(char **args, char **envs)
{
	char *homepath;

	homepath = get_env(args, *envs);
	if(args[0] == ft_strdup("cd"))
	{
		if(!args[1])
			chdir(homepath);
		else if (args[1])
		{
			if(chdir(ft_strjoin(homepath, path_parser(args[1]))) != 0)
				write(2, ft_strjoin("cd: no such file or directory: ", args[1]), 31 + ft_strlen(args[1]));
		}
	}
	else
		return ;
}