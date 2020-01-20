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
#include "../graphics/display.h"

struct being {
    char *type;
    int id;
    // 0: mage
    // 1: knight
    // 2: rogue
    // 3: fighter
    int maxhp;
    int hp;
    int attack;
    int defense;
    int level;
    struct item **backpack;
    int is_guarding;
    SDL_Rect rect;
};

/* ---------- CREATING CHARACTERS ---------- */
struct being * create_mage( int level );
struct being * create_knight( int level );
struct being * create_rogue( int level );
struct being * create_fighter( int level );
struct being * create_dedede( int level );
struct being * create_waddledee( int level );
struct being * create_waddledoo( int level );
struct being * free_being( struct being *pointer );

int is_guarding(struct being *being);
int set_hp(struct being *pointer, int new_hp);
int set_attack(struct being *pointer, int new_attack);
int set_defense(struct being *pointer, int new_defense);
int guard(struct being *pointer);
int unguard(struct being *pointer);

int get_id(struct being *pointer);
int get_maxhp(struct being *pointer);
int get_hp(struct being *pointer);
int get_attack(struct being *pointer);
int get_defense(struct being *pointer);
struct item ** get_backpack(struct being *pointer);

struct being * print_being( struct being *pointer);
int remove_item ( struct being *being_ptr, int item_index );
int add_item( struct being *being_ptr, struct item *item );
