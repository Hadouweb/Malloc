cmake_minimum_required(VERSION 3.6)
project(malloc)

set(CMAKE_CXX_STANDARD 11)

include_directories(includes)
add_subdirectory(libft)

set(SRCS
    srcs/malloc.c
    srcs/alloc.c
    srcs/error.c
    srcs/find_ptr.c
    srcs/show_alloc.c
    srcs/util.c
    srcs/free.c
    srcs/find_region.c
    srcs/realloc.c
    srcs/call_unsafe.c
    srcs/show_alloc_mem_ex.c
    srcs/show_ptr.c
    srcs/unmap.c
    )

set(HEADERS includes/malloc.h)

add_library(ft_malloc ${SRCS} ${HEADERS})

target_include_directories(ft_malloc PUBLIC ./includes)