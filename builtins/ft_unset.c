/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:45:15 by mumontei          #+#    #+#             */
/*   Updated: 2023/08/09 11:36:23 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	unset(char **envs)
{
	int		i;
	char	*key;
	
	key = NULL;
	g_minishell.exit_code = 0;
	i = -1;
	while (envs[++i])
	{
		key =  get_key(envs[i]);
		if (ht_search(g_minishell.env, key) != NULL)
			 ht_delete(g_minishell.env, key);
		if (ht_search(g_minishell.local, key) != NULL)
			ht_delete(g_minishell.env, key);
		free(key);
	}

	return (g_minishell.exit_code);
}