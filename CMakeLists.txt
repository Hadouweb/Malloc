cmake_minimum_required(VERSION 3.6)
project(malloc)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(libft)

set(SRCS
    main.c
    malloc.c
    debug.c
    alloc.c
    error.c
    get_tiny.c
    get_small.c
    get_large.c
    show_alloc.c
    util.c
    free.c
    )

set(HEADERS
        malloc.h
    )

add_executable(malloc ${SRCS} ${HEADERS})

target_link_libraries(malloc ft)