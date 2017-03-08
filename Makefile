CC = gcc -Werror -Wextra -Wall -g

SRCPATH = ./srcs
INCPATH = ./includes

LIBFTPATH = ./libft

HEADER = -I $(LIBFTPATH)/includes -I $(INCPATH)

LIB = -L$(LIBFTPATH) -lft
LIBNAME = $(LIBFTPATH)/libft.a

SRC = 	$(SRCPATH)/main.c\
        $(SRCPATH)/m_malloc.c\
        $(SRCPATH)/m_debug.c\
        $(SRCPATH)/m_alloc.c\
        $(SRCPATH)/m_error.c\
        $(SRCPATH)/m_get_tiny.c\
        $(SRCPATH)/m_get_small.c\
        $(SRCPATH)/m_get_large.c\
        $(SRCPATH)/m_show_alloc.c\

OBJ = $(SRC:.c=.o)

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINK = libft_malloc.so

all: $(NAME)

$(NAME): $(LIBNAME) $(OBJ)
	@$(CC) -o $@ $(LIB) $^
	@echo "\n\033[39mCompilation done.\033[0m"
	@rm -f $(LINK)
	@ln -s $(NAME) $(LINK)

$(LIBNAME):
	@make -C $(LIBFTPATH) -j8

%.o: %.c
	@$(CC) -o $@ -c $< $(HEADER)
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