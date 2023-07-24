#include "../../includes/minishell.h"

char *get_env(char **envs, char *search)
{
	int i;
	char *env;

	env = NULL;
	i = 0;
	if (ft_strlen(search) < 2)
		return (NULL);
	if (ft_strncmp(search, "$ ", 1) == 0)
		search++;
	else
		return (NULL);
	if (search[0] >= 65 && search[0] <= 90)
	{}
	else
		return (NULL);
	search = ft_strjoin(search, "=");
	while(i < ft_lstlen(envs))
	{
		if(ft_strncmp(envs[i], search, ft_strlen(search)) == 0)
		{
			env = envs[i];
			break ;
		}
		else
		{
			i++;
		}
	}
	if (env)
	{
		return(env + ft_strlen(search) + 1);
	}
	else
	{
		return(NULL);
	}
}
