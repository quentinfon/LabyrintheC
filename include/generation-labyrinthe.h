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


/**
 * @struct case_lab Struct to represent a cell of the maze
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

/**
 * @brief Function to display the current game (score and maze).
 * @param lab The maze
 * @param row The number of row of the maze
 * @param col The number of col of the maze
 * @param score The actual score to display
 */
void display_current_game(case_lab ** lab, int row, int col, int score);

/**
 * @brief Function to display the maze in the terminal.
 * @param lab The maze
 * @param row The number of row of the maze
 * @param col The number of col of the maze
 */
void display_labyrinthe(case_lab ** lab, int row, int col);

/**
 * @brief Function to display the value of the cells
 * @param lab The maze
 * @param row The number of row of the maze
 * @param col The number of col of the maze
 */
void display_test_labyrinthe(case_lab ** lab, int row, int col);

/**
 * @brief Function to initialise the labyrinth (allocate memory and set walls)
 * @param row The number of row of the maze
 * @param col The number of col of the maze
 * @return The initial maze
 */
case_lab ** init_labyrinthe(int row, int col);

/**
 * @brief Function to add a random amount of bonus and traps on a maze.
 * @param lab The maze to add traps and bonus on.
 * @param row The number of row of the maze
 * @param col The number of col of the maze
 */
void add_bonus_and_traps(case_lab ** lab, int row, int col);

/**
 * @brief Function to add a bonus or a trap
 * @param lab The maze
 * @param row The number of row of the maze
 * @param col The number of col of the maze
 * @param val If it's a trap or a bonus to add
 */
void add_a_rand_bonus_or_trap(case_lab ** lab, int row, int col, int val);

/**
 * @brief Function to allocate a row of the maze
 */
case_lab * alloue_cases_labyrinthe(int col);

/**
 * @brief Function to replace all the value of the maze cells by an other one
 * @param target The value to replace
 * @param new_value The new value
 */
void replace_val_cells_generation(case_lab ** lab, int row, int col, int target, int new_value);

/**
 * @brief Function to set the char corresponding to the value of the cell
 */
void rendering_labyrinthe(case_lab ** lab, int row, int col);

/**
 * @brief Function to check if the maze is completly genereted
 * @return 0 If it's not finish to generate, 1 if done
 */
int fin_de_generation(case_lab ** lab, int row, int col);

/**
 * @brief Function to remove a random wall of the maze (part of the maze generation)
 */
void remove_wall(case_lab ** lab, int row, int col);

/**
 * @brief Function that build the maze
 */
void generate_labyrinthe(case_lab ** lab, int row, int col);

/**
 * @brief Function that play a turn on a maze
 * @param direction The char (z,q,s,d) to know the direction
 * @param score The actual score to increment
 */
int play_turn(case_lab** lab, int row, int col, char direction, int * score);

/**
 * @brief Function to find the player position
 * @param[out] pos_x The x position of the player
 * @param[out] pos_y The y position of the player
 */
void player_position(int* pos_x, int* pos_y, case_lab ** lab, int row, int col);


#endif
