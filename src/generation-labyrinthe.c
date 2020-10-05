#include "generation-labyrinthe.h"


void display_labyrinthe(case_lab ** lab, int row, int col){

    system("@cls||clear");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            printf("%c", lab[i][j].affichage);

        }
        printf("\n");
    }

}

void display_test_labyrinthe(case_lab ** lab, int row, int col){

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", lab[i][j].val);
        }
        printf("\n");
    }

}

/*Allocate a row of the labyrinthe in memory*/
case_lab * alloue_cases_labyrinthe(int col){
    case_lab *row_of_cases = (case_lab*) malloc(col * sizeof(case_lab));
    for (int i = 0; i < col; i++) {
        row_of_cases[i].affichage = '#';
        row_of_cases[i].val = 0;
    }
    return row_of_cases;
}
/*Allocate the labyrinthe in memory*/
case_lab ** init_labyrinthe(int row, int col){
    case_lab **lab = (case_lab**) malloc(row * sizeof(case_lab*));
    for (int i = 0; i < row; i++) {
        lab[i] = alloue_cases_labyrinthe(col);
    }
    return lab;
}

void replace_val_cells_generation(case_lab ** lab, int row, int col, int target, int new_value){

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (lab[i][j].val == target){
                lab[i][j].val = new_value;
            }
        }
    }

}


/*Convert int map into a clean char map*/
void rendering_labyrinthe(case_lab ** lab, int row, int col){

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            if (lab[i][j].val == -1){
                lab[i][j].affichage =  '#';
            } else if (lab[i][j].val == 1){
                lab[i][j].affichage = 'o';
            }else{
                lab[i][j].affichage = ' ';
            }
        }
    }

}

int fin_de_generation(case_lab **lab, int row, int col){

    int num = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){

            if (lab[i][j].val != -1) {

                if (num == 0){
                    num = lab[i][j].val;
                }else if (num != lab[i][j].val){
                    return 0;
                }

            }

        }
    }

    return 1;
}

void remove_wall(case_lab ** lab, int row, int col){

    /*Count the number of walls*/
    int walls_count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (lab[i][j].val == -1){
                walls_count ++;
            }
        }
    }

    /*Sort a rand wall and try to see if it can be break*/

    int wall_number = 0;
    int rand_wall = rand() % walls_count;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            /*Removable walls*/
            if (lab[i][j].val == -1){

                if (wall_number == rand_wall){

                    /*Lower and Upper cells*/
                    if (i + 1 < row && i - 1 >= 0 && lab[i+1][j].val != -1 && lab[i-1][j].val != -1 && lab[i+1][j].val != lab[i-1][j].val){
                        /*set the new link cells values*/
                        replace_val_cells_generation(lab, row, col, lab[i+1][j].val, lab[i-1][j].val);
                        /*Remove the wall between the cells*/
                        lab[i][j].val = lab[i-1][j].val;
                    }
                    /*Right and Left cells*/
                    if (j + 1 < col && j - 1 >= 0 && lab[i][j+1].val != -1 && lab[i][j-1].val != -1 && lab[i][j+1].val != lab[i][j-1].val){
                        /*set the new link cells values*/
                        replace_val_cells_generation(lab, row, col, lab[i][j+1].val, lab[i][j-1].val);
                        /*Remove the wall between the cells*/
                        lab[i][j].val = lab[i][j-1].val;
                    }

                }

                wall_number ++;

            }
        }
    }



}

void generate_labyrinthe(case_lab ** lab, int row, int col){


    /*Num of the case used for the generation*/
    int count_case = 1;

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++){
            /*If first or last row*/
            if (i == 0 || i == row-1){
                lab[i][j].val = -1;
            }else {
                if (j == 0 || j == col - 1) {
                    lab[i][j].val = -1;
                } else {
                    /*initial grid wall for the generation*/
                    if (i % 2 == 0 || j % 2 == 0) {
                        lab[i][j].val = -1;
                    } else {
                        lab[i][j].val = count_case;
                        count_case++;
                    }
                }
            }
        }

    }

    /*Generate the labyrinth path*/
    while (!fin_de_generation(lab, row, col)){

        remove_wall(lab, row, col);

    }

    /*Putting all the val to 0*/
    replace_val_cells_generation(lab, row, col, lab[1][1].val, 0);

    /*Enter and exit*/

    /*Player at the enter*/
    lab[1][0].val = 1;
    lab[row - 2][col - 1].val = 0;

    /*Attribue a char to each case depending of the value*/
    rendering_labyrinthe(lab, row, col);

}

void player_position(int* pos_x, int* pos_y, case_lab ** lab, int row, int col){

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if (lab[i][j].val == 1){
                *pos_x = j;
                *pos_y = i;
                return;
            }

        }
    }

}

/* return if the player is on the last cell of the labyrinth */
int play_turn(case_lab** lab, int row, int col, char direction){

    int x = 0;
    int y = 0;
    /*
     * y = -1 : upper / 1 lower
     * x = -1 : left / 1 right
     * */

    if (direction == 'Z' || direction == 'z'){
        y = -1;
    }
    else if (direction == 'Q' || direction == 'q'){
        x = -1;
    }
    else if (direction == 'S' || direction == 's'){
        y = 1;
    }
    else if (direction == 'D' || direction == 'd'){
        x = 1;
    }

    int pos_x_player, pos_y_player;

    player_position(&pos_x_player, &pos_y_player, lab, row, col);

    if ( y != 0 && pos_y_player + y >= 0 && pos_y_player + y < row && lab[pos_y_player+y][pos_x_player].val != -1){
        lab[pos_y_player][pos_x_player].val = 0;
        lab[pos_y_player+y][pos_x_player].val = 1;
    } else if ( x != 0 && pos_x_player + x >= 0 && pos_x_player + x < col && lab[pos_y_player][pos_x_player+x].val != -1){
        lab[pos_y_player][pos_x_player].val = 0;
        lab[pos_y_player][pos_x_player+x].val = 1;
    }

    rendering_labyrinthe(lab, row, col);

    if (pos_x_player == col-1 && pos_y_player == row-2){
        return 1;
    }else{
        return 0;
    }

}
