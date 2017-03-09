CC = gcc
FLAG = -Werror -Wextra -Wall -g
LIBFTPATH = ./libft

HEADER = -I $(LIBFTPATH)/includes

LIB = -L$(LIBFTPATH) -lft
LIBNAME = $(LIBFTPATH)/libft.a

SRC =   malloc.c\
        debug.c\
        alloc.c\
        error.c\
        get_tiny.c\
        get_small.c\
        get_large.c\
        show_alloc.c\
        util.c\
        free.c\

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
	@make -C $(LIBFTPATH) -j8

%.o: %.c
	@$(CC) -fPIC -o $@ -c $< $(HEADER)
	@echo "\033[34m█\033[0m\c"

clean:
	@make -C $(LIBFTPATH) clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C $(LIBFTPATH) fclean
	@rm -rf $(NAME)
	@rm -f $(LINK)

re: fclean all

.PHONY: all clean fclean re