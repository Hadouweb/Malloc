#include "../includes/malloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#define M1 (1024 * 1024)

int		main(void) {
	/*t_tiny_region 	*p1;
	t_small_region	*p2;

	p1 = mmap(0, 4000, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	printf("sizeof t_tiny_region: %lu\n", PAD_GOAL(sizeof(t_tiny_region)));
	printf("sizeof t_small_region: %lu\n", PAD_GOAL(sizeof(t_small_region)));
	printf("sizeof t_tiny_block: %lu\n", sizeof(t_tiny_block));
	printf("sizeof t_small_block: %lu\n", sizeof(t_small_block));
	printf("sizeof t_block: %lu\n", sizeof(t_block));
	printf("sizeof info_block: %lu\n", sizeof(p1->info_block));
	printf("sizeof data tiny: %lu\n", sizeof(p1->data));
	printf("sizeof data small: %lu\n", sizeof(p2->data));
	printf("sizeof PAGE SIZE: %d\n", PAGE_SIZE);
	printf("sizeof pad tiny: %lu\n", PAD_TINY);
	printf("sizeof pad small: %lu\n\n", PAD_SMALL);
	printf("sizeof data tiny: %lu\n\n", sizeof(p1->data));

	printf("RUN\n");*/

	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		i++;
	}
	show_alloc_mem();
	return (0);

	return 0;
}
