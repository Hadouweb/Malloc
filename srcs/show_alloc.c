/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:37:10 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/15 19:37:12 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	show_tiny_region(t_link *list_region)
{
	int				i;
	t_tiny_region	*region;

	region = PTR_NODE(list_region, t_tiny_region, link);
	if (region->nb_used == 0)
		return ;
	ft_putstr("TINY : ");
	print_addr(region);
	ft_putstr("\n");
	while (list_region)
	{
		i = 0;
		region = PTR_NODE(list_region, t_tiny_region, link);
		while (i < NUM_TINY_BLOCKS)
		{
			if (region->info_block[i].used == 1)
				print_ptr(region->data[i], region->info_block[i].size);
			i++;
		}
		list_region = list_region->next;
	}
}

void	show_small_region(t_link *list_region)
{
	int				i;
	t_small_region	*region;

	region = PTR_NODE(list_region, t_small_region, link);
	if (region->nb_used == 0)
		return ;
	ft_putstr("SMALL : ");
	print_addr(region);
	ft_putstr("\n");
	while (list_region)
	{
		i = 0;
		region = PTR_NODE(list_region, t_small_region, link);
		while (i < NUM_SMALL_BLOCKS)
		{
			if (region->info_block[i].used == 1)
				print_ptr(region->data[i], region->info_block[i].size);
			i++;
		}
		list_region = list_region->next;
	}
}

void	show_large_block(t_link *list_region)
{
	t_large_block	*block;

	block = PTR_NODE(list_region, t_large_block, link);
	ft_putstr("LARGE : ");
	print_addr(block);
	ft_putstr("\n");
	while (list_region)
	{
		block = PTR_NODE(list_region, t_large_block, link);
		if (block->used == 1)
			print_ptr(block->data, block->size);
		list_region = list_region->next;
	}
}

void	show_alloc_mem(void)
{
	pthread_mutex_lock(&g_mutex);
	if (g_manager.tiny_list.head != NULL)
		show_tiny_region(g_manager.tiny_list.head);
	if (g_manager.small_list.head != NULL)
		show_small_region(g_manager.small_list.head);
	if (g_manager.large_list.head != NULL)
		show_large_block(g_manager.large_list.head);
	pthread_mutex_unlock(&g_mutex);
}
