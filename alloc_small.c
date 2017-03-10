#include "malloc.h"

t_small_region		*load_small_region(void) {
	t_small_region	*small_region;

	small_region = alloc_small_region();
	if (small_region == MAP_FAILED)
		error_exit("can't allocate region MAP_FAILED\n");

	list_push_back(&g_manager.small_list, &small_region->link);
	return small_region;
}

t_small_region		*alloc_small_region(void) {
	t_small_region	*small_region;

	small_region = mmap(0, PAD_GOAL(sizeof(t_small_region)),
						PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	if (small_region != MAP_FAILED) {
		ft_bzero(small_region->info_block, sizeof(small_region->info_block));
		//small_region->header_prot = MAGIC_PROT;
		small_region->current_index = 0;
		small_region->nb_used = 0;
	}
	return small_region;
}