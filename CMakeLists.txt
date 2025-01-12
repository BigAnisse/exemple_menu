cmake_minimum_required(VERSION 3.29)
project(exemple_menu C)

set(CMAKE_C_STANDARD 11)

include_directories(exemple-menu)

add_executable(exemple_menu
    exemple-menu/jeu.c
    exemple-menu/jeu.h
    exemple-menu/main.c
    exemple-menu/menu.c
    exemple-menu/menu.h
    exemple-menu/plateau.c
    exemple-menu/plateau.h
    exemple-menu/pion.c
    exemple-menu/pion.h
    exemple-menu/mur.h
    exemple-menu/mur.c
        exemple-menu/constante.h
        exemple-menu/constante.c
)
