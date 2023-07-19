/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:51:12 by mumontei          #+#    #+#             */
/*   Updated: 2023/07/19 12:41:23 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



// Create and initialize a new hashtable
t_hashtable	*ht_create(void)
{
	t_hashtable	*ht;
	int			i;

	ht = (t_hashtable *)malloc(sizeof(t_hashtable));
	i = 0;
	while (i < TABLE_SIZE)
	{
		ht->table[i] = NULL;
		i++;
	}
	return (ht);
}


