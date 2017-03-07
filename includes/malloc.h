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

# include <stdio.h>
# include "libft.h"

enum	e_type {
	TINY,
	SMALL,
	LARGE
};

# define CHECKER_MAGIC_HEADER (1 << 31)
# define SIZE_TINY_BLOCK 16
# define SIZE_SMALL_BLOCK 512

typedef uint8_t		t_tiny_block[SIZE_TINY_BLOCK];
typedef uint8_t		t_small_block[SIZE_SMALL_BLOCK];

# define NUM_TINY_BLOCKS 64510
# define NUM_SMALL_BLOCKS 16319
# define PAGE_SIZE 4096

# define PAD_REGION (int)(sizeof(t_block) + sizeof(uint64_t))
# define SIZE_SMALL_REG (NUM_SMALL_BLOCKS * SIZE_SMALL_BLOCK) + PAD_REGION
# define SIZE_TINY_REG (NUM_TINY_BLOCKS * SIZE_TINY_BLOCK) + PAD_REGION
# define AC(X) (((double)X) / (double)PAGE_SIZE)
# define COEF(X) (int)((AC(X) == (int)AC(X)) ? AC(X) : AC(X) + 1)
# define PAD_GOAL(X) (PAGE_SIZE) * COEF(X)
# define PAD_TINY (PAD_GOAL(SIZE_TINY_REG) - (SIZE_TINY_REG))
# define PAD_SMALL (PAD_GOAL(SIZE_SMALL_REG) - (SIZE_SMALL_REG))

typedef struct		s_block {
	t_link			link;
	unsigned int	used:1;
	unsigned int	size:5;
	unsigned int	index:9;
}					t_block;

typedef struct		s_tiny_region {
	t_tiny_block	data[NUM_TINY_BLOCKS];
	uint64_t		header_prot;
	t_block			head_block;
	uint8_t			pad[PAD_TINY];
}					t_tiny_region;

typedef struct		s_small_region {
	t_small_block	data[NUM_SMALL_BLOCKS];
	uint64_t		header_prot;
	t_block			head_block;
	uint8_t			pad[PAD_SMALL];
}					t_small_region;

void				show_alloc_mem(void);
void				show_alloc_mem_ex(void);
void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				*get_ptr(enum e_type type);
char				*debug_enum(enum e_type type);

#endif
