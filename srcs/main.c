#include "malloc.h"

int		main(void) {
	t_tiny_region 	*p1;

	p1 = mmap(0, 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	printf("sizeof t_tiny_region: %lu\n", sizeof(t_tiny_region));
	printf("sizeof t_small_region: %lu\n", sizeof(t_small_region));
	printf("sizeof t_tiny_block: %lu\n", sizeof(t_tiny_block));
	printf("sizeof t_small_block: %lu\n", sizeof(t_small_block));
	printf("sizeof t_block: %lu\n", sizeof(t_block));
	printf("sizeof info_block: %lu\n", sizeof(p1->info_block));
	printf("sizeof data: %lu\n\n", sizeof(p1->data));
	//printf("sizeof pad tiny: %lu\n", PAD_TINY);
	printf("sizeof PAD_REG_TINY: %d\n", PAD_REG_TINY);
	printf("sizeof PAD_TINY: %d\n", PAD_TINY);
	printf("sizeof PAD_SMALL: %d\n", PAD_SMALL);



	t_tiny_region t;

	t.current_index = 64510;
	t.nb_used = 64510;

	//printf("current_index: %d\n", t.current_index);
	//printf("nb_used: %d\n", t.nb_used);

	m_malloc(1);

	return 0;
}
