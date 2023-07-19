/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:00:40 by mumontei          #+#    #+#             */
/*   Updated: 2023/07/19 13:47:42 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h" 

int	main(int ac, char **av, char **env)
{
	t_hashtable	*ht;
	char		*read;
	char		**array;
	int			len;
	char		*str;

	ht = ht_create();
	ht_insert(ht, "apple", 5);
	ht_insert(ht, "banana", 10);
	ht_insert(ht, "orange", 8);
	ht_insert(ht, "grape", 15);

	ht_print(ht);

	ht_delete(ht, "banana");

	printf("\nAfter deleting 'banana':\n");
	ht_print(ht);

	ht_clear(ht);
	free(ht);

	return (0);

	while (1)
	{
		read = readline("$ ");
		array = ft_split(read, ' ');
		if (get_env(env, read) != 0)
		{
			str = ft_strjoin(get_env(env, read), "\n");
			len = ft_strlen(get_env(env, read)) + 1;
			write(1, str, len);
			free(str);
		}
		else if (ft_strncmp(read, "echo  ", 4) == 0)
			ft_echo(array);
		else if (ft_strncmp(read, "pwd  ", 3) == 0)
			ft_pwd();
		else if (ft_strncmp(read, "cd", 2) == 0)
			ft_cd("/home/Desktop", env);
		else
			write(1, "$ Error, the command is not recognized\n", 39);
	}
}