/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:06:14 by mumontei          #+#    #+#             */
/*   Updated: 2023/07/20 21:44:40 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ht_search(char *key)
{
	int			index;
	t_hashnode	*ptr;

	ptr = NULL;
	if (!key)
		return (0);
	index = hash(key);
	ptr = g_minishell.env->table[index];
	if (ft_strcmp(ptr->key, key) == 0)
		return (TRUE);
	while (ptr->key != key && g_minishell.env->table[index]->next != NULL)
		ptr = g_minishell.env->table[index]->next;
	return (FALSE);
}