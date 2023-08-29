#include "../libft/libft.h"
#include <stdio.h>

# define FALSE 0
# define TRUE 1

# define ERROR 0
# define SUCCESS 1

char	***list_parser_pipe(char **array);
int 	activator(char **array, char *read, char **env);
void	ft_exit(void);
char 	*get_env(char **envs, char *search);
int		ft_echo(char **args);
int		ft_pwd(void);
void 	ft_started(void);
void	ft_cd(char **args, char **envs);
char	*path_parser(char *path);
char 	*ft_backtrack(char *track);

char *messagestart(char **env);