/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 05:09:00 by nle-bret          #+#    #+#             */
/*   Updated: 2017/03/07 05:09:01 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include <sys/resource.h>
# include <errno.h>
# include <stdlib.h>
# include <pthread.h>

# include <stdio.h>
# include "../libft/includes/libft.h"


enum	e_type {
	TINY,
	SMALL,
	LARGE
};

# define MAGIC_PROT (1 << 31)
# define SIZE_TINY_BLOCK 1024
# define SIZE_SMALL_BLOCK 32768

typedef uint8_t		t_tiny_block[SIZE_TINY_BLOCK];
typedef uint8_t		t_small_block[SIZE_SMALL_BLOCK];

# define NUM_TINY_BLOCKS 1024
# define NUM_SMALL_BLOCKS 1024
# define PAGE_SIZE getpagesize()

# define S_TINY_DATA (NUM_TINY_BLOCKS * SIZE_TINY_BLOCK)
# define S_TINY_INFO (NUM_TINY_BLOCKS * sizeof(t_block))

# define S_SMALL_DATA (NUM_SMALL_BLOCKS * SIZE_SMALL_BLOCK)
# define S_SMALL_INFO (NUM_SMALL_BLOCKS * sizeof(t_block))

# define S_TOKEN sizeof(uint32_t) * 2 + sizeof(t_link)

# define PAD_REG_TINY (int)(S_TINY_DATA + S_TINY_INFO + S_TOKEN)
# define PAD_REG_SMALL (int)(S_SMALL_DATA + S_SMALL_INFO + S_TOKEN)

# define AC(X) (((double)X) / (double)PAGE_SIZE)
# define COEF(X) (int)((AC(X) == (int)AC(X)) ? AC(X) : AC(X) + 1)
# define PAD_GOAL(X) (size_t)(PAGE_SIZE) * COEF(X)
# define PAD_TINY (PAD_GOAL(PAD_REG_TINY) - (PAD_REG_TINY))
# define PAD_SMALL (PAD_GOAL(PAD_REG_SMALL) - (PAD_REG_SMALL))

# define SIZE_LARGE_BLOCK sizeof(t_large_block)

typedef struct		s_block {
	uint32_t		used:1;
	uint32_t		size:31;
}					t_block;

typedef struct		s_tiny_region
{
	t_tiny_block	data[NUM_TINY_BLOCKS];
	t_block			info_block[NUM_TINY_BLOCKS];
	uint32_t 		current_index:16;
	uint32_t 		nb_used:16;
	t_link			link;
}					t_tiny_region;

typedef struct		s_small_region {
	t_small_block	data[NUM_SMALL_BLOCKS];
	t_block			info_block[NUM_SMALL_BLOCKS];
	uint32_t 		current_index:16;
	uint32_t 		nb_used:16;
	t_link			link;
}					t_small_region;

typedef struct		s_large_block {
	uint8_t			used;
	size_t			size;
	t_link			link;
	void			*data;
}					t_large_block;

typedef struct		s_manager {
	t_list			tiny_list;
	t_list			small_list;
	t_list			large_list;
}					t_manager;

t_manager			g_manager;
pthread_mutex_t		mutex;

void				show_alloc_mem(void);
void				show_alloc_mem_ex(void);
void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);

void 				*malloc_unsafe(size_t size);
void				free_unsafe(void *ptr);

void				*realloc_tiny_block(t_tiny_region *region,
						void *ptr, size_t size);
void				*realloc_small_block(t_small_region *region,
						void *ptr, size_t size);
void				*realloc_large_block(t_large_block *block,
						void *ptr, size_t size);

void 				show_tiny_region(t_link *list_region);
void 				show_small_region(t_link *list_region);
void 				show_large_block(t_link *list_region);

void				free_tiny_block(t_tiny_region *region, void *ptr);
void				free_small_block(t_small_region *region, void *ptr);
void				free_large_block(t_large_block *block, void *ptr);

void				*find_on_tiny(void *ptr);
void				*find_on_small(void *ptr);
void				*find_on_large(void *ptr);

void				*get_ptr_tiny(size_t size);
void				*get_ptr_small(size_t size);
void				*get_ptr_large(size_t size);

t_tiny_region		*load_tiny_region(void);
t_tiny_region		*alloc_tiny_region(void);

t_small_region		*load_small_region(void);
t_small_region		*alloc_small_region(void);

t_large_block		*alloc_large_block(size_t size);

void				print_addr(void *ptr);
void 				print_ptr(void *start, size_t size);
void				list_pop_node(t_list *list, t_link *link);
void				list_push_back(t_list *list, t_link *link);

void				error_exit(char *str);

char				*debug_enum(enum e_type type);

#endif
