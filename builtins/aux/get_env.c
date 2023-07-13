#include "../../includes/minishell.h"

static int	env_exists(char **vars, char *search)
{
	int	i;

	i = 0;
	search++;
	while (vars[i])
	{
		if (ft_strncmp(vars[i], search, ft_strlen(search)) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*get_env(char **envs, char *search)
{
	int		i;
	char	*env;

	i = 0;
	if (!search || !env_exists(envs, search))
		return (NULL);
	search++;
	search = ft_strjoin(search, "=");
	while(envs[i])
	{
		if(ft_strncmp(envs[i], search, ft_strlen(search)) == 0)
		{
			env = envs[i] + ft_strlen(search);
			free(search);
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