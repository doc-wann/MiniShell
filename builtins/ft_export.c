/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:19:25 by mumontei          #+#    #+#             */
/*   Updated: 2023/08/01 15:18:10 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	declare_var(char **cmd, int index)
{
	if(ht_search(get_key(cmd[index])))
		ht_delete(g_minishell.env, get_key(cmd[index]));
	ht_insert(g_minishell.env, get_key(cmd[index]), get_value(cmd[index]));
}

int	export_var(char **command, int index)
{
	if (!command[index])
		return (0);
	if (ft_strchr(command[index], '='))
		declare_var(command, index);
	else
		exit(0);
	return (export_var(command, index + 1));

}

int	ft_export(char **command)
{
	g_minishell.exit_code = 0;
	if (command[1])
		return (export_var(command, 1));
	else
		ft_exit(command);
}