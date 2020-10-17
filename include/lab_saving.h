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

/**
 * @brief Function that check if the file extension is .cfd
 * @param dir the file
 * @return 1 if it's .cfg else 0
 */
int is_cfg_format(struct dirent *dir);

/**
 * @brief Function that check if a file is in the save directory
 * @param file_name The name of the file to check
 * @return 1 if it's in the list else 0
 */
int is_in_file_list(char * file_name);

/**
 * @brief Function that display the list of maze saved on the save directory
 */
void display_save_list();

/**
 * @brief Function that check if the input is a correct name
 * @return 1 if it's correct else 0
 */
int is_valid_name(char * file_name);

/**
 * @brief Function that save the lab into a binary file
 * @param nom The name of the maze to save
 */
void save_labyrinthe(case_lab **lab, int row, int col, char nom[]);

/**
 * @brief Function that load a maze from a binary file
 * @param file_location The location of the file to load
 * @param[out] row To set the number of row with the file
 * @param[out] col To set the number of col with the file
 * @return The maze
 */
case_lab ** load_labyrinthe_from_file(char file_location[], int *row, int *col);

#endif
