cmake_minimum_required(VERSION 3.20)
project(exemple_menu C)

set(CMAKE_C_STANDARD 11)

add_executable(exemple_menu
        main.c
        jeu.c
        jeu.h
        plateau.c
        plateau.h
        menu.c
        menu.h
        mur.c
        mur.h
        constante.c
        constante.h
)
