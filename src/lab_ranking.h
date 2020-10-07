
#ifndef LAB_RANKING_H
#define LAB_RANKING_H

typedef struct score_lab
{
    char name[100];
    int score;

} score_lab;

score_lab * read_rank_file(char* lab_name);

void save_rank_file(char* lab_name, score_lab ranking[10]);

void display_scores(char* lab_name, int actual_score);

void add_score(score_lab * ranking, int score);

#endif
