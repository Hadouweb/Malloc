#include "malloc.h"

void	*get_ptr(enum e_type type) {
	void	*ptr;

	ptr = NULL;
	printf("Alloc tiny %s\n", debug_enum(type));

	return ptr;
}

void 	*malloc(size_t size) {
	void	*ptr;

	ptr = NULL;
	if (size <= SIZE_TINY_BLOCK) {
		get_ptr(TINY);
	}

	return ptr;
}