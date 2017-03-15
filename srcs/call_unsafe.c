/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_unsafe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:36:22 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/15 19:36:23 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc_unsafe(size_t size)
{
	void	*ptr;

	ptr = NULL;
	if (size > 0 && size <= SIZE_TINY_BLOCK)
		ptr = get_ptr_tiny(size);
	else if (size > SIZE_TINY_BLOCK && size <= SIZE_SMALL_BLOCK)
		ptr = get_ptr_small(size);
	else if (size > 0 && size > SIZE_SMALL_BLOCK)
		ptr = get_ptr_large(size);
	return (ptr);
}

void	free_unsafe(void *ptr)
{
	t_tiny_region	*region_tiny;
	t_small_region	*region_small;
	t_large_block	*block_large;

	if (ptr != NULL)
	{
		if ((region_tiny = find_on_tiny(ptr)) != NULL)
			free_tiny_block(region_tiny, ptr);
		else if ((region_small = find_on_small(ptr)) != NULL)
			free_small_block(region_small, ptr);
		else if ((block_large = find_on_large(ptr)) != NULL)
			free_large_block(block_large);
	}
}
