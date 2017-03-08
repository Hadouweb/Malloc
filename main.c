#include "malloc.h"
#include <stdio.h>

int		main(void) {
	/*t_tiny_region 	*p1;

	p1 = mmap(0, 1290248, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	printf("sizeof t_tiny_region: %lu\n", sizeof(t_tiny_region));
	printf("sizeof t_small_region: %lu\n", sizeof(t_small_region));
	printf("sizeof t_tiny_block: %lu\n", sizeof(t_tiny_block));
	printf("sizeof t_small_block: %lu\n", sizeof(t_small_block));
	printf("sizeof t_block: %lu\n", sizeof(t_block));
	printf("sizeof info_block: %lu\n", sizeof(p1->info_block));
	printf("sizeof data: %lu\n\n", sizeof(p1->data));
	//printf("sizeof pad tiny: %lu\n", PAD_TINY);



	printf("sizeof S_TOKEN: %lu\n", S_TOKEN);
	printf("sizeof PAD_REG_TINY: %d\n", PAD_REG_TINY);
	printf("sizeof PAD_GOAL: %d\n", PAD_GOAL(PAD_REG_TINY));
	printf("sizeof PAD_TINY: %d\n", PAD_TINY);
	printf("sizeof PAD_SMALL: %d\n", PAD_SMALL);*/


	printf("RUN\n");
	malloc(1);

	//show_alloc_mem();

	return 0;
}
