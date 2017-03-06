#include <sys/mman.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>
#include <stdlib.h>

#include <stdio.h>

int 	main(void) {
	int b[10];

	b[1] = 42;
	b[8] = 12323233;
	b[0] = 42;

	return 0;
}