#include "./includes/minishell.h" 

char ***list_parser_pipe(char **array)
{
	int	i;
	int	splits_q;
	int q;
	char ***megalist;
	
	i = 0;
	q = 0;
	splits_q = 0;
	while(array[i])
	{
		if(ft_strncmp(array[i], "|", 1) == 0)
			splits_q++;
		i++;
	}
	printf("step2");
	megalist = calloc(splits_q, sizeof(char **));
	i = 0;
	splits_q = 0;
	printf("step3");
	while(array[i])
	{
		if(ft_strncmp(array[i], "|", 1) == 0)
		{
			q = 0;
			splits_q++;
		}
		printf("\nmegalist[%i][%i] = array[%i]\n",splits_q,q,i);
		// megalist[splits_q][q] = array[i];
		q++;
		i++;
	}
	printf("step1");
	return(megalist);
}