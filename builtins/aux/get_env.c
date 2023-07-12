#include "../../includes/minishell.h"

char *get_env(char **envs, char *search)
{
	int i;
	char *env;

	i = 0;
	search++;
	search = ft_strjoin(search, "=");
	while(envs[i])
	{
		if(ft_strncmp(envs[i], search, ft_strlen(search)) == 0)
		{
			env = envs[i] + ft_strlen(search) + 1;
			break ;
		}
		else
			i++;
	}
	if(env)
		return(env);
	else
		return (0);

}