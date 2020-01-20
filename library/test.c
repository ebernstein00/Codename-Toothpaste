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

    struct items *itempool[NUM_ITEMS];
    item_pool[0] = create_wood_sword();
    item_pool[1] = create_iron_sword();
    item_pool[2] = create_steel_sword();
    item_pool[3] = create_armoring_wooden_sword();
    item_pool[4] = create_armoring_iron_sword();
    item_pool[5] = create_armoring_steel_sword();
    item_pool[6] = create_rigidity_wooden_sword();
    item_pool[7] = create_rigidity_iron_sword();
    item_pool[8] = create_rigidity_steel_sword();
    item_pool[9] = create_leather_armor();
    item_pool[10] = create_iron_armor();
    item_pool[11] = create_steel_armor();
    item_pool[12] = create_mithril_armor();
    item_pool[13] = create_rigidity_leather_armor();
    item_pool[14] = create_rigidity_iron_armor();
    item_pool[15] = create_rigidity_steel_armor();
    item_pool[16] = create_rigidity_mithril_armor();
    item_pool[17] = create_strength_leather_armor();
    item_pool[18] = create_strength_iron_armor();
    item_pool[19] = create_strength_steel_armor();
    item_pool[20] = create_strength_mithril_armor();
    item_pool[21] = create_health_potion();
    item_pool[22] = create_health_potion();
    item_pool[23] = create_health_potion();
    item_pool[24] = create_health_potion();
    item_pool[25] = create_health_potion();
    item_pool[26] = create_health_potion();
    item_pool[27] = create_health_potion();
    item_pool[28] = create_health_potion();
    item_pool[29] = create_health_potion();
    item_pool[30] = create_strength_potion();
    item_pool[31] = create_strength_potion();
    item_pool[32] = create_strength_potion();
    item_pool[33] = create_strength_potion();
    

    struct game *game = newgame();
    
    /* struct being *p1 = create_mage(1); */
    /* struct being *p2 = create_knight(1); */
    /* struct being *m1 = create_dedede(1); */
    /* struct being *m2 = create_waddledee(1); */

    game->player1 = create_mage(1);
    game->player2 = create_knight(1);
    game->monster1 = create_dedede(1);
    game->monster2 = create_waddledee(1);
    struct item *woodsword = create_wood_sword();
    add_item( game->player1, woodsword );
    printgame( game );



    playerturn( game->player1, game );
    garbage_collector( game );
    printgame( game );

    monsterturn( game->monster1, game );
    printgame( game );

    freegame ( game );
    return 0;
}
