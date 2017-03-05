#ifndef MALLOC_H
# define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <sys/resource.h>
#include <curses.h>
#include <errno.h>

#include <stdio.h>
#include "libft.h"

void show_alloc_mem(void);
void show_alloc_mem_ex(void);


#endif