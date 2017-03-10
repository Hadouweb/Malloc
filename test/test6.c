#include "../malloc.h"

int		main(void)
{
	char	*addr1;
	char	*addr2;
	char	*addr3;
	char	*addr4;

	addr1 = (char*)malloc(32);
	addr2 = (char*)malloc(32);
	addr3 = (char*)malloc(32);
	show_alloc_mem();
	free(addr1);
	free(addr2);
	addr4 = (char*)malloc(64);
	show_alloc_mem();
	return (0);
}