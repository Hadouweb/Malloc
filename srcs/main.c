#include "malloc.h"


int		main(void) {
	void *ptr;

	ptr = mmap(0, 10, PROT_READ | PROT_WRITE, MAP_ANONYMOUS, -1, 0);

	ptr = "lol";
	printf("%p\n", ptr);

	int	tab[10] = {0, 23, 150, 255,
			12, 16,  21, 42};

	print_memory(tab, sizeof(tab));

	return 0;
}