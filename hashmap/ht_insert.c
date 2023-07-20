/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:32:11 by mumontei          #+#    #+#             */
/*   Updated: 2023/07/20 12:58:09 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Function to ht_insert a key-value pair into the hashtable
void	ht_insert(t_hashtable *ht, const char *key, char *value)
{
	unsigned int	index;
	t_hashnode		*new_node;

	index = hash(key);
	new_node = (t_hashnode *)malloc(sizeof(t_hashnode));
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;
	if (ht->table[index] == NULL)
		ht->table[index] = new_node;
	else
	{
		new_node->next = ht->table[index];
		ht->table[index] = new_node;
	}
}

static void	free_kv(char **kv)
{
	int	i;

	i = 0;
	while (kv[i])
		free(kv[i++]);
	free(kv);
}

void	envars_to_hashtable(char **env, t_hashtable *ht)
{
	int		i;
	char	**kv;
	char	*str;

	i = 0;
	str = NULL;
	while (i < TABLE_SIZE)
	{
		if (!env[i])
			break ;
		str = get_env(env, env[i]);
		kv = ft_split(env[i], '=');
		ht_insert(ht, kv[0], str);
		free_kv(kv);
		i++;
	}
}
