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
#include "characters.h

int attack(struct being * attacker, struct being * target){
    target->hp = target->hp - (attacker->attack - target->defense);
    return 0;
}

int use_item(struct being * user, int item_index){
    if (strcmp(user->backpack[item_index]->name, "Health Potion") ||
        strcmp(user->backpack[item_index]->name, "Strength Potion")) == 0){
        user->hp += user->backpack[item_index]->hp_buff;
        user->attack += user->backpack[item_index]->attack_buff;
    }
    remove_item(user, item_index);
    return 0;
}

int guard_start(struct being * user){
    target->defense += 20;
    return 0;
}

int guard_end(struct being * user){
    target->defense -= 20;
    return 0;
}
