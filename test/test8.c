#include "../includes/malloc.h"

int		main(void)
{
	ft_putstr("\n-----------> malloc 125\n");
	ft_putstr("-----------> strcpy(ptr, \"Bonjour\")\n");
	char *ptr = malloc(125);
	strcpy(ptr, "Bonjour");
	show_ptr_ex(ptr, 10);

	ft_putstr("\n-----------> realloc 5\n");
	ptr = realloc(ptr, 5);
	show_ptr_ex(ptr, 10);

	ft_putstr("\n-----------> realloc 15\n");
	ptr = realloc(ptr, 15);
	show_ptr_ex(ptr, 10);

	ft_putstr("\n-----------> realloc 5\n");
	ptr = realloc(ptr, 5);
	show_ptr_ex(ptr, 10);

	ft_putstr("\n-----------> realloc 10000\n");
	ptr = realloc(ptr, 10000);
	show_ptr_ex(ptr, 10);

	return (0);
}