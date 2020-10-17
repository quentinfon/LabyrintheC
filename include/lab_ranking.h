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
 * Functions to manage the ranking of players
 * @author  Quentin Fontaine
 * @version 1.0
 * @date    10/2020
 */

#ifndef LAB_RANKING_H
#define LAB_RANKING_H

/**
 * @struct score_lab Struct of a score to make a ranking array
 */
typedef struct score_lab
{
    char name[100];
    int score;

} score_lab;


/**
 * @brief Function that return the rank array if there is no save return an empty score array
 * @param lab_name The name of the maze to load the ranking
 * */
score_lab * read_rank_file(char* lab_name);

/**
 * @brief Functions that save the ranking into a binary file in the scores directory
 * @param[in] lab_nam Name of the maze to save the score file
 * @param[in] ranking The ranking array to save in the file
 * */
void save_rank_file(char* lab_name, score_lab ranking[10]);

/**
 *  @brief Function that display the scores of a maze
 *  @param lab_name Name of the maze to display the ranking
 *  @param actual_score Score done by the player
 * */
void display_scores(char* lab_name, int actual_score);

/**
 * @brief Function that check the score and if needed insert it in the top 10
 * @param ranking The ranking array to check and add the score if needed
 * @param score The score done by the player
 * */
int add_score(score_lab * ranking, int score);

#endif
