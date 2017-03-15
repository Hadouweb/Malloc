#include "../includes/malloc.h"
#include <stdio.h>

# define N 100000


int		main(void)
{
	int i = 0;
	char *ptr[N];

	while (i < N)
	{
		ptr[i] = malloc(2000);
		ptr[i][0] = 'a';
		i++;
	}
	i = 0;
	printf("Number region small after 100000 * 2000 malloc: %zu\n", get_size_region(SMALL));

	while (i < N)
	{
		free(ptr[i]);
		i++;
	}
	printf("Number region small after free all: %zu\n", get_size_region(SMALL));

	i = 0;
	while (i < N)
	{
		ptr[i] = malloc(2000);
		ptr[i][0] = 'a';
		i++;
	}
	printf("Number region small after 100000 * 2000 malloc: %zu\n", get_size_region(SMALL));

	i = 0;
	while (i < N)
	{
		free(ptr[i]);
		i++;
	}
	printf("Number region small after free all: %zu\n", get_size_region(SMALL));
	return (0);
}