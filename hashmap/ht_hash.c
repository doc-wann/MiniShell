/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:32:17 by mumontei          #+#    #+#             */
/*   Updated: 2023/07/20 21:30:14 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Hash function
unsigned int	hash(const char *key)
{
	int				i;
	unsigned int	hash_value;

	hash_value = 0;
	i = 0;
	while (key && key[i] != '\0')
	{
		//hash_value = key[i] + 31 * hash_value;
		hash_value = ((hash_value << 5) + hash_value) + key[i];
		i++;
	}
	return (hash_value % TABLE_SIZE);
}
