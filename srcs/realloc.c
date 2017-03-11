#include "../includes/malloc.h"

void	*realloc_tiny_block(t_tiny_region *region, void *ptr, size_t size)
{
	int 	index;
	void	*new_ptr;
	size_t 	min_size;

	index = (ptr - (void*)region) / SIZE_TINY_BLOCK;
	if (region->data[index] != ptr)
		return NULL;
	if (size <= SIZE_TINY_BLOCK)
	{
		region->info_block[index].size = size;
		return ptr;
	}
	new_ptr = malloc_unsafe(size);
	min_size = (region->info_block[index].size < size) ?
		region->info_block[index].size : size;
	ft_memcpy(new_ptr, region->data[index], min_size);
	free_tiny_block(region, ptr);
	return new_ptr;
}

void	*realloc_small_block(t_small_region *region, void *ptr, size_t size)
{
	int 	index;
	void	*new_ptr;
	size_t 	min_size;

	index = (ptr - (void*)region) / SIZE_SMALL_BLOCK;
	if (region->data[index] != ptr)
		return NULL;
	if (size <= SIZE_SMALL_BLOCK)
	{
		region->info_block[index].size = size;
		return ptr;
	}
	new_ptr = malloc_unsafe(size);
	min_size = (region->info_block[index].size < size) ?
			   region->info_block[index].size : size;
	ft_memcpy(new_ptr, region->data[index], min_size);
	free_small_block(region, ptr);
	return new_ptr;
}

void	*realloc_large_block(t_large_block *block, void *ptr, size_t size)
{
	void	*new_ptr;
	size_t 	min_size;

	new_ptr = malloc_unsafe(size);
	min_size = (block->size < size) ? block->size : size;
	ft_memcpy(new_ptr, block->data, min_size);
	free_large_block(block, ptr);
	return new_ptr;
}

void	*realloc(void *ptr, size_t size)
{
	t_tiny_region	*region_tiny;
	t_small_region	*region_small;
	t_large_block	*block_large;
	void			*ptr_ret;

	ptr_ret = ptr;
	pthread_mutex_lock(&mutex);
	if (ptr == NULL)
		ptr_ret = malloc_unsafe(size);
	else if (size == 0)
		free_unsafe(ptr);
	else
	{
		region_tiny = find_on_tiny(ptr);
		if (region_tiny != NULL)
			ptr_ret = realloc_tiny_block(region_tiny, ptr, size);
		region_small = find_on_small(ptr);
		if (region_small != NULL)
			ptr_ret = realloc_small_block(region_small, ptr, size);
		block_large = find_on_large(ptr);
		if (block_large != NULL)
			ptr_ret = realloc_large_block(block_large, ptr, size);
	}
	pthread_mutex_unlock(&mutex);
	return ptr_ret;
}