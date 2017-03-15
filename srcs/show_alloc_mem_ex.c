/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_ex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:37:22 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/15 19:37:23 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	loop_tiny_block(void (*f)(const void*, size_t))
{
	t_link			*list;
	t_tiny_region	*region;
	int				i;

	list = g_manager.tiny_list.head;
	while (list)
	{
		i = 0;
		region = PTR_NODE(list, t_tiny_region, link);
		while (i < NUM_TINY_BLOCKS)
		{
			if (region->info_block[i].used == 1)
				f(region->data[i], MAX_SIZE_BYTE_SHOW);
			i++;
		}
		list = list->next;
	}
}

void	loop_small_block(void (*f)(const void*, size_t))
{
	t_link			*list;
	t_small_region	*region;
	int				i;

	list = g_manager.small_list.head;
	while (list)
	{
		i = 0;
		region = PTR_NODE(list, t_small_region, link);
		while (i < NUM_SMALL_BLOCKS)
		{
			if (region->info_block[i].used == 1)
				f(region->data[i], MAX_SIZE_BYTE_SHOW);
			i++;
		}
		list = list->next;
	}
}

void	loop_large_block(void (*f)(const void*, size_t))
{
	t_link			*list;
	t_large_block	*block;

	list = g_manager.large_list.head;
	while (list)
	{
		block = PTR_NODE(list, t_large_block, link);
		if (block->used == 1)
			f(block->data, 32);
		list = list->next;
	}
}

void	show_alloc_mem_ex(void)
{
	loop_tiny_block(ft_hex_dump);
	loop_small_block(ft_hex_dump);
	loop_large_block(ft_hex_dump);
}

void	show_alloc_mem_bit(void)
{
	loop_tiny_block(ft_bit_dump);
	loop_small_block(ft_bit_dump);
	loop_large_block(ft_bit_dump);
}
