#include "malloc.h"

void			*get_ptr_large(size_t size)
{
	t_large_block 	*block;
	void			*ptr;

	block = alloc_large_block(size);
	list_push_back(&g_manager.large_list, &block->link);
	ptr = block->data;

	return ptr;
}
