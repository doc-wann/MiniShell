/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:06:14 by mumontei          #+#    #+#             */
/*   Updated: 2023/08/02 17:34:08 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_hashnode	*ht_search(t_hashtable *ht, char *key)
{
	int			index;

	if (!key)
		return (0);
	index = hash(key);
	if (!ht->table[index])
		return (NULL);
	while (ft_strcmp(ht->table[index]->key, key) != 0 && \
		ht->table[index]->next != NULL)
		ht->table[index] = ht->table[index]->next;
	if (ft_strcmp(ht->table[index]->key, key) == 0)
		return (ht->table[index]);
	return (NULL);
}