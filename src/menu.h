/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students. No portion of this
 * document may be reproduced, copied or revised without written
 * permission of the authors.
 */

/*
 * Functions to manage the menu of the game
 * @author  Quentin Fontaine
 * @version 1.0
 * @date    10/2020
 */

#ifndef MENU_H
#define MENU_H

#include "generation-labyrinthe.h"

void create_labyrinthe(case_lab ** lab);

void load_labyrinthe(case_lab ** lab);

void play(case_lab ** lab, int row, int col, char* lab_name);

void menu(case_lab ** lab, int row, int col, char* lab_name);

#endif
