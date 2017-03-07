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

# define MAGIC_PROT (1 << 31)
# define SIZE_TINY_BLOCK 16
# define SIZE_SMALL_BLOCK 512

typedef uint8_t		t_tiny_block[SIZE_TINY_BLOCK];
typedef uint8_t		t_small_block[SIZE_SMALL_BLOCK];

# define NUM_TINY_BLOCKS  65535
# define NUM_SMALL_BLOCKS 16376
# define PAGE_SIZE 4096

# define SIZE_TINY_DATA (NUM_TINY_BLOCKS * SIZE_TINY_BLOCK)
# define SIZE_TINY_INFO (NUM_TINY_BLOCKS * sizeof(t_block))

# define SIZE_SMALL_DATA (NUM_SMALL_BLOCKS * SIZE_SMALL_BLOCK)
# define SIZE_SMALL_INFO (NUM_SMALL_BLOCKS * sizeof(t_block))

# define SIZE_TOKEN sizeof(uint32_t) * 3

# define PAD_REG_TINY (int)(SIZE_TINY_DATA + SIZE_TINY_INFO + SIZE_TOKEN)
# define PAD_REG_SMALL (int)(SIZE_SMALL_DATA + SIZE_SMALL_INFO + SIZE_TOKEN)

# define AC(X) (((double)X) / (double)PAGE_SIZE)
# define COEF(X) (int)((AC(X) == (int)AC(X)) ? AC(X) : AC(X) + 1)
# define PAD_GOAL(X) (PAGE_SIZE) * COEF(X)
# define PAD_TINY (PAD_GOAL(PAD_REG_TINY) - (PAD_REG_TINY))
# define PAD_SMALL (PAD_GOAL(PAD_REG_SMALL) - (PAD_REG_SMALL))

typedef struct		s_block {
	unsigned int	used:1;
	unsigned int	size:31;
}					t_block;

typedef struct		s_tiny_region {
	t_tiny_block	data[NUM_TINY_BLOCKS];
	uint32_t		header_prot;
	t_block			info_block[NUM_TINY_BLOCKS];
	uint32_t 		current_index;
	uint32_t 		nb_used;
	uint8_t			pad[PAD_TINY];
}					t_tiny_region;


typedef struct		s_small_region {
	t_small_block	data[NUM_SMALL_BLOCKS];
	uint32_t		header_prot;
	t_block			info_block[NUM_SMALL_BLOCKS];
	uint32_t 		current_index;
	uint32_t 		nb_used;
	uint8_t			pad[PAD_SMALL];
}					t_small_region;

typedef struct 		s_list_region {
	t_link			link;
	enum e_type		type;
	void			*region;
}					t_list_region;

typedef struct		s_manager {
	t_list_region	all_region;
}					t_manager;

void				show_alloc_mem(void);
void				show_alloc_mem_ex(void);
void				free(void *ptr);
void				*m_malloc(size_t size); // A changer malloc
void				*realloc(void *ptr, size_t size);

void				*get_ptr(enum e_type type);

void				preload_region(t_manager *manager);
t_tiny_region		*alloc_tiny_region(void);
t_small_region		*alloc_small_region(void);

char				*debug_enum(enum e_type type);

#endif
