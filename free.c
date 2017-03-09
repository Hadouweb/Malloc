#include "malloc.h"

static void		*find_on_tiny(void *ptr)
{
	t_link		*link;
	void		*start;
	void		*end;

	link = g_manager.tiny_list.head;
	while (link) {
		t_tiny_region *region = PTR_NODE(link, t_tiny_region, link);
		start = (void*)region;
		end = (void*)region + NUM_TINY_BLOCKS;
		if (ptr >= start && ptr < end)
			return region;
		link = link->next;
	}
	return NULL;
}

static void		*find_on_small(void *ptr)
{
	t_link		*link;
	void		*start;
	void		*end;

	link = g_manager.tiny_list.head;
	while (link) {
		t_small_region *region = PTR_NODE(link, t_small_region, link);
		start = (void*)region;
		end = (void*)region + NUM_SMALL_BLOCKS;
		if (ptr >= start && ptr < end)
			return region;
		link = link->next;
	}
	return NULL;
}


static void		*find_on_large(void *ptr)
{
	t_link		*link;
	void		*start;

	link = g_manager.tiny_list.head;
	while (link) {
		t_large_block *block = PTR_NODE(link, t_large_block, link);
		printf("used: %d\n", block->used);
		printf("size: %zu\n", block->size);

		if (block->used == 1) {
			printf("ptr: %p\n", ptr);
			printf("start: %p\n", start);
			printf("block: %p\n", block);
			start = block->data;
			if (ptr == start)
				return block;
		}
		link = link->next;
	}
	return NULL;
}

static void		set_block(void *ptr)
{
	t_tiny_region	*region_tiny;
	t_small_region	*region_small;
	t_large_block	*block_large;
	int 			index;

	region_tiny = find_on_tiny(ptr);
	if (region_tiny != NULL)
	{
		index = (ptr - (void*)region_tiny) / SIZE_TINY_BLOCK;
		region_tiny->info_block[index].size = 0;
		region_tiny->info_block[index].used = 0;
		region_tiny->nb_used--;
		region_tiny->current_index = index;
		return ;
	}
	region_small = find_on_small(ptr);
	if (region_small != NULL)
	{
		index = (ptr - (void*)region_small) / SIZE_SMALL_BLOCK;
		region_small->info_block[index].size = 0;
		region_small->info_block[index].used = 0;
		region_small->nb_used--;
		region_small->current_index = index;
		return ;
	}
	block_large = find_on_large(ptr);
	if (block_large != NULL)
	{
		block_large->size = 0;
		block_large->used = 0;
	}
}

void			m_free(void *ptr)
{
	printf("LOL\n");
	//set_block(ptr);
}