#ifndef LAB_SAVING_H
#define LAB_SAVING_H

#include "main.h"
#include "generation-labyrinthe.h"
#include <dirent.h>
#include <mem.h>

int is_cfg_format(struct dirent *dir);

int is_in_file_list(char * file_name);

void display_save_list();

int is_valid_name(char * file_name);

void save_labyrinthe(case_lab **lab, int row, int col, char nom[]);

case_lab ** load_labyrinthe_from_file(char file_location[], int *row, int *col);

#endif
