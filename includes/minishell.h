#ifndef MINISHELL_H
# define MINISHELL_H
# define FALSE 0
# define TRUE 1
# define ERROR 0
# define SUCCESS 1

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

//hashmap
# define TABLE_SIZE 100
# include <stdlib.h>
# include <string.h>


typedef struct s_minishell
{
	struct s_hashtable	*env;
	struct s_hashtable	*local;
	int					exit_code;
}	t_minishell;

// hashnode structure for chaining
typedef struct s_hashnode
{
	char				*key;
	char				*value;
	struct s_hashnode	*next;
}	t_hashnode;

// Hashtable structure
typedef struct s_hashtable
{
	t_hashnode	*table[TABLE_SIZE];
}	t_hashtable;

extern t_minishell	g_minishell;

t_hashtable		*ht_create(void);
unsigned int	hash(const char *key);
t_hashnode		*ht_search(t_hashtable *ht, char *key);
void			ht_clear(t_hashtable *ht);
void			ht_print(const t_hashtable *ht);
void			ht_delete(t_hashtable *ht, const char *key);
void			ht_insert(t_hashtable *ht, const char *key, char *value);
void			envars_to_hashtable(char **env);
void			chdir_path(char *path);
void			ft_cd(char *dir);
int				ft_env(char **envp);
char			*get_env(char **envs, char *search);
int				ft_echo(char **args);
int				ft_pwd(void);
void			put_endl(char *str, int fd);
int				env_exists(char **vars, char *search);
void			error_msg(char *command, char*msg, int status_code);
void			ft_exit(char **args);
char			*get_key(char *env);
char			*get_value(char *env);
void			declare_and_assign(char **cmd, int index);
int				export_var(char **command, int index);
int				ft_export(char **command);
void			minishell(void);
void			export_local_var(char **cmd, int index);
void			export_without_args(void);
char			**hashmap_to_2darray(t_hashtable *dict);
int				unset(char **envs);
#endif