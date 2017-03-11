cmake_minimum_required(VERSION 3.6)
project(malloc)

set(CMAKE_CXX_STANDARD 11)

include_directories(includes)
add_subdirectory(libft)

set(SRCS
    srcs/malloc.c
    srcs/debug.c
    srcs/alloc_tiny.c
    srcs/alloc_small.c
    srcs/alloc_large.c
    srcs/error.c
    srcs/get_tiny.c
    srcs/get_small.c
    srcs/get_large.c
    srcs/show_alloc.c
    srcs/util.c
    srcs/free.c
    srcs/find_ptr.c
    srcs/realloc.c
    srcs/call_unsafe.c
    )

set(HEADERS includes/malloc.h)

add_library(ft_malloc ${SRCS} ${HEADERS})

target_include_directories(ft_malloc PUBLIC ./includes)