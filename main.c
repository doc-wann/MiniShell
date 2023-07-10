#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void)
{
	char *read;

	while(1)
	{
		write(1, "$", 1);
		if(read)
			write(1, "$Error, the command is not recognized\n", 38);
	}
}