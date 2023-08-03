/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:19:25 by mumontei          #+#    #+#             */
/*   Updated: 2023/08/03 08:13:44 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	export_local_var(char **cmd, int index)
{
	char	*value;

	if (ht_search(g_minishell.local, cmd[index]) == NULL)
		return ;
	if (ht_search(g_minishell.env, cmd[index]))
		ht_delete(g_minishell.env, cmd[index]);
	ht_insert(g_minishell.env, cmd[index], \
				ht_search(g_minishell.local, cmd[index])->value);
}

void	declare_and_assign(char **cmd, int index)
{
	if (ht_search(g_minishell.env, get_key(cmd[index])))
		ht_delete(g_minishell.env, get_key(cmd[index]));
	ht_insert(g_minishell.env, get_key(cmd[index]), get_value(cmd[index]));
}

int	export_var(char **command, int index)
{
	if (!command[index])
		return (0);
	if (ft_strchr(command[index], '='))
		declare_and_assign(command, index);
	else
		export_local_var(command, index);
	return (export_var(command, index + 1));

}

int	ft_export(char **command)
{
	g_minishell.exit_code = 0;
	if (command[0])
		return (export_var(command, 0));
	else
		ft_exit(command);
}