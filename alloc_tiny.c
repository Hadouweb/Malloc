#include "malloc.h"

t_tiny_region		*load_tiny_region(void) {
	t_tiny_region	*tiny_region;

	tiny_region = alloc_tiny_region();
	list_push_back(&g_manager.tiny_list, &tiny_region->link);
	return tiny_region;
}

t_tiny_region		*alloc_tiny_region(void) {
	t_tiny_region	*tiny_region;

	tiny_region = mmap(0, PAD_GOAL(sizeof(t_tiny_region)),
					   PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	if (tiny_region == MAP_FAILED)
		error_exit("can't allocate region MAP_FAILED\n");
	ft_bzero(tiny_region->info_block, sizeof(tiny_region->info_block));
	tiny_region->current_index = 0;
	tiny_region->nb_used = 0;
	return tiny_region;
}