/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:06:14 by mumontei          #+#    #+#             */
/*   Updated: 2023/08/01 10:21:01 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_hashnode	*ht_search(char *key)
{
	int			index;

	if (!key)
		return (0);
	index = hash(key);
	if (!g_minishell.env->table[index])
		return (NULL);
	while (ft_strcmp(g_minishell.env->table[index]->key, key) != 0 && \
		g_minishell.env->table[index]->next != NULL)
		g_minishell.env->table[index] = g_minishell.env->table[index]->next;
	if (ft_strcmp(g_minishell.env->table[index]->key, key) == 0)
		return (g_minishell.env->table[index]);
	return (NULL);
}