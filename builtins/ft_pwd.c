/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:06:06 by mumontei          #+#    #+#             */
/*   Updated: 2023/07/17 18:41:48 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	put_endl(char *str, int fd)
{
	if (!str || fd < 0)
		return ;
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}

int	ft_pwd(void)
{
	char	*buf;
	char	*cwd;

	cwd = NULL;
	buf = NULL;
	cwd = getcwd(buf, 100);
	if (cwd)
	{
		put_endl(cwd, 1);
		free(buf);
		free(cwd);
		return (SUCCESS);
	}
	return (ERROR);
}
