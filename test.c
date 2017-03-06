#include <sys/mman.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>
#include <stdlib.h>

#include <stdio.h>

int 	main(void) {
	struct rlimit limit;
	char *ptr;

	int ret = getrlimit(RLIMIT_AS, &limit);
	unsigned long long limit_memory = limit.rlim_cur / 100000;
	ptr = malloc(limit_memory);

	int i = 0;
	while (i < limit_memory) {
		ptr[i] = i;
		i++;
	}

	printf("limit_memory: %llu\n", limit_memory);
	printf("rlim_cur: %llu\n", limit.rlim_cur);
	printf("rlim_max: %llu\n", limit.rlim_max);

	while(42)
		;

	return 0;
}