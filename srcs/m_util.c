#include "malloc.h"

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

void	print_addr(void *ptr)
{
	char			str[20];
	int				size;
	int				sign;
	unsigned long 	value;

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

void	list_push_back(t_list *list, t_link *link)
{
	if (link == NULL)
		return ;
	if (list->head == NULL) {
		list->head = link;
		list->tail = link;
		list->size++;
		return ;
	}
	list->tail->next = link;
	link->prev = list->tail;
	list->tail = link;
	list->size++;
}