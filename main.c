/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:00:40 by mumontei          #+#    #+#             */
/*   Updated: 2023/08/08 16:40:48 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

t_minishell	g_minishell;

int	main(int ac, char **av, char **env)
{
	g_minishell.env = ht_create();
	envars_to_hashtable(env);
	ht_clear(g_minishell.env);
	if (g_minishell.local)
		ht_clear(g_minishell.local);
	return (0);
	// minishell();
}
