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
 * Functions to generate a labyrinth
 * @author  Quentin Fontaine
 * @version 1.0
 * @date    10/2020
 */

#ifndef GENERATION_LABYRINTHE_H
#define GENERATION_LABYRINTHE_H


/*
 * Vals :
 * -1 : wall
 *  0 : path
 *  1 : player
 *  2 : bonus
 *  3 : trap
 * */
typedef struct case_lab
{
    int val;
    char affichage;

} case_lab;

void display_current_game(case_lab ** lab, int row, int col, int score);

void display_labyrinthe(case_lab ** lab, int row, int col);

void display_test_labyrinthe(case_lab ** lab, int row, int col);

case_lab ** init_labyrinthe(int row, int col);

void add_bonus_and_traps(case_lab ** lab, int row, int col);

void add_a_rand_bonus_or_trap(case_lab ** lab, int row, int col, int val);

case_lab * alloue_cases_labyrinthe(int col);

void replace_val_cells_generation(case_lab ** lab, int row, int col, int target, int new_value);

void rendering_labyrinthe(case_lab ** lab, int row, int col);

int fin_de_generation(case_lab ** lab, int row, int col);

void remove_wall(case_lab ** lab, int row, int col);

void generate_labyrinthe(case_lab ** lab, int row, int col);

int play_turn(case_lab** lab, int row, int col, char direction, int * score);


#endif
