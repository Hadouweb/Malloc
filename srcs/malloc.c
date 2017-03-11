#include "../includes/malloc.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void 	*malloc(size_t size) {
	void	*ptr;

	pthread_mutex_lock(&mutex);
	ptr = NULL;
	if (size > 0 && size <= SIZE_TINY_BLOCK)
		ptr = get_ptr_tiny(size);
	else if (size > SIZE_TINY_BLOCK && size <= SIZE_SMALL_BLOCK)
		ptr = get_ptr_small(size);
	else if (size > 0 && size > SIZE_SMALL_BLOCK)
		ptr = get_ptr_large(size);
	pthread_mutex_unlock(&mutex);
	return ptr;
}