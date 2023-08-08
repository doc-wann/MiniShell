#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "./includes/minishell.h" 

#include <signal.h>

void sig_handler(int);


int main(int ac, char **av, char **env)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);

	char *read;
	int i;
	char **array;
	int argcount;

	ft_started();
	i = 0;
	while(1)
	{
		read = readline("\n$");
		if (read == 0)
		{
			ft_exit();
		}
		else
		{
		
			array = ft_split(read, ' ');

			argcount = ft_lstlen(array);

			// printf("this is the argcount %i\n", argcount);

			// list_parser_pipe(array);
			activator(array, read, env);
		}
	}
}

void sig_handler(int signum)
{
	if (signum > 55)
	{
		return;
	}
	else
	{
		sig_handler(signum + 55);
		write(1,"\b\b\033[K", 6);
	}

	if (signum == SIGINT)
	{
		write(1, "\n$", 2);
	}


	return ;
}