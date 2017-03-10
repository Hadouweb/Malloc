#include "malloc.h"

static void		*find_ptr_tiny(t_tiny_region * r, size_t size)
{
	int 	current_index;

	current_index = r->current_index;
	if (current_index == NUM_TINY_BLOCKS)
		current_index = 0;

	while (current_index < NUM_TINY_BLOCKS)
	{
		if (r->info_block[current_index].used == 0)
		{
			r->info_block[current_index].used = 1;
			r->info_block[current_index].size = size;
			r->current_index++;
			r->nb_used++;
			return r->data[current_index];
		}
		current_index++;
	}

	return NULL;
}

void			*get_ptr_tiny(size_t size)
{
	t_link			*list_region;
	t_tiny_region 	*region;
	void			*ptr;

	region = NULL;
	list_region = g_manager.tiny_list.head;
	while (list_region)
	{
		region = PTR_NODE(list_region, t_tiny_region, link);
		if (region->nb_used < NUM_TINY_BLOCKS)
			break;
		list_region = list_region->next;
	}

	if (list_region == NULL)
		region = load_tiny_region();
	ptr = find_ptr_tiny(region, size);
	return ptr;
}
