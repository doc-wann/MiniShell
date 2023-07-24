/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:43:21 by mumontei          #+#    #+#             */
/*   Updated: 2023/06/23 11:35:00 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_env(char **envp)
{
	int	i;

	i = -1;
	//if (args && args[1])
	//	exit(ERROR);
	while (envp[++i])
		put_endl(envp[i], STDOUT_FILENO);
	return (SUCCESS);
}