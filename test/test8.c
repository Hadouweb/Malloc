#include "../includes/malloc.h"

int		main(void)
{
	int i = 0;
	while (i < 1024 * 1024)
	{
		char *ptr = malloc(1024 * 1024);
		ptr[0] = 'a';
		i++;
	}
	return (0);
}