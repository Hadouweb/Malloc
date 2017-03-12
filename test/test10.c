#include "../includes/malloc.h"

int		main(void)
{
	char *ptr = malloc(10000);
	strcpy(ptr, "Bonjour ex");
	show_alloc_mem_ex();

	return (0);
}