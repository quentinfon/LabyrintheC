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
 * Testing the functions the labyrinth project
 * @author  Quentin Fontaine
 * @version 1.0
 * @date    14/10/2020
 */

#include "minunit.h"
#include "../generation-labyrinthe.h"
#include "../lab_ranking.h"
#include "../lab_saving.h"


void test_setup(void) {
}

void test_teardown(void) {

}

MU_TEST(test_init_labyrinth) {

    case_lab ** lab = init_labyrinthe(9, 23);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 23; j ++){

            if(lab[i][j].val != 0){
                mu_fail("Lab not initialised with 0.");
            }

        }
    }

}


MU_TEST(test_size_labyrinth){

    case_lab ** lab = init_labyrinthe(9, 23);
    int count = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 23; j++){
            /*Count the cells defined*/
            if(lab[i][j].val > -10){
                count++;
            }
        }
    }

    mu_assert(count == 9*23, "Cells missing in the labyrinth");

}

MU_TEST(check_bonus_traps){

    case_lab ** lab = init_labyrinthe(9, 23);
    generate_labyrinthe(lab, 9, 23);

    int count_bonus = 0;
    int count_traps = 0;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 23; j++){
            /*Bonus*/
            if(lab[i][j].val == 2){
                count_bonus++;
            }
            /*Traps*/
            if(lab[i][j].val == 3){
                count_traps++;
            }
        }
    }

    mu_assert(count_traps != 0, "There is no traps");
    mu_assert(count_bonus != 0, "There is no bonus");
}

MU_TEST(test_remove_wall){

    case_lab ** lab = init_labyrinthe(9, 23);
    generate_labyrinthe(lab, 9, 23);

    int count_wall_ini = 0;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 23; j++){
            /*Walls*/
            if(lab[i][j].val == -1){
                count_wall_ini++;
            }
        }
    }

    remove_wall(lab, 9, 23);

    int count_wall_end = 0;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 23; j++){
            /*Walls*/
            if(lab[i][j].val == -1){
                count_wall_end++;
            }
        }
    }

    mu_assert(count_wall_ini -1 == count_wall_end, "Error removing wall");
}


MU_TEST(test_player_position){

    case_lab ** lab = init_labyrinthe(9, 23);
    generate_labyrinthe(lab, 9, 23);

    int pos_x, pos_y;

    lab[1][0].val = 1;
    player_position(&pos_x, &pos_y, lab, 9, 23);
    mu_assert(lab[pos_y][pos_x].val == 1, "Wrong player position finding");
    lab[1][0].val = 0;

    lab[7][22].val = 1;
    player_position(&pos_x, &pos_y, lab, 9, 23);
    mu_assert(lab[pos_y][pos_x].val == 1, "Wrong player position finding");
    lab[7][22].val = 0;
}


MU_TEST_SUITE(test_suite) {
        MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
        MU_RUN_TEST(test_init_labyrinth);
        MU_RUN_TEST(test_size_labyrinth);
        MU_RUN_TEST(check_bonus_traps);
        MU_RUN_TEST(test_remove_wall);
        MU_RUN_TEST(test_player_position);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
