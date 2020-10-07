#include <stdio.h>
#include <mem.h>
#include <malloc.h>
#include <io.h>
#include "lab_ranking.h"


void display_scores(char* lab_name, int actual_score){

    printf("Scores sur le labyrinthe %s :\n", lab_name);

    int score_count = 0;
    int insert_new_score = 0;
    score_lab * ranking = read_rank_file(lab_name);

    for (int i = 0; i < 10; i++) {
        if (ranking[i].score != -1){

            printf(" - %d : %s \n", ranking[i].score, ranking[i].name);
            score_count ++;
            if (actual_score > ranking[i].score){
                insert_new_score = 1;
            }
        }
    }

    if (score_count == 0){
        printf("Aucun score pour ce labyrinthe \n");
    }

    /*Adding the new score*/
    if (insert_new_score == 1){
        add_score(ranking, actual_score);
        save_rank_file(lab_name, ranking);
    }

}

void add_score(score_lab * ranking, int score){

    int index_score = -1;
    for (int i = 9; i <= 0 ; i--) {

        if (ranking[i].score < score){
            index_score = i;
        }

    }

    /*If the score have to be insert*/
    if (index_score != -1){

        /*Get the user name*/
        char name[100];
        scanf("%[^\n]", name);

        for (int i = 9; i <= index_score ; i--) {

            if (i == index_score){
                ranking[i].score = score;
                ranking[i].name = name;
            } else{
                ranking[i].score = ranking[i-1].score;
                ranking[i].name = ranking[i-1].name;
            }

        }

    }

}

/*Return the rank array if there is no save return an empty score array*/
score_lab * read_rank_file(char* lab_name){
    FILE *fichier;

    /*location of the save file*/
    char * file_path = (char*) malloc(sizeof(lab_name) + sizeof(char) * 20);
    strcpy(file_path, "../scores/");
    strcat(file_path, lab_name);
    strcat(file_path, ".score");

    if( access( file_path, F_OK ) != -1 ) {

        fichier = fopen(file_path, "rb");


        score_lab * ranking = (score_lab *) malloc( 10 * sizeof(score_lab));
        fread(ranking, 10 * sizeof(score_lab) , 1, fichier);

        fclose(fichier);

        return ranking;

    } else {
        // file doesn't exist
        score_lab * new_ranking = (score_lab *) malloc( 10 * sizeof(score_lab));
        for (int i = 0; i < 10; i++) {
            new_ranking[i].score = -1;
            new_ranking[i].name = malloc(100*sizeof(char));
            new_ranking[i].name = "";
        }

        return new_ranking;
    }
}

void save_rank_file(char* lab_name, score_lab ranking[10]){
    FILE *fichier;

    /*location of the save file*/
    char * file_path = (char*) malloc(sizeof(lab_name) + sizeof(char) * 20);
    strcpy(file_path, "../scores/");
    strcat(file_path, lab_name);
    strcat(file_path, ".score");

    fichier = fopen (file_path, "wb");

    fwrite(ranking, sizeof(score_lab) * 10, 1, fichier);

    if(fwrite != 0)
        printf("Le labyrinthe a bien ete enregistre !\n");
    else
        printf("Erreur lors de l'enregistrement du labyrinthe !\n");

    /* close file */
    fclose (fichier);
}

