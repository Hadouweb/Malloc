/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:37:42 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/15 19:37:43 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static int	ft_ull_len(unsigned long long value, int base)
{
	int		i;

	i = 0;
	if (value == 0)
		i++;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

void		print_addr(void *ptr)
{
	char			str[20];
	int				size;
	unsigned long	value;

	value = (unsigned long)ptr;
	size = ft_ull_len(value, 16);
	str[size--] = '\0';
	if (value == 0)
		str[0] = '0';
	while (value)
	{
		str[size] = value % 16;
		if (str[size] >= 10)
			str[size] += 7;
		str[size] += '0';
		value /= 16;
		size--;
	}
	write(1, "0x", 2);
	write(1, str, ft_strlen(str));
}

void		list_pop_node(t_list *list, t_link *link)
{
	t_link	*prev;
	t_link	*next;

	if (link == NULL)
		return ;
	prev = link->prev;
	next = link->next;
	if (list->head == link)
		list->head = next;
	if (list->tail == link)
		list->tail = prev;
	if (prev != NULL)
		prev->next = next;
	if (next != NULL)
		next->prev = prev;
	list->size--;
}

void		print_ptr(void *start, size_t size)
{
	print_addr(start);
	ft_putstr(" - ");
	print_addr(start + size);
	ft_putstr(" : ");
	ft_putnbr(size);
	if (size == 1)
		ft_putstr(" octet\n");
	else
		ft_putstr(" octets\n");
}
