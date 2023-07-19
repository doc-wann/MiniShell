/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:32:11 by mumontei          #+#    #+#             */
/*   Updated: 2023/07/19 12:32:12 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Function to ht_insert a key-value pair into the hashtable
void	ht_insert(t_hashtable *ht, const char *key, int value)
{
	unsigned int	index;
	t_hashnode		*new_node;

	index = hash(key);
	new_node = (t_hashnode *)malloc(sizeof(t_hashnode));
	new_node->key = strdup(key);
	new_node->value = value;
	new_node->next = NULL;

	if (ht->table[index] == NULL)
		ht->table[index] = new_node;
	else
	{
		new_node->next = ht->table[index];
		ht->table[index] = new_node;
	}
}