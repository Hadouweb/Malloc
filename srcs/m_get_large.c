#include "malloc.h"


void			*get_ptr_large(size_t size) {
	t_large_block 	*block;
	void			*ptr;

	//printf("rest_size %d\n", g_manager.size_unused);
	//printf("rest_size %d\n", g_manager.size_unused);
	//if (block)
		//printf("find_large_block: %zu\n", block->size);
	//if (block == NULL) {
		//printf("alloc_large_block\n");
		block = alloc_large_block(size);
		list_push_back(&g_manager.large_list, &block->link);
	//}
	//printf("%p\n", block);
	//printf("%p\n", block->data);
	ptr = block->data;

	return ptr;
}