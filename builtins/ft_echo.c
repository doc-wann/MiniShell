/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:20:51 by mmuriloj          #+#    #+#             */
/*   Updated: 2023/07/12 16:53:05 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	count_args(char **args)
{
	int		count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

int	ft_echo(char **args)
{
	int		i;
	int		n_flag;

	i = 1;
	n_flag = FALSE;
	if (count_args(args) > 1)
	{
		while (args[i] && ft_strncmp(args[i], "-n", ft_strlen(args[i])) == 0)
		{
			n_flag = TRUE;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n_flag == FALSE)
		write(1, "\n", 1);
	return (0);
}

// int	main(int argc, char *args[])
// {
// 	ft_echo(args);
// 	return (0);
// }
