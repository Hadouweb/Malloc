#include "../includes/malloc.h"

int		main(void)
{
	char	*addr1;

	addr1 = (char*)malloc(32);
	printf("addr = %p\n", addr1);
	addr1 = (char*)realloc(addr1, 64);
	printf("after realloc \naddr = %p\n", addr1);
	show_alloc_mem();
	return (0);
}