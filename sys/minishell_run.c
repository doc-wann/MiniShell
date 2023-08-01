/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:34:16 by mumontei          #+#    #+#             */
/*   Updated: 2023/08/01 15:04:58 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(void)
{
	char		*read;
	char		**array;
	int			len;
	char		*str;
	char		prompt;

	while (1)
	{
		prompt = ft_strjoin (getcwd(prompt, 1024), " $ ");
		read = readline(prompt);
		array = ft_split(read, ' ');
		if (ft_strncmp(read, "echo", 4) == 0)
			ft_echo(array);
		else if (ft_strncmp(read, "env", 3) == 0)
			ht_print(g_minishell.env);
		else if (ft_strncmp(read, "pwd", 3) == 0)
			ft_pwd();
		else if (ft_strncmp(read, "cd", 2) == 0)
			ft_cd(array[1]);
		else if (get_env(env, read) != 0)
		{
			str = ft_strjoin(get_env(env, read), "\n");
			len = ft_strlen(get_env(env, read)) + 1;
			write(1, str, len);
			free(str);
		}
		else
			printf("%s: command not found\n", array[0]);
		free(read);
		for (int j = 0; array[j]; j++)
			free (array[j]);
		free(array);
	}
}