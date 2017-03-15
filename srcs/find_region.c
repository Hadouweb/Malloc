/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_region.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:36:45 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/15 19:36:46 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*find_on_tiny(void *ptr)
{
	t_tiny_region	*region;
	t_link			*link;
	void			*start;
	void			*end;

	link = g_manager.tiny_list.head;
	while (link)
	{
		region = PTR_NODE(link, t_tiny_region, link);
		start = (void*)region;
		end = (void*)region + sizeof(t_tiny_region);
		if (ptr >= start && ptr <= end)
			return (region);
		link = link->next;
	}
	return (NULL);
}

void		*find_on_small(void *ptr)
{
	t_small_region	*region;
	t_link			*link;
	void			*start;
	void			*end;

	link = g_manager.small_list.head;
	while (link)
	{
		region = PTR_NODE(link, t_small_region, link);
		start = (void*)region;
		end = (void*)region + sizeof(t_small_region);
		if (ptr >= start && ptr <= end)
			return (region);
		link = link->next;
	}
	return (NULL);
}

void		*find_on_large(void *ptr)
{
	t_large_block	*block;
	t_link			*link;
	void			*start;

	link = g_manager.large_list.head;
	while (link)
	{
		block = PTR_NODE(link, t_large_block, link);
		if (block->used == 1)
		{
			start = block->data;
			if (ptr == start)
				return (block);
		}
		link = link->next;
	}
	return (NULL);
}
