#include "../malloc.h"

#define M1 (1024 * 1024)

int		main(void) {
	/*t_tiny_region 	*p1;
	t_small_region	*p2;

	p1 = mmap(0, 4000, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	printf("sizeof t_tiny_region: %d\n", PAD_GOAL(sizeof(t_tiny_region)));
	printf("sizeof t_small_region: %d\n", PAD_GOAL(sizeof(t_small_region)));
	printf("sizeof t_tiny_block: %lu\n", sizeof(t_tiny_block));
	printf("sizeof t_small_block: %lu\n", sizeof(t_small_block));
	printf("sizeof t_block: %lu\n", sizeof(t_block));
	printf("sizeof info_block: %lu\n", sizeof(p1->info_block));
	printf("sizeof data tiny: %lu\n", sizeof(p1->data));
	printf("sizeof data small: %lu\n", sizeof(p2->data));
	printf("sizeof PAGE SIZE: %d\n", PAGE_SIZE);
	printf("sizeof pad tiny: %d\n", PAD_TINY);
	printf("sizeof pad small: %d\n\n", PAD_SMALL);

	printf("RUN\n");*/

	//printf("%ld\n", 0x106815280 - 0x106721028);
	int i = 0;
	while (i < 10) {
		char *ptr = malloc(33024);
		ptr[1023] = 42;
		//free(ptr);
		//char *ptr2 = malloc(5001);
		//ptr2[5000] = 42;
		i++;
	}
	show_alloc_mem();

	return 0;
}
