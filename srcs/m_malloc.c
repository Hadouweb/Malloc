#include "malloc.h"

void 	*malloc(size_t size) {
	void	*ptr;

	printf("My Malloc\n");

	return (NULL);
	if (g_manager.tiny_list == NULL && g_manager.small_list == NULL) {
		preload_region();
	}

	ptr = NULL;
	/*if (size > 0 && size <= SIZE_TINY_BLOCK)
		ptr = get_ptr_tiny(size);
	else if (size > SIZE_TINY_BLOCK && size <= SIZE_SMALL_BLOCK)
		ptr = get_ptr_small(size);
	else if (size > 0 && size > SIZE_SMALL_BLOCK)
		ptr = get_ptr_large(size);*/

	(void)size;

	return ptr;
}