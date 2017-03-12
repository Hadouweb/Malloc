#include "../includes/malloc.h"

int		main(void)
{
	char *ptr_tiny = malloc(1);
	ptr_tiny[1019904] = 'a';
	ft_putstr_fd("free ptr tiny : ", 2);
	free(ptr_tiny);
	ft_putstr_fd("realloc ptr tiny : ", 2);
	realloc(ptr_tiny, 2);
	ft_putstr_fd("\n", 2);
	//show_alloc_mem();

	char *ptr_small = malloc(2000);
	ptr_small[33554432] = 'a';
	ft_putstr_fd("free ptr small : ", 2);
	free(ptr_small);
	ft_putstr_fd("realloc ptr small : ", 2);
	realloc(ptr_small, 3000);
	ft_putstr_fd("\n", 2);
	//show_alloc_mem();

	char *ptr_large = malloc(200000);
	ptr_large[-SIZE_LARGE_BLOCK] = 'a';
	ft_putstr_fd("free ptr large : ", 2);
	free(ptr_large);
	ft_putstr_fd("realloc ptr large : ", 2);
	realloc(ptr_large, 300000);
	ft_putstr_fd("\n", 2);
	//show_alloc_mem();*/

	return (0);
}