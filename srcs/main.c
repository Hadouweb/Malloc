#include "malloc.h"

typedef struct 		s_tiny {
	int 			f:1;
	int 			s:4;
	int 			type:2;
	char 			m[16];
}					t_tiny;

typedef struct 		s_page {
	int 			i;
	char 			o;
	t_tiny 			tiny[100];
	struct s_page 	*next;
}					t_page;

int		main(void) {
	void *ptr1;
	void *ptr2;
	void *ptr3;


	ptr1 = malloc(17);
	ptr2 = malloc(4000);
	ptr3 = malloc(17);

	printf("%p\n", ptr1);
	printf("%p\n", ptr2);
	printf("%p\n", ptr3);

	long delta1 = ptr2 - ptr1;
	long delta2 = ptr3 - ptr2;

	printf("%ld\n", delta1);
	printf("%ld\n", delta2);

	show_alloc_mem();

	return 0;
}
