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
 * Main file to execute the game
 * @author  Quentin Fontaine
 * @version 1.0
 * @date    10/2020
 */

#include <stdlib.h>
#include <time.h>
#include "../include/generation-labyrinthe.h"
#include "../include/menu.h"

int main() {

    srand(time(NULL));

    case_lab ** lab = NULL;

    menu(lab, 0, 0, "");

    return 0;
}
