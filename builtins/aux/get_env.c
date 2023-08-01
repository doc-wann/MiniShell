/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:12:36 by mumontei          #+#    #+#             */
/*   Updated: 2023/08/01 14:24:34 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_exists(char **vars, char *search)
{
	int	i;

	i = 0;
	while (vars[i])
	{
		if (ft_strncmp(vars[i], search, ft_strlen(search)) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*get_value(char *env)
{
	char	*ptr;
	int		i;

	i = -1;
	if (!env)
		return (0);
	ptr = env;
	while (env[++i])
	{
		if (env[i] == '=')
		{
			i++;
			ptr = (char *)&env[i];
			return (ptr);
		}
	}
	return (ptr);
}

char	*get_key(char *env)
{
	int		i;
	int		key_length;
	char	*key;

	key = NULL;
	if (!env)
		return (0);
	key_length = 0;
	i = -1;
	while (env[++i] != '=')
		key_length++;
	key = (char *)malloc(sizeof(char) * key_length + 1);
	i = -1;
	while (++i < key_length)
		key[i] = env[i];
	key[i] = '\0';
	return (key);
}

char	*get_env(char **envs, char *search)
{
	int		i;
	char	*value;

	i = 0;
	value = NULL;
	if (!search || !env_exists(envs, search))
		return (NULL);
	while (envs[i])
	{
		if (ft_strncmp(envs[i], search, ft_strlen(search) - 1) == 0)
		{
			value = get_value(search);
			break ;
		}
		else
			i++;
	}
	if (value)
		return (value);
	else
		return (0);
}