#include "malloc.h"

void				preload_region(void) {
	t_tiny_region	*tiny_region;
	t_small_region	*small_region;

	tiny_region = alloc_tiny_region();
	if (tiny_region == MAP_FAILED)
		error_exit("can't allocate region MAP_FAILED\n");
	small_region = alloc_small_region();
	if (small_region == MAP_FAILED)
		error_exit("can't allocate region MAP_FAILED\n");

	list_push_back(&g_manager.tiny_list, &tiny_region->link);
	list_push_back(&g_manager.small_list, &small_region->link);
}

t_tiny_region		*alloc_tiny_region(void) {
	t_tiny_region	*tiny_region;

	tiny_region = mmap(0, PAD_GOAL(sizeof(t_tiny_region)),
	PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	if (tiny_region != MAP_FAILED) {
		ft_bzero(tiny_region->info_block, sizeof(tiny_region->info_block));
		//tiny_region->header_prot = MAGIC_PROT;
		tiny_region->current_index = 0;
		tiny_region->nb_used = 0;
	}
	return tiny_region;
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

t_large_block		*alloc_large_block(size_t size) {
	t_large_block	*large_block;

	large_block = mmap(0, PAD_GOAL(size + SIZE_LARGE_BLOCK),
	PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	if (large_block->data != MAP_FAILED) {
		large_block->used = 1;
		large_block->size = size;
		large_block->data = (void*)large_block + SIZE_LARGE_BLOCK;
	}
	return large_block;
}