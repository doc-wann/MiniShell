/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:35:42 by mumontei          #+#    #+#             */
/*   Updated: 2023/08/01 10:58:44 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_msg(char *command, char*msg, int status_code)
{
	char	*output;

	write(1, "minishell: ", 11);
	output = ft_strjoin(command, msg);
	write(1, output, ft_strlen(output));
	g_minishell.exit_code = status_code;
	free(output);
}
