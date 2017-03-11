#include "../includes/malloc.h"
#include <pthread.h>

void	*func(void *ptr);

int		main(void)
{
	pthread_t t;

	pthread_create(&t, NULL, func, NULL);
	int i = 10;
	while (i--)
	{
		usleep(10000);
		char *ptr = malloc(1);
		ptr = realloc(ptr, 100);
		ptr[0] = 'a';
		show_alloc_mem();
	}
	pthread_join(t, NULL);
	show_alloc_mem();
}

void	*func(void *p)
{
	if (p)
		;
	char *ptr[10];
	int i = 10;
	while (i--)
	{
		usleep(20000);
		ptr[i] = malloc(2);
		ptr[i] = realloc(ptr[i], 2000);
		ptr[i][0] = 'a';
	}
	i = 10;
	while (i--)
	{
		free(ptr[i]);
	}

	return NULL;
}