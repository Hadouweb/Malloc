#include "../includes/malloc.h"

#define M1 (1024 * 1024)

void		print(char *s)
{
	write(1, s, strlen(s));
}

int			main(void)
{
	char	*addr1;
	char	*addr2;
	char	*addr3;

	addr1 = (char *)malloc(16 * M1);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr2 = (char *)malloc(16 * M1);
	addr3 = (char *)realloc(addr1, 128 * M1);
	addr3[127 * M1] = 42;
	print(addr3);
	return (0);
}