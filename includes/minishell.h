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

//hashmap
# define TABLE_SIZE 100
# include <stdlib.h>
# include <string.h>

// hashnode structure for chaining
typedef struct s_hashnode
{
	char				*key;
	int					value;
	struct s_hashnode	*next;
}	t_hashnode;

// Hashtable structure
typedef struct s_hashtable
{
	t_hashnode	*table[TABLE_SIZE];
}	t_hashtable;

t_hashtable		*ht_create(void);
unsigned int	hash(const char *key);
void			ht_clear(t_hashtable *ht);
void			ht_print(const t_hashtable *ht);
void			ht_delete(t_hashtable *ht, const char *key);
void			ht_insert(t_hashtable *ht, const char *key, int value);

void			ft_cd(char *dir, char **env);
int				ft_env(char **envp);
char			*get_env(char **envs, char *search);
int				ft_echo(char **args);
int				ft_pwd(void);
void			put_endl(char *str, int fd);

#endif