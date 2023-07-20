/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:32:17 by mumontei          #+#    #+#             */
/*   Updated: 2023/07/20 12:57:20 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Hash function
unsigned int	hash(const char *key)
{
	int				i;
	unsigned int	hashval;

	hashval = 0;
	i = 0;
	while (key[i] != '\0')
	{
		hashval = key[i] + 31 * hashval;
		i++;
	}
	return (hashval % TABLE_SIZE);
}
