#include "malloc.h"

int		main(void) {
	//char *ptr;
	//char *ptr2;
	int *ptr3;

	//ptr = mmap(0, 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	//ptr2 = mmap(0, 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	ptr3 = malloc(1);

	/*ptr[0] = 'f';
	ptr[1] = 'g';
	ptr[2] = 'h';
	ptr[3] = 'i';
	ptr[4] = 'j';


	ptr2[0] = 'a';
	ptr2[1] = 'b';
	ptr2[2] = 'c';
	ptr2[3] = 'd';
	ptr2[4] = 'e';*/

	ptr3[0] = 'k';
	ptr3[1] = 'l';
	ptr3[2] = 'm';
	ptr3[3] = 'n';
	ptr3[4] = 'o';


	int i = 0;
	while (i < 1) {
		ptr3[i] = i;
		i++;
	}


	//ft_bit_dump(ptr, 20);
	//ft_bit_dump(ptr2, 20);
	ft_bit_dump(ptr3, 20);

	//printf("%ld\n", ptr - ptr);

	//printf("%p\n", ptr);
	//printf("%p\n", ptr2);
	printf("%p\n", ptr3);
	ft_print_addr(ptr3);
	return 0;
}