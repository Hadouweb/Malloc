#include "../includes/malloc.h"

int		main(void)
{
	char *ptr = malloc(100);
	strcpy(ptr, "Bonjour");
	show_ptr_bit(ptr, 10);

	int *ptr2 = malloc(10000);
	ptr2[0] = 42;
	show_ptr_bit(ptr2, 10);

	uint64_t *ptr3 = malloc(100000);
	ptr3[0] = 'a';
	show_ptr_bit(ptr3, 10);

	return (0);
}