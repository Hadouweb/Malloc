/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unmap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:37:36 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/15 19:37:37 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	unmap_tiny_region(void)
{
	t_link			*list;
	t_tiny_region	*region;
	int				token;

	token = 0;
	list = g_manager.tiny_list.head;
	while (list)
	{
		region = PTR_NODE(list, t_tiny_region, link);
		if (region->nb_used == 0 && token == 0)
			token = 1;
		else if (region->nb_used == 0 && token == 1)
		{
			list_pop_node(&g_manager.tiny_list, &region->link);
			munmap((void *)region, PAD_GOAL(sizeof(t_tiny_region)));
			return ;
		}
		list = list->next;
	}
}

void	unmap_small_region(void)
{
	t_link			*list;
	t_small_region	*region;
	int				token;

	token = 0;
	list = g_manager.small_list.head;
	while (list)
	{
		region = PTR_NODE(list, t_small_region, link);
		if (region->nb_used == 0 && token == 0)
			token = 1;
		else if (region->nb_used == 0 && token == 1)
		{
			list_pop_node(&g_manager.small_list, &region->link);
			munmap((void *)region, PAD_GOAL(sizeof(t_small_region)));
			return ;
		}
		list = list->next;
	}
}

size_t	get_size_region(enum e_type t)
{
	if (t == TINY)
		return (g_manager.tiny_list.size);
	else if (t == SMALL)
		return (g_manager.small_list.size);
	else if (t == LARGE)
		return (g_manager.large_list.size);
	return (0);
}
