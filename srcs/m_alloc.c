#include "malloc.h"

void				preload_region(void) {
	t_tiny_region	*tiny_region;
	t_small_region	*small_region;

	g_manager.index_pool = 0;
	g_manager.chunk_index = 0;
	g_manager.size_rest = 0;

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

	tiny_region = mmap(0, sizeof(t_tiny_region), PROT_READ | PROT_WRITE,
	MAP_ANON | MAP_PRIVATE, -1, 0);

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

	small_region = mmap(0, sizeof(t_small_region), PROT_READ | PROT_WRITE,
	MAP_ANON | MAP_PRIVATE, -1, 0);

	if (small_region != MAP_FAILED) {
		ft_bzero(small_region->info_block, sizeof(small_region->info_block));
		//small_region->header_prot = MAGIC_PROT;
		small_region->current_index = 0;
		small_region->nb_used = 0;
	}
	return small_region;
}

void				alloc_pool_block_large(void)
{
	printf("alloc_pool_block_large\n");
	g_manager.pool_block_large = mmap(0,
	sizeof(t_large_block) * NUM_LARGE_BLOCKS, PROT_READ | PROT_WRITE,
	MAP_ANON | MAP_PRIVATE, -1, 0);
}

t_large_block		*get_large_block(void) {
	return g_manager.pool_block_large + (g_manager.index_pool *
			SIZE_LARGE_BLOCK);
}

void 				keep_rest_large_block(size_t size, void *ptr) {
	g_manager.size_rest -= size;
	if (g_manager.size_rest >= (long)size)
		g_manager.ptr_rest = ptr + size;
}

t_large_block		*alloc_large_block(size_t size) {
	t_large_block	*large_block;

	if (g_manager.index_pool == 0)
		alloc_pool_block_large();
	large_block = get_large_block();
	if (g_manager.size_rest >= (long)size) {
		printf("KEEP\n");
		large_block->data = g_manager.ptr_rest;
	} else {
		printf("NEW\n");
		g_manager.chunk_index = 0;
		g_manager.size_rest = PAD_GOAL(size);
		large_block->data = mmap(0, PAD_GOAL(size),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	}

	if (large_block->data != MAP_FAILED) {
		large_block->used = 1;
		large_block->size = size;
		large_block->chunk_index = g_manager.chunk_index;
		g_manager.index_pool++;
		g_manager.chunk_index++;
		if (g_manager.index_pool == NUM_LARGE_BLOCKS)
			g_manager.index_pool = 0;
		keep_rest_large_block(size, large_block->data);
	}
	printf("%d\n", large_block->chunk_index);
	return large_block;
}