/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_without_arguments.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:41:49 by mumontei          #+#    #+#             */
/*   Updated: 2023/08/08 16:35:08 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	insertion_sort(char **arr, int size)
{
	int		i;
	int		j;
	char	*key;

	i = 0;
	while (++i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && ft_strcmp(arr[j], key) > 0)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

static int	count_vars(t_hashtable *dict)
{
	int			i;
	int			len;
	t_hashnode	*current;

	len = 0;
	i = -1;
	while (++i < TABLE_SIZE)
	{
		if (dict->table[i] != NULL)
		{
			current = dict->table[i];
			len++;
			while (current->next != NULL)
			{
				current = current->next;
				len++;
			}
		}
	}
	return (len);
}

static char	*joint_with_quotes(t_hashnode *node)
{
	char	*str;
	char	*key;
	char	*value;
	
	key = ft_strjoin(node->key, "=\"");
	value = ft_strjoin(node->value, "\"");
	str = ft_strjoin(key, value);
	free(key);
	free(value);
	return (str);
}

char	**hashmap_to_2darray(t_hashtable *dict)
{
	char		**list;
	int			i;
	int			j;
	int			len;
	t_hashnode	*current;

	len = count_vars(dict);
	list = (char **)ft_calloc(len, sizeof(char *));
	j = 0;
	i = -1;
	while (++i < TABLE_SIZE && j < len)
	{
		if (dict->table[i] != NULL)
		{
			current = dict->table[i];
			list[j] = joint_with_quotes(current);
			while (current->next != NULL)
			{
				current = current->next;
				list[++j] = joint_with_quotes(current);
			}
			j++;
		}
	}
	return (list);
}

void	export_without_args(void)
{
	char	**arr;
	int		i;
	int		num_envs;
	
	i = -1;
	num_envs = count_vars(g_minishell.env);
	arr = hashmap_to_2darray(g_minishell.env);
	insertion_sort(arr, num_envs);
	while(++i < num_envs)
	{
		// if (ft_strncmp(arr[i], "OLWPWD=", 7) && ft_strncmp(arr[i], "_=", 2))
		if (ft_strncmp(arr[i], "_=", 2))
			printf("declare -x %s\n", arr[i]);
	}
}