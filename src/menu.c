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

#include "../include/menu.h"
#include "../include/lab_ranking.h"
#include "../include/lab_saving.h"
#include <conio.h>
#include <stdio.h>

void clear_buffer(){
    while ((getchar()) != '\n');
}

void create_labyrinthe(case_lab ** lab){

    int row = 0;
    int col = 0;
    char name[100];

    while (row <= 3 || row%2 == 0){
        printf("Nombre de lignes (impaire) du labyrinthe : \n");
        scanf("%d", &row);
        clear_buffer();
    }

    while (col <= 3 || col%2 == 0){
        printf("Nombre de colonnes (impaire) du labyrinthe : \n");
        scanf("%d", &col);
        clear_buffer();
    }

    do {
        printf("Nom du labyrinthe : \n");
        scanf("%[^\n]", name);
        clear_buffer();
    }while (is_valid_name(name) == 0);

    lab = init_labyrinthe(row, col);

    generate_labyrinthe(lab, row, col);
    display_labyrinthe(lab, row, col);

    /*Saving the generated labyrinthe*/
    save_labyrinthe(lab, row, col, name);

    menu(lab, row, col, name);
}


void load_labyrinthe(case_lab ** lab){

    int row;
    int col;

    char file_name[100];

    /*Choosing the file to load*/
    do {
        printf("Liste des sauvegardes : \n");
        display_save_list();
        printf("q : quitter\n");

        printf("Quelle sauvegarde voulez vous charger : \n");
        scanf("%s", file_name);
        clear_buffer();

        /*Option to quit the loading page*/
        if (file_name[0] == 'q' && file_name[1] == '\0'){
            break;
        }
    }while (is_in_file_list(file_name) == 0);

    if ((file_name[0] == 'q' && file_name[1] == '\0')){

    }else{
        lab = load_labyrinthe_from_file(file_name, &row, &col);

        display_labyrinthe(lab, row, col);
    }

    menu(lab, row, col, file_name);
}

void play(case_lab ** lab, int row, int col, char* lab_name){

    if (lab == NULL){
        printf("Aucun labyrinthe charge\n");
        menu(lab, row, col, "");
    }else{
        char direction;
        int end = 0;
        int score = 0;

        do{

            display_current_game(lab, row, col, score);

            direction = getch();
            //scanf("%c", &direction);
            //clear_buffer();
            if (direction == 'z' || direction == 'q' || direction == 's' || direction == 'd'){
                end = play_turn(lab, row, col, direction, &score);

            }
        }while (end != 1);

        display_scores(lab_name, score);

    }
    free_labyrinthe(lab, row, col);

    /*Reset the lab in memory*/
    menu(NULL, 0, 0, "");

}

void menu(case_lab ** lab, int row, int col, char* lab_name){

    printf("##### LABYRINTHE #####\n");

    int choix = 0;

    while (choix <= 0 || choix > 4){
        printf("Que voulez-vous faire :\n");
        printf("1 : Creer un labyrinthe\n");
        printf("2 : Charger un labyrinthe\n");
        printf("3 : Jouer\n");
        printf("4 : Quitter\n");

        scanf("%d", &choix);
        clear_buffer();
    }

    switch (choix) {

        case 1:
            create_labyrinthe(lab);
            break;
        case 2:
            load_labyrinthe(lab);
            break;
        case 3:
            play(lab, row, col, lab_name);
            break;
        default:
            break;
    }

}
