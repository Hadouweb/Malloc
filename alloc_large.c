#include "malloc.h"

t_large_block		*alloc_large_block(size_t size) {
	t_large_block	*large_block;

	large_block = mmap(0, PAD_GOAL(size + SIZE_LARGE_BLOCK),
					   PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	if (large_block == MAP_FAILED)
		error_exit("can't allocate large block MAP_FAILED\n");
	if (large_block != MAP_FAILED) {
		large_block->used = 1;
		large_block->size = size;
		large_block->data = (void*)large_block + SIZE_LARGE_BLOCK;
	}
	return large_block;
}