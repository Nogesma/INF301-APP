cmake_minimum_required(VERSION 3.12)
project(Client_c___crypteSeq C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Client_c___crypteSeq
        client-interactif.c
        client-introduction.c
        client-tutoriel.c
        client.c
        client.h
        crypt.c
        crypt.h)
