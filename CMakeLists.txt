cmake_minimum_required(VERSION 3.17)
project(labyrinthe C)

set(CMAKE_C_STANDARD 99)

add_executable(labyrinthe src/main.c src/generation-labyrinthe.c include/generation-labyrinthe.h src/menu.c include/menu.h src/lab_saving.c include/lab_saving.h src/lab_ranking.c include/lab_ranking.h)

add_executable(test src/generation-labyrinthe.c include/generation-labyrinthe.h src/lab_saving.c include/lab_saving.h src/lab_ranking.c include/lab_ranking.h src/test/lab_test.c)
