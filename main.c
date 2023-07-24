#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "./includes/minishell.h" 

int main(int ac, char **av, char **env)
{
	char *read;
	char **array;

	ft_started();
	while(1)
	{
		read = readline("$");
		array = ft_split(read, ' ');
		if (get_env(env, read) != 0)
		{
			if (get_env(env,read) != NULL)
				write(1, ft_strjoin(get_env(env,read), "\n"), ft_strlen(get_env(env,read)) + 1);
			else
				write(1, "PATH NOT FOUND\n", 15);
		}
		else if (ft_strncmp(read, "echo  ", 4) == 0)
		{
			ft_echo(array);
		}
		else if (ft_strncmp(read, "pwd  ", 3) == 0)
		{
			ft_pwd();
		}
		else if (ft_strncmp(read, "cd  ", 2) == 0)
		{
			ft_cd(array, env);
		}
		else
			printf("%s: the command is not recognized\n", read);
	}
}