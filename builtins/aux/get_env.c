/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:12:36 by mumontei          #+#    #+#             */
/*   Updated: 2023/07/20 11:43:10 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_exists(char **vars, char *search)
{
	int	i;

	i = 0;
	//search++;
	while (vars[i])
	{
		if (ft_strncmp(vars[i], search, ft_strlen(search)) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static char	*get_value(char *envar)
{
	char	*ptr;
	int		i;

	i = -1;
	if (!envar)
		return (0);
	ptr = envar;
	while (envar[++i])
	{
		if (envar[i] == '=')
		{
			i++;
			ptr = (char *)&envar[i];
			return (ptr);
		}
	}
	return (ptr);
}

static char	*get_key(char *envar)
{
	int		i;
	int		key_length;
	char	*key;

	key = NULL;
	if (!envar)
		return (0);
	key_length = 0;
	i = -1;
	while (envar[++i] != '=')
		key_length++;
	key = (char *)malloc(sizeof(char) * key_length + 1);
	i = -1;
	while(++i < key_length)
		key[i] = envar[i];
	key[i] = '\0';
	return (key);
}

char	*get_env(char **envs, char *search)
{
	int		i;
	char	*env;
	char	*value;

	i = 0;
	value = NULL;
	if (!search || !env_exists(envs, search))
		return (NULL);
	//search++;
	//search = ft_strjoin(search, "=");
	while (envs[i])
	{
		if (ft_strncmp(envs[i], search, ft_strlen(search) - 1) == 0)
		{
			value = get_value(search);
			env = get_key(search);
			//free(search);
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