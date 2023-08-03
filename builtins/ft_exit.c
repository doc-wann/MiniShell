/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:20:48 by mumontei          #+#    #+#             */
/*   Updated: 2023/08/03 07:55:13 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i > 2)
	{
		error_msg("exit: ", "too many arguments\n", 1);
		return ;
	}
	ht_clear(g_minishell.env);
	free(g_minishell.env);
	if (g_minishell.local)
		ht_clear(g_minishell.local);
	write(1, "exit\n", 5);
	exit(g_minishell.exit_code);
}
