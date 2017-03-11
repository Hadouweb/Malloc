#include "malloc.h"

static void		show_ptr_tiny(void (*f)(const void*, size_t),
	t_tiny_region *r, void *ptr, size_t size)
{
	int		index;
	size_t 	min_size;

	index = (ptr - (void*)r) / SIZE_TINY_BLOCK;
	min_size = (size > r->info_block[index].size) ? r->info_block[index].size
		: size;
	ft_putstr(
	C_CYAN("********************** TINY BLOCK **********************\n"));
	ft_putstr(C_YELLOW("Start address: "));
	ft_putstr("\033[31;1m");
	ft_print_addr(ptr);
	ft_putstr("\n\033[0m");
	ft_putstr(C_YELLOW("End address:   "));
	ft_putstr("\033[31;1m");
	ft_print_addr(ptr + r->info_block[index].size);
	ft_putstr("\n\033[0m");
	ft_putstr(C_YELLOW("Size:          "));
	ft_putstr("\033[31;1m");
	ft_putnbr(r->info_block[index].size);
	ft_putstr("\n\033[0m");
	ft_putstr(C_YELLOW("Content :\n"));
	f(ptr, min_size);
}

static void		show_ptr_small(void (*f)(const void*, size_t),
	t_small_region *r, void *ptr, size_t size)
{
	int 	index;
	size_t 	min_size;

	index = (ptr - (void*)r) / SIZE_SMALL_BLOCK;
	min_size = (size > r->info_block[index].size) ? r->info_block[index].size
		: size;
	ft_putstr(
	C_CYAN("********************** SMALL BLOCK **********************\n"));
	ft_putstr(C_YELLOW("Start address: "));
	ft_putstr("\033[31;1m");
	ft_print_addr(ptr);
	ft_putstr("\n\033[0m");
	ft_putstr(C_YELLOW("End address:   "));
	ft_putstr("\033[31;1m");
	ft_print_addr(ptr + r->info_block[index].size);
	ft_putstr("\n\033[0m");
	ft_putstr(C_YELLOW("Size:          "));
	ft_putstr("\033[31;1m");
	ft_putnbr(r->info_block[index].size);
	ft_putstr("\n\033[0m");
	ft_putstr(C_YELLOW("Content :\n"));
	f(ptr, min_size);
}

static void		show_ptr_large(void (*f)(const void*, size_t),
	t_large_block *b, void *ptr, size_t size)
{
	int 			index;
	size_t 	min_size;

	min_size = (size > b->size) ? b->size : size;
	ft_putstr(
	C_CYAN("********************** LARGE BLOCK **********************\n"));
	ft_putstr(C_YELLOW("Start address: "));
	ft_putstr("\033[31;1m");
	ft_print_addr(ptr);
	ft_putstr("\n\033[0m");
	ft_putstr(C_YELLOW("End address:   "));
	ft_putstr("\033[31;1m");
	ft_print_addr(ptr + b->size);
	ft_putstr("\n\033[0m");
	ft_putstr(C_YELLOW("Size:          "));
	ft_putstr("\033[31;1m");
	ft_putnbr(b->size);
	ft_putstr("\n\033[0m");
	ft_putstr(C_YELLOW("Content :\n"));
	f(ptr, min_size);
}

void			show_ptr_ex(void *ptr, size_t size)
{
	t_tiny_region	*region_tiny;
	t_small_region	*region_small;
	t_large_block	*block_large;

	if ((region_tiny = find_on_tiny(ptr)) != NULL)
		show_ptr_tiny(ft_hex_dump, region_tiny, ptr, size);
	else if ((region_small = find_on_small(ptr)) != NULL)
		show_ptr_small(ft_hex_dump, region_small, ptr, size);
	else if ((block_large = find_on_large(ptr)) != NULL)
		show_ptr_large(ft_hex_dump, block_large, ptr, size);
}

void			show_ptr_bit(void *ptr, size_t size)
{
	t_tiny_region	*region_tiny;
	t_small_region	*region_small;
	t_large_block	*block_large;

	if ((region_tiny = find_on_tiny(ptr)) != NULL)
		show_ptr_tiny(ft_bit_dump, region_tiny, ptr, size);
	else if ((region_small = find_on_small(ptr)) != NULL)
		show_ptr_small(ft_bit_dump, region_small, ptr, size);
	else if ((block_large = find_on_large(ptr)) != NULL)
		show_ptr_large(ft_bit_dump, block_large, ptr, size);
}
