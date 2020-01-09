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
    char *type;
    int hp;
    int attack;
    int defense;
    int level;
    char **status;
    char *ability;
};

/*---------- PROTAGONISTS ----------*/


struct being * create_mage( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    char **status_array = (char **)calloc(3, sizeof(char [25]));
    status_array[0] = "";
    status_array[1] = "";
    status_array[2] = "";

    being_pointer->type = "mage";
    being_pointer->hp = 50;
    being_pointer->attack = 20;
    being_pointer->defense = 5;
    being_pointer->level = level;
    being_pointer->status = status_array;
    being_pointer->ability = "burned";

    return being_pointer;
}

struct being * create_knight( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    char **status_array = (char **)calloc(3, sizeof(char [25]));
    status_array[0] = "";
    status_array[1] = "";
    status_array[2] = "";

    being_pointer->type = "knight";
    being_pointer->hp = 75;
    being_pointer->attack = 10;
    being_pointer->defense = 10;
    being_pointer->level = level;
    being_pointer->status = status_array;
    being_pointer->ability = "bleeding";

    return being_pointer;

}

struct being * create_rogue( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    char **status_array = (char **)calloc(3, sizeof(char [25]));
    status_array[0] = "";
    status_array[1] = "";
    status_array[2] = "";

    being_pointer->type = "rogue";
    being_pointer->hp = 100;
    being_pointer->attack = 5;
    being_pointer->defense = 15;
    being_pointer->level = level;
    being_pointer->status = status_array;
    being_pointer->ability = "poisoned";

    return being_pointer;

}

struct being * create_slime( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    char **status_array = (char **)calloc(3, sizeof(char [25]));
    status_array[0] = "";
    status_array[1] = "";
    status_array[2] = "";

    being_pointer->type = "slime";
    being_pointer->hp = 100;
    being_pointer->attack = 10;
    being_pointer->defense = 5;
    being_pointer->level = level;
    being_pointer->status = status_array;
    being_pointer->ability = "sticky";

    return being_pointer;

}

struct being * create_zombie( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    char **status_array = (char **)calloc(3, sizeof(char [25]));
    status_array[0] = "";
    status_array[1] = "";
    status_array[2] = "";

    being_pointer->type = "zombie";
    being_pointer->hp = 75;
    being_pointer->attack = 5;
    being_pointer->defense = 15;
    being_pointer->level = level;
    being_pointer->status = status_array;
    being_pointer->ability = "lazy";

    return being_pointer;

}

struct being * create_bat( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    char **status_array = (char **)calloc(3, sizeof(char [25]));
    status_array[0] = "";
    status_array[1] = "";
    status_array[2] = "";

    being_pointer->type = "bat";
    being_pointer->hp = 50;
    being_pointer->attack = 15;
    being_pointer->defense = 5;
    being_pointer->level = level;
    being_pointer->status = status_array;
    being_pointer->ability = "confused";

    return being_pointer;

}

struct being * free_being( struct being *pointer ) {
    free(pointer->status);
    free(pointer);
    return pointer;
}

struct being * print_being( struct being *pointer) {
    printf("Type: [%s]\n", pointer->type);
    printf("HP: [%d]\n", pointer->hp);
    printf("Attack: [%d]\n", pointer->attack);
    printf("Defense: [%d]\n", pointer->defense);
    printf("Level: [%d]\n", pointer->level);
    printf("Status:\n");
    printf("\t[%s]\n", pointer->status[0]);
    printf("\t[%s]\n", pointer->status[1]);
    printf("\t[%s]\n", pointer->status[2]);
    printf("Ability: [%s]\n", pointer->ability);
    return pointer;
}


// ---------- MAIN (TESTING FUNCTION) ----------
int main() {
    struct being *knight = create_knight(1);
    print_being(knight);
    free_being(knight)
    return 0;
}
