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

/*
 * Struct of a score to make a ranking array
 */
typedef struct score_lab
{
    char name[100];
    int score;

} score_lab;

score_lab * read_rank_file(char* lab_name);

void save_rank_file(char* lab_name, score_lab ranking[10]);

void display_scores(char* lab_name, int actual_score);

int add_score(score_lab * ranking, int score);

#endif
