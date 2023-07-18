#ifndef MINISHELL_H
# define MINISHELL_H
# define FALSE 0
# define TRUE 1
# define ERROR 0
# define SUCCESS 1

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>


void	ft_cd(char *dir, char **env);
int		ft_env(char **envp);
char	*get_env(char **envs, char *search);
int		ft_echo(char **args);
int		ft_pwd(void);
void	put_endl(char *str, int fd);

#endif