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

# define NUM_TINY_BLOCKS  64510
# define NUM_SMALL_BLOCKS 16376
# define PAGE_SIZE 4096

# define S_TINY_DATA (NUM_TINY_BLOCKS * SIZE_TINY_BLOCK)
# define S_TINY_INFO (NUM_TINY_BLOCKS * sizeof(t_block))

# define S_SMALL_DATA (NUM_SMALL_BLOCKS * SIZE_SMALL_BLOCK)
# define S_SMALL_INFO (NUM_SMALL_BLOCKS * sizeof(t_block))

# define S_TOKEN sizeof(uint32_t) * 2
# define S_LINK sizeof(t_link)

# define PAD_REG_TINY (int)(S_TINY_DATA + S_TINY_INFO + S_TOKEN + S_LINK)
# define PAD_REG_SMALL (int)(S_SMALL_DATA + S_SMALL_INFO + S_TOKEN + S_LINK)

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
	uint32_t 		current_index:16;
	uint32_t 		nb_used:16;
	t_link			link;
	uint8_t			pad[PAD_TINY];
}					t_tiny_region;

typedef struct		s_small_region {
	t_small_block	data[NUM_SMALL_BLOCKS];
	uint32_t		header_prot;
	t_block			info_block[NUM_SMALL_BLOCKS];
	uint32_t 		current_index:16;
	uint32_t 		nb_used:16;
	t_link			link;
	uint8_t			pad[PAD_SMALL];
}					t_small_region;

typedef struct		s_large_block {
	uint32_t		header_prot;
	char			used:1;
	uint64_t		size;
	t_link			link;
	void			*data;
}					t_large_block;

typedef struct		s_manager {
	t_list			*tiny_list;
	t_list			*small_list;
	t_list			*large_list;
}					t_manager;

t_manager			g_manager;

void				show_alloc_mem(void);
void				show_alloc_mem_ex(void);
void				m_free(void *ptr); 		// A changer free
void				*m_malloc(size_t size); // A changer malloc
void				*realloc(void *ptr, size_t size);

void				*get_ptr_tiny(size_t size);
void				*get_ptr_small(size_t size);
void				*get_ptr_large(size_t size);

void				preload_region(void);
t_tiny_region		*alloc_tiny_region(void);
t_small_region		*alloc_small_region(void);
t_large_block		*alloc_large_block(size_t size);

void				error_exit(char *str);

char				*debug_enum(enum e_type type);

#endif
