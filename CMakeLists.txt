cmake_minimum_required(VERSION 3.6)
project(malloc)

set(CMAKE_CXX_STANDARD 11)

include_directories(includes)
add_subdirectory(libft)

set(SRCS
    main.c
    srcs/m_malloc.c
    srcs/m_debug.c
    srcs/m_alloc.c
    srcs/m_error.c
    srcs/m_get_tiny.c
    srcs/m_get_small.c
    srcs/m_get_large.c
    srcs/m_show_alloc.c
    )

set(HEADERS
   includes/malloc.h
    )

add_executable(malloc ${SRCS} ${HEADERS})

target_link_libraries(malloc ft)