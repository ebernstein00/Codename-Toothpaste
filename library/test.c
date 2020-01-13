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

int main() {
  struct being *mage = create_mage(1);
    printf("\n ----- NEW MAGE ----- \n");
    print_being(mage);

    // Adding health potion to inventory
    struct item *healthpot = create_health_potion();
    struct item *healthpot2 = create_health_potion();    
    struct item *strengthpot = create_strength_potion();
    struct item *strengthpot2 = create_strength_potion();    
    struct item *rigid_ironsword = create_rigidity_iron_sword();
    print_item(rigid_ironsword);
    struct item *ironarmor = create_iron_armor();
    add_item(mage, healthpot);
    add_item(mage, strengthpot);
    add_item(mage, healthpot2);
    add_item(mage, strengthpot2);
    add_item(mage, rigid_ironsword);
    add_item(mage, ironarmor);
    printf("\n ----- WITH ITEMS ----- \n");
    print_being(mage);

    // Adding sword to inventory
    free_being(mage);
}
