#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include "items.h"
#include "characters.h"
#include "gameflow.h"

#define CONSUM_TYPE 1;
#define SWORD_TYPE 2;
#define ARMOR_TYPE 3;
#define NUM_ITEMS 34;

int main() {
    srand(time(NULL));

    struct game *game = newgame();
    game->player1 = create_mage(1);
    game->player2 = create_knight(1);
    game->monster1 = create_dedede(1);
    game->monster2 = create_waddledee(1);
    /* struct item *woodsword = create_wood_sword(); */
    /* add_item( game->player1, woodsword ); */
    printgame(game);
    playerturn( game->player1, game );
    garbage_collector( game );
    printgame( game );

    /* monsterturn( game->monster1, game ); */
    /* printgame( game ); */

    freegame ( game );

    return 0;
}
