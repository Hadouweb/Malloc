#include "malloc.h"

void	*get_ptr(enum e_type type) {
	void	*ptr;

	ptr = NULL;
	if (type)
		;
	//printf("Alloc tiny %s\n", debug_enum(type));

	return ptr;
}

void 	*m_malloc(size_t size) {
	t_manager manager;
	void	*ptr;

	preload_region(&manager);

	ptr = NULL;
	if (size <= SIZE_TINY_BLOCK) {
		get_ptr(TINY);
	}

	return ptr;
}