/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:19:25 by mumontei          #+#    #+#             */
/*   Updated: 2023/06/22 14:57:40 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*static char	**get_key_value(char *str)
{
	char	**temp;
	char	*equal_pos;

	equal_pos = ft_strchr(str, '=');
	temp = malloc(sizeof * temp * (3));
	temp[0] = ft_substr(str, 0, equal_pos - str);
	temp[1] = ft_substr(equal_pos, 1, ft_strlen(equal_pos));
	temp[2] = NULL;

	int		i;
	i = 0;
	while (temp[i])
		ft_printf("%s\n", temp[i++]);

	return (temp);
}

int	ft_export(char **args)
{
	char	**temp;
	int		i;

	i = 1;
	if (!args[1])
		exit(1); //implementar tratamento
	while (args[i])
	{
		//mplementar teste de validez
		if (ft_strchr(args[i], '=') != NULL)
			temp = get_key_value(args[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(void)
{
	char		**args;
	const char	*s = "export var = 34684";

	args = ft_split(s,' ');
	ft_export(args);
}*/