cmake_minimum_required(VERSION 3.6)
project(malloc)

set(CMAKE_CXX_STANDARD 11)

include_directories(includes)
add_subdirectory(libft)

set(SRCS
    srcs/main.c
    srcs/m_malloc.c
    srcs/m_debug.c
    srcs/m_region.c
    )

set(HEADERS
   includes/malloc.h
    )

add_executable(malloc ${SRCS} ${HEADERS})

target_link_libraries(malloc ft)