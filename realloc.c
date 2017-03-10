#include "malloc.h"

static void	*realloc_tiny_block(t_tiny_region *region, void *ptr, size_t size)
{
	int 	index;
	void	*new_ptr;

	index = (ptr - (void*)region) / SIZE_TINY_BLOCK;
	if (region->data[index] != ptr)
		return NULL;
	if (size <= SIZE_TINY_BLOCK)
	{
		region->info_block[index].size = size;
		return ptr;
	}
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, region->data[index], region->info_block[index].size);
	free_tiny_block(region, ptr);
	return new_ptr;
}

static void	*realloc_small_block(t_small_region *region, void *ptr, size_t size)
{
	int 	index;
	void	*new_ptr;

	index = (ptr - (void*)region) / SIZE_SMALL_BLOCK;
	if (region->data[index] != ptr)
		return NULL;
	if (size <= SIZE_SMALL_BLOCK)
	{
		region->info_block[index].size = size;
		return ptr;
	}
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, region->data[index], region->info_block[index].size);
	free_small_block(region, ptr);
	return new_ptr;
}

static void	*realloc_large_block(t_large_block *block, void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	ft_memcpy(new_ptr, block->data, block->size);
	free_large_block(block, ptr);
	return new_ptr;
}

void		*realloc(void *ptr, size_t size)
{
	t_tiny_region	*region_tiny;
	t_small_region	*region_small;
	t_large_block	*block_large;

	if (ptr == NULL)
		return malloc(size);
	else if (size == 0)
		free(ptr);
	else
	{
		region_tiny = find_on_tiny(ptr);
		if (region_tiny != NULL)
			return realloc_tiny_block(region_tiny, ptr, size);
		region_small = find_on_small(ptr);
		if (region_small != NULL)
			return realloc_small_block(region_small, ptr, size);
		block_large = find_on_large(ptr);
		if (block_large != NULL)
			return realloc_large_block(block_large, ptr, size);
	}
	return NULL;
}