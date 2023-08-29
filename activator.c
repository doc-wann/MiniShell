
#include "./includes/minishell.h" 

int activator(char **array, char *read, char **env)
{
	{
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
		else if (ft_strncmp(read, "exit  ", 4) == 0)
		{
			ft_exit();
		}
		else
			printf("%s: the command is not recognized\n", read);
		return (0);
	}
}

char *messagestart(char **envs)
{
	return ft_strjoin(ft_strjoin(get_env(envs, "$USER"), "@"),ft_substr(ft_strjoin(ft_strjoin(getcwd(NULL, 400), "$ "), " "), 1, 1 +  ft_strlen(getcwd(NULL, 400))));
}