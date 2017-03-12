CC = gcc
FLAG = -Werror -Wextra -Wall -g

LIBFT_PATH = ./libft
SRCS_PATH = ./srcs
INC_PATH = ./includes

HEADER = -I $(LIBFT_PATH)/includes -I $(INC_PATH)

LIB = -L$(LIBFT_PATH) -lft
LIBNAME = $(LIBFT_PATH)/libft.a

SRC =   $(SRCS_PATH)/malloc.c\
        $(SRCS_PATH)/alloc.c\
        $(SRCS_PATH)/error.c\
        $(SRCS_PATH)/find_ptr.c\
        $(SRCS_PATH)/show_alloc.c\
        $(SRCS_PATH)/util.c\
        $(SRCS_PATH)/free.c\
        $(SRCS_PATH)/find_region.c\
        $(SRCS_PATH)/realloc.c\
        $(SRCS_PATH)/call_unsafe.c\
        $(SRCS_PATH)/show_alloc_mem_ex.c\
        $(SRCS_PATH)/show_ptr.c\
        $(SRCS_PATH)/unmap.c\

OBJ = $(SRC:.c=.o)

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINK = libft_malloc.so

all: $(NAME)

$(NAME): $(LIBNAME) $(OBJ)
	@$(CC) -shared $(LIB) -o $(NAME) $^
	@echo "\n\033[39mCompilation done.\033[0m"
	@rm -f $(LINK)
	@ln -s $(NAME) $(LINK)

$(LIBNAME):
	@make -C $(LIBFT_PATH) -j8

%.o: %.c
	@$(CC) -fPIC -o $@ -c $< $(HEADER)
	@echo "\033[34m█\033[0m\c"

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)
	@rm -f $(LINK)

re: fclean all

.PHONY: all clean fclean re