#include "malloc.h"

void				preload_region(t_manager *manager) {
	t_tiny_region	*tiny_region;
	//t_small_region	*small_region;

	tiny_region = alloc_tiny_region();
	if (manager)
		;
}

t_tiny_region		*alloc_tiny_region(void) {
	t_tiny_region	*tiny_region;

	tiny_region = mmap(0, sizeof(t_tiny_region), PROT_READ | PROT_WRITE,
	MAP_ANON | MAP_PRIVATE, -1, 0);

	if (tiny_region != MAP_FAILED) {
		tiny_region->header_prot = MAGIC_PROT;
		ft_bzero(tiny_region->info_block, sizeof(tiny_region->info_block));
	}
	return tiny_region;
}