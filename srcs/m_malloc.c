#include "malloc.h"

void 	*malloc(size_t size) {
	void	*ptr;

	if (g_manager.tiny_list.head == NULL && g_manager.small_list.head == NULL) {
		preload_region();
	}

	ptr = NULL;
	if (size > 0 && size <= SIZE_TINY_BLOCK)
		ptr = get_ptr_tiny(size);
	else if (size > SIZE_TINY_BLOCK && size <= SIZE_SMALL_BLOCK)
		ptr = get_ptr_small(size);
	else if (size > 0 && size > SIZE_SMALL_BLOCK)
		ptr = get_ptr_large(size);

	//printf("size tiny: %lu\n", g_manager.tiny_list.size);
	//printf("size small: %lu\n", g_manager.small_list.size);
	//printf("size large: %lu\n", g_manager.large_list.size);

	return ptr;
}