#include "malloc.h"

void		free_tiny_block(t_tiny_region *region, void *ptr)
{
	int 			index;

	index = (ptr - (void*)region) / SIZE_TINY_BLOCK;
	region->info_block[index].size = 0;
	region->info_block[index].used = 0;
	region->nb_used--;
	region->current_index = index;
}

void		free_small_block(t_small_region *region, void *ptr)
{
	int 			index;

	index = (ptr - (void*)region) / SIZE_SMALL_BLOCK;
	region->info_block[index].size = 0;
	region->info_block[index].used = 0;
	region->nb_used--;
	region->current_index = index;
}

void		free_large_block(t_large_block *block, void *ptr)
{
	int ret;

	list_pop_node(&g_manager.large_list, &block->link);
	ret = munmap((void*)block,  PAD_GOAL(block->size + SIZE_LARGE_BLOCK));
	//printf("munmap %d\n", ret);
	(void)ptr;
}

void		free(void *ptr)
{
	t_tiny_region	*region_tiny;
	t_small_region	*region_small;
	t_large_block	*block_large;

	//ft_putstr("MY FREE\n");
	if (ptr == NULL)
		return ;
	region_tiny = find_on_tiny(ptr);
	if (region_tiny != NULL)
	{
		free_tiny_block(region_tiny, ptr);
		return ;
	}
	region_small = find_on_small(ptr);
	if (region_small != NULL)
	{
		free_small_block(region_small, ptr);
		return ;
	}
	block_large = find_on_large(ptr);
	if (block_large != NULL)
		free_large_block(block_large, ptr);
	//ft_putstr("MY FREE 2\n");
}