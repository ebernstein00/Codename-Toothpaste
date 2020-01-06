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

struct being {
    int hp;
    int attack;
    int defense;
    int level;
    char *status[3];
    char *ability;
};

/*---------- PROTAGONISTS ----------*/
struct mage {
    // Default Mage config, at lv 1
    struct being base;
};

struct knight {
    // Default Knight config, at lv 1
    struct being base;
};


struct rogue {
    // Default Rogue config, at lv 1
    struct being base;
};

/*---------- MONSTERS ---------- */

struct slime {
    // Default Slime config, at lv 1
    struct being base;
};

struct zombie {
    // Default zombie config, at lv 1
    struct being base;
};

struct bat {
    // Default Rogue config, at lv 1
    struct being base;
};


// ---------- FUNCTIONS ----------
struct being * create_mage( int level ) {
    struct being *being_pointer = (struct node *)calloc(1, sizeof(struct being));
    char **status_array = (char **)calloc(3, sizeof(char [128]));
    status_array[0] = "";
    status_array[1] = "";
    status_array[2] = "";
    
    being_pointer->base.hp = 50;
    being_pointer->base.attack = 20;
    being_pointer->base.defense = 5;
    being_pointer->base.level = level;
    being_pointer->base.status = status_array;
    being_pointer->base.ability = "burned";

    return being_pointer;
}

struct being * create_knight( int level ) {
    struct being *being_pointer = (struct node *)calloc(1, sizeof(struct being));
    char **status_array = (char **)calloc(3, sizeof(char [128]));
    status_array[0] = "";
    status_array[1] = "";
    status_array[2] = "";
    
    being_pointer->base.hp = 75;
    being_pointer->base.attack = 10;
    being_pointer->base.defense = 10;
    being_pointer->base.level = level;
    being_pointer->base.status = status_array;
    being_pointer->base.ability = "bleeding";

    return being_pointer;

}

struct being * create_rogue( int level ) {
    struct being *being_pointer = (struct node *)calloc(1, sizeof(struct being));
    char **status_array = (char **)calloc(3, sizeof(char [128]));
    status_array[0] = "";
    status_array[1] = "";
    status_array[2] = "";
    
    being_pointer->base.hp = 100;
    being_pointer->base.attack = 5;
    being_pointer->base.defense = 15;
    being_pointer->base.level = level;
    being_pointer->base.status = status_array;
    being_pointer->base.ability = "poisoned";

    return being_pointer;

}

struct being * create_slime( int level ) {
    struct being *being_pointer = (struct node *)calloc(1, sizeof(struct being));
    char **status_array = (char **)calloc(3, sizeof(char [128]));
    status_array[0] = "";
    status_array[1] = "";
    status_array[2] = "";
    
    being_pointer->base.hp = 100;
    being_pointer->base.attack = 10;
    being_pointer->base.defense = 5;
    being_pointer->base.level = level;
    being_pointer->base.status = status_array;
    being_pointer->base.ability = "sticky";

    return being_pointer;

}

struct being * create_zombie( int level ) {
    struct being *being_pointer = (struct node *)calloc(1, sizeof(struct being));
    char **status_array = (char **)calloc(3, sizeof(char [128]));
    status_array[0] = "";
    status_array[1] = "";
    status_array[2] = "";
    
    being_pointer->base.hp = 75;
    being_pointer->base.attack = 5;
    being_pointer->base.defense = 15;
    being_pointer->base.level = level;
    being_pointer->base.status = status_array;
    being_pointer->base.ability = "lazy";

    return being_pointer;

}

struct being * create_bat( int level ) {
    struct being *being_pointer = (struct node *)calloc(1, sizeof(struct being));
    char **status_array = (char **)calloc(3, sizeof(char [128]));
    status_array[0] = "";
    status_array[1] = "";
    status_array[2] = "";
    
    being_pointer->base.hp = 50;
    being_pointer->base.attack = 15;
    being_pointer->base.defense = 5;
    being_pointer->base.level = level;
    being_pointer->base.status = status_array;
    being_pointer->base.ability = "confused";

    return being_pointer;

}

struct being * free_being( struct being *pointer ) {
    free(pointer->base.status);
    free(pointer);
}


// ---------- MAIN (TESTING FUNCTION) ----------
int main() {
    struct being *knight = create_knight(1);
    printf("HP: [%d]\n", knight->base.hp);
    printf("Attack: [%d]\n", knight->base.attack);
    printf("Defense: [%d]\n", knight->base.defense);
    printf("Level: [%d]\n", knight->base.level);
    printf("Status:\n");
    printf("\t[%s]\n", knight->base.status[0]);
    printf("\t[%s]\n", knight->base.status[1]);
    printf("\t[%s]\n", knight->base.status[2]);
    printf("Ability: [%s]\n", knight->base.ability);
}
