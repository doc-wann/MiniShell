#include "../libft/libft.h"
#include <stdio.h>

# define FALSE 0
# define TRUE 1

# define ERROR 0
# define SUCCESS 1


char 	*get_env(char **envs, char *search);
int		ft_echo(char **args);
int		ft_pwd(void);
void	ft_cd(char **args, char **envs);
char	*path_parser(char *path);