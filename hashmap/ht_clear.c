/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:32:20 by mumontei          #+#    #+#             */
/*   Updated: 2023/07/20 12:58:30 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Function to clear the hashtable and free allocated memory
void	ht_clear(t_hashtable *ht)
{
	int			i;
	t_hashnode	*current;
	t_hashnode	*temp;

	current = NULL;
	temp = NULL;
	i = 0;
	while (i < TABLE_SIZE)
	{
		current = ht->table[i];
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			free(temp->key);
			free(temp);
		}
		ht->table[i] = NULL;
		i++;
	}
}
