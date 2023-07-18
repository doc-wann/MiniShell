#include "../../includes/minishell.h"

char	*path_parser(char *path)
{
	int i;

	i = 0;
	while(!ft_isalnum(path[0]))
		path++;
	path = ft_strjoin("/",path);
	return(path);
}