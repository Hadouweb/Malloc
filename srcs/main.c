#include "malloc.h"


int		main(void) {
	char *ptr;

	ptr = (char*)malloc(3);
	//ptr = mmap(0, 4, PROT_READ | PROT_WRITE, MAP_ANONYMOUS, -1, 0);

	ptr = "lol";
	//printf("%p\n", ptr);

	ft_bit_dump(ptr, 8);

	return 0;
}