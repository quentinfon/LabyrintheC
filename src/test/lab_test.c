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

MU_TEST(test_init_labyrinthe) {

    case_lab ** lab = init_labyrinthe(9, 23);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 23; j ++){

            if(lab[i][j].val != 0){
                mu_fail("Lab not initialised with 0.");
            }

        }
    }

}

MU_TEST_SUITE(test_suite) {
        MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
        MU_RUN_TEST(test_init_labyrinthe);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
