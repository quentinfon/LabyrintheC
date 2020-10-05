#ifndef MENU_H
#define MENU_H

#include "main.h"
#include "generation-labyrinthe.h"
#include "lab_saving.h"
#include <conio.h>
#include <stdio.h>

void create_labyrinthe(case_lab ** lab);

void load_labyrinthe(case_lab ** lab);

void play(case_lab ** lab, int row, int col);

void menu(case_lab ** lab, int row, int col);

#endif
