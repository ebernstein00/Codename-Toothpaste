#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include "items.h"
#include "characters.h"
#include "gameflow.h"

int main() {
    /* struct being *mage = create_mage(1); */
    /* printf("\n ----- NEW MAGE ----- \n"); */
    /* print_being(mage); */

    /* // Adding health potion to inventory */
    /* struct item *healthpot = create_health_potion(); */
    /* struct item *healthpot2 = create_health_potion();     */
    /* struct item *strengthpot = create_strength_potion(); */
    /* struct item *strengthpot2 = create_strength_potion();     */
    /* struct item *rigid_ironsword = create_rigidity_iron_sword(); */
    /* struct item *ironarmor = create_iron_armor(); */
    /* add_item(mage, healthpot); */
    /* add_item(mage, strengthpot); */
    /* add_item(mage, healthpot2); */
    /* add_item(mage, strengthpot2); */
    /* add_item(mage, rigid_ironsword); */
    /* add_item(mage, ironarmor); */
    /* printf("\n ----- WITH ITEMS ----- \n"); */
    /* print_being(mage); */
    
    /* free_being(mage); */

    struct game *game = newgame();
    struct being *p1 = create_mage(1);
    struct being *p2 = create_knight(1);
    struct being *m1 = create_slime(1);
    struct being *m2 = create_zombie(1);

    game->player1 = p1;
    game->player2 = p2;
    game->monster1 = m1;
    game->monster2 = m2;
    printgame( game );
    freegame ( game );

    int s;
    s = playerturn( game->player1, game );
    if (s == 1) {
      s = playerturn ( game->player1, game );
    }
    playerturn( game->player1, game );
    return 0;
}
