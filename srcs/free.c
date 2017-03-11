#include "../includes/malloc.h"

void		free_tiny_block(t_tiny_region *region, void *ptr)
{
	int 			index;

	index = (ptr - (void*)region) / SIZE_TINY_BLOCK;
	if (region->data[index] != ptr)
		return ;
	region->info_block[index].size = 0;
	region->info_block[index].used = 0;
	region->nb_used--;
	region->current_index = index;
}

void		free_small_block(t_small_region *region, void *ptr)
{
	int 			index;

	index = (ptr - (void*)region) / SIZE_SMALL_BLOCK;
	if (region->data[index] != ptr)
		return ;
	region->info_block[index].size = 0;
	region->info_block[index].used = 0;
	region->nb_used--;
	region->current_index = index;
}

void		free_large_block(t_large_block *block, void *ptr)
{
	list_pop_node(&g_manager.large_list, &block->link);
	munmap((void*)block,  PAD_GOAL(block->size + SIZE_LARGE_BLOCK));
	(void)ptr;
}

void		free(void *ptr)
{
	t_tiny_region	*region_tiny;
	t_small_region	*region_small;
	t_large_block	*block_large;

	pthread_mutex_lock(&mutex);
	if (ptr != NULL)
	{
		if ((region_tiny = find_on_tiny(ptr)) != NULL)
			free_tiny_block(region_tiny, ptr);
		else if ((region_small = find_on_small(ptr)) != NULL)
			free_small_block(region_small, ptr);
		else if ((block_large = find_on_large(ptr)) != NULL)
			free_large_block(block_large, ptr);
	}
	pthread_mutex_unlock(&mutex);
}