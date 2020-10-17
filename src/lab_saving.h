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
 * Functions to save a labyrinth in a binary file
 * @author  Quentin Fontaine
 * @version 1.0
 * @date    10/2020
 */

#ifndef LAB_SAVING_H
#define LAB_SAVING_H

#include "generation-labyrinthe.h"
#include <dirent.h>

int is_cfg_format(struct dirent *dir);

int is_in_file_list(char * file_name);

void display_save_list();

int is_valid_name(char * file_name);

void save_labyrinthe(case_lab **lab, int row, int col, char nom[]);

case_lab ** load_labyrinthe_from_file(char file_location[], int *row, int *col);

#endif
