#include "malloc.h"

void				keep_unused_mem(void *ptr) {
	t_large_block		*unused;
	size_t 				delta;

	//printf("size: %zu\n", size);
	//printf("ptr2 %p\n", ptr);
	delta = sizeof(t_large_block) - sizeof(void*);
	//printf("rest_size2 %d %d\n", g_manager.size_unused, SIZE_SMALL_BLOCK + delta);
	if (g_manager.size_unused > SIZE_SMALL_BLOCK + delta)
	{
		//printf("rest_size4 %d\n", g_manager.size_unused);
		unused = (t_large_block*)ptr;
		//printf("ok6\n");
		unused->header_prot = MAGIC_PROT;
		//printf("ok7\n");
		unused->used = 0;
		unused->size = g_manager.size_unused;
		unused->data = ptr + delta;
		//printf("ok10\n");
		list_push_back(&g_manager.large_list, &unused->link);
	}
}

t_large_block		*find_large_block(size_t size) {
	t_link			*link;
	t_large_block	*block;
	size_t 			delta;

	link = g_manager.large_list.head;
	while (link) {
		delta = sizeof(t_large_block) - sizeof(void*);
		block = PTR_NODE(link, t_large_block, link);
		if (block->used == 0 && block->size > size) {
			//printf("ok8\n");
			block->used = 1;
			block->size = size;
			block->data = (void*)block + delta;
			g_manager.size_unused -= size + delta;
			keep_unused_mem((void*)block + delta + size);
			return block;
		}
		link = link->next;
	}
	return NULL;
}

void			*get_ptr_large(size_t size) {
	t_large_block 	*block;
	void			*ptr;

	//printf("rest_size %d\n", g_manager.size_unused);
	block = find_large_block(size);
	//printf("rest_size %d\n", g_manager.size_unused);
	//if (block)
		//printf("find_large_block: %zu\n", block->size);
	if (block == NULL) {
		//printf("alloc_large_block\n");
		block = alloc_large_block(size);
		list_push_back(&g_manager.large_list, &block->link);
	}
	ptr = block->data;

	return ptr;
}