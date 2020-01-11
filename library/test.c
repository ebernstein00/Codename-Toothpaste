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
    struct being *knight = create_knight(1);
    printf("\n ----- NEW KNIGHT ----- \n");
    print_being(knight);

    // Adding health potion to inventory
    struct item *healthpot = create_health_potion();
    add_item(knight, healthpot);
    printf("\n ----- WITH HEALTHPOT ----- \n");
    print_being(knight);

    // Adding sword to inventory
    free_being(knight);
}
