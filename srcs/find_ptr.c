/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:36:32 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/15 19:36:40 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void		*find_ptr_tiny(t_tiny_region *r, size_t size)
{
	while (r->current_index < NUM_TINY_BLOCKS)
	{
		if (r->info_block[r->current_index].used == 0)
		{
			r->info_block[r->current_index].used = 1;
			r->info_block[r->current_index].size = size;
			r->nb_used++;
			if (r->current_index + 1 == NUM_TINY_BLOCKS)
				r->current_index = 0;
			return (r->data[r->current_index]);
		}
		r->current_index++;
	}
	return (NULL);
}

void			*get_ptr_tiny(size_t size)
{
	t_link			*list_region;
	t_tiny_region	*region;
	void			*ptr;

	region = NULL;
	list_region = g_manager.tiny_list.head;
	while (list_region)
	{
		region = PTR_NODE(list_region, t_tiny_region, link);
		if (region->nb_used + 1 < NUM_TINY_BLOCKS)
			break ;
		list_region = list_region->next;
	}
	if (list_region == NULL)
		region = load_tiny_region();
	if (region == MAP_FAILED)
		return (NULL);
	ptr = find_ptr_tiny(region, size);
	return (ptr);
}

static void		*find_ptr_small(t_small_region *r, size_t size)
{
	while (r->current_index < NUM_SMALL_BLOCKS)
	{
		if (r->info_block[r->current_index].used == 0)
		{
			r->info_block[r->current_index].used = 1;
			r->info_block[r->current_index].size = size;
			r->nb_used++;
			if (r->current_index + 1 == NUM_SMALL_BLOCKS)
				r->current_index = 0;
			return (r->data[r->current_index]);
		}
		r->current_index++;
	}
	return (NULL);
}

void			*get_ptr_small(size_t size)
{
	t_link			*list_region;
	t_small_region	*region;
	void			*ptr;

	region = NULL;
	list_region = g_manager.small_list.head;
	while (list_region)
	{
		region = PTR_NODE(list_region, t_small_region, link);
		if (region->nb_used + 1 < NUM_SMALL_BLOCKS)
			break ;
		list_region = list_region->next;
	}
	if (list_region == NULL)
		region = load_small_region();
	if (region == MAP_FAILED)
		return (NULL);
	ptr = find_ptr_small(region, size);
	return (ptr);
}

void			*get_ptr_large(size_t size)
{
	t_large_block	*block;

	block = alloc_large_block(size);
	ft_list_push_back(&g_manager.large_list, &block->link);
	return (block->data);
}
