/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:19:25 by mumontei          #+#    #+#             */
/*   Updated: 2023/08/09 11:39:48 by mumontei         ###   ########.fr       */
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
	char	*key;

	key = get_key(cmd[index]);
	if (ht_search(g_minishell.env, key))
		ht_delete(g_minishell.env, key);
	ht_insert(g_minishell.env, key, get_value(cmd[index]));
	free(key);
}

int	export_var(char **args, int index)
{
	if (!args[index])
		return (0);
	if (ft_strchr(args[index], '='))
		declare_and_assign(args, index);
	else
		export_local_var(args, index);
	return (export_var(args, index + 1));

}

int	ft_export(char **args)
{
	g_minishell.exit_code = 0;
	if (args[0])
		return (export_var(args, 0));
	else
		export_without_args();
}