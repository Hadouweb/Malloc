#include "malloc.h"
#include <execinfo.h>

typedef uint32_t t_tiny_block[4];

#define NUM_TINY_BLOCKS	254
#define SMALL_REGION_SIZE 4096
#define PAD (SMALL_REGION_SIZE - (NUM_TINY_BLOCKS * sizeof(t_tiny_block) + sizeof(t_block)))

typedef struct 		s_block {
	t_link			link;
	unsigned int 	used:1;
	unsigned int 	size:5;
	unsigned int	index:9;
}					t_block;

typedef struct 		s_tiny_region {
	t_tiny_block 	data[NUM_TINY_BLOCKS];
	t_block			head_block;
	uint8_t 		pad[PAD];
}					t_tiny_region;

int		main(void) {
	t_tiny_region 	*p1;

	p1 = mmap(0, 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	printf("sizeof t_tiny_region: %lu\n", sizeof(t_tiny_region));
	printf("sizeof t_tiny_block: %lu\n", sizeof(t_tiny_block));
	printf("sizeof t_block: %lu\n", sizeof(t_block));

	t_block t;

	t.used = 1;
	t.size = 16;
	t.index = 256;



	printf("used: %lu\n", PAD);
	printf("size: %d\n", t.size);
	printf("index: %d\n", t.index);

	return 0;
}
