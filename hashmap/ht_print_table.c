/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:32:23 by mumontei          #+#    #+#             */
/*   Updated: 2023/07/19 12:32:24 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Function to print the contents of the hashtable
void	ht_print(const t_hashtable *ht)
{
	int			i;
	t_hashnode	*current;

	current = NULL;
	printf("t_hashtable Contents:\n");
	i = 0;
	while (i < TABLE_SIZE)
	{
		if (ht->table[i] != NULL)
		{
			current = ht->table[i];
			while (current != NULL)
			{
				printf("[%s:\t\t%d] ", current->key, current->value);
				current = current->next;
			}
			printf("\n");
		}
		i++;
	}
}