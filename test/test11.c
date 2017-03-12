#include "../includes/malloc.h"

int		main(void)
{
	char *ptr = malloc(100000);
	strcpy(ptr, "Bonjour bit");
	show_alloc_mem_bit();

	return (0);
}