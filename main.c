#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "./includes/minishell.h" 

int main(int ac, char **av, char **env)
{
	char *read;
	char **array;
	int argcount;

	ft_started();
	while(1)
	{
		read = readline("\n$");
		
		array = ft_split(read, ' ');

		argcount = ft_lstlen(array);

		// printf("this is the argcount %i\n", argcount);

		// list_parser_pipe(array);
		activator(array, read, env);
	}
}