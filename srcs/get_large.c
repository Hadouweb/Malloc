#include "../includes/malloc.h"

void			*get_ptr_large(size_t size)
{
	t_large_block 	*block;

	block = alloc_large_block(size);
	list_push_back(&g_manager.large_list, &block->link);
	return block->data;
}