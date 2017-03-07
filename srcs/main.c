#include "malloc.h"

int		main(void) {
	t_tiny_region 	*p1;

	p1 = mmap(0, 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	printf("sizeof t_tiny_region: %lu\n", sizeof(t_tiny_region));
	printf("sizeof t_small_region: %lu\n", sizeof(t_small_region));
	printf("sizeof t_tiny_block: %lu\n", sizeof(t_tiny_block));
	printf("sizeof t_small_block: %lu\n", sizeof(t_small_block));
	printf("sizeof t_block: %lu\n\n", sizeof(t_block));
	//printf("sizeof pad tiny: %lu\n", PAD_TINY);
	printf("sizeof PAD_TINY: %d\n", PAD_TINY);
	printf("sizeof PAD_SMALL: %d\n", PAD_SMALL);
	t_block t;

	t.used = 1;
	t.size = 16;
	t.index = 256;

	printf("size: %d\n", t.size);
	printf("index: %d\n", t.index);

	malloc(1);

	return 0;
}
