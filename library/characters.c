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

struct being {
    char *type;
    int id;
    // 0: mage
    // 1: knight
    // 2: rogue
    // 3: fighter
    
    int hp;
    int attack;
    int defense;
    int level;
    struct item **backpack;
    int is_guarding;
};

/*---------- PROTAGONISTS ----------*/
struct being * create_mage( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    being_pointer->type = "mage";
    being_pointer->hp = 50;
    being_pointer->attack = 20;
    being_pointer->defense = 5;
    being_pointer->level = level;
    being_pointer->backpack = create_backpack();
    being_pointer->is_guarding = 0;
    return being_pointer;
}

struct being * create_knight( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));

    being_pointer->type = "knight";
    being_pointer->hp = 75;
    being_pointer->attack = 10;
    being_pointer->defense = 10;
    being_pointer->level = level;
    being_pointer->backpack = create_backpack();
    being_pointer->is_guarding = 0;

    return being_pointer;

}

struct being * create_rogue( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    being_pointer->type = "rogue";
    being_pointer->hp = 100;
    being_pointer->attack = 5;
    being_pointer->defense = 15;
    being_pointer->level = level;
    being_pointer->backpack = create_backpack();
    being_pointer->is_guarding = 0;

    return being_pointer;
}

struct being * create_fighter( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    being_pointer->type = "fighter";

    // not balanced, copied from rogue
    /* being_pointer->hp = 100; */
    /* being_pointer->attack = 5; */
    /* being_pointer->defense = 15; */
    /* being_pointer->level = level; */
    /* being_pointer->backpack = create_backpack(); */
    /* being_pointer->is_guarding = 0; */

    return being_pointer;
}


/*---------- ANTAGONISTS ----------*/

struct being * create_slime( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));

    being_pointer->type = "slime";
    being_pointer->hp = 100;
    being_pointer->attack = 10;
    being_pointer->defense = 5;
    being_pointer->level = level;

    //BEASTS HAVE NULL BACKPACKS
    being_pointer->backpack = NULL;
    being_pointer->is_guarding = 0;
    
    return being_pointer;
}

struct being * create_zombie( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));

    being_pointer->type = "zombie";
    being_pointer->hp = 75;
    being_pointer->attack = 5;
    being_pointer->defense = 15;
    being_pointer->level = level;
    being_pointer->backpack = NULL;
    being_pointer->is_guarding = 0;

    return being_pointer;

}

struct being * create_bat( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));

    being_pointer->type = "bat";
    being_pointer->hp = 50;
    being_pointer->attack = 15;
    being_pointer->defense = 5;
    being_pointer->level = level;
    being_pointer->backpack = NULL;
    being_pointer->is_guarding = 0;

    return being_pointer;

}

struct being * free_being( struct being *pointer ) {
    free_backpack(pointer->backpack);
    free(pointer);
    return pointer;
}

struct being * print_being( struct being *pointer) {
    printf("Type: [%s]\n", pointer->type);
    printf("HP: [%d]\n", pointer->hp);
    printf("Attack: [%d]\n", pointer->attack);
    printf("Defense: [%d]\n", pointer->defense);
    printf("Level: [%d]\n", pointer->level);
    printf("Is Guarding? [%d]\n", pointer->is_guarding);
    print_backpack( pointer->backpack );
    return pointer;
}


int remove_item ( struct being *being_ptr, int item_index ) {
    switch( item_index )
    {
    case 0:
	free_item( being_ptr->backpack[item_index] );
	being_ptr->backpack[item_index] = NULL;
	return 1;
	break;
    case 1: 
	free_item( being_ptr->backpack[item_index] );
	being_ptr->backpack[item_index] = NULL;
	return 1;
	break;
    case 2: 
	free_item( being_ptr->backpack[item_index] );
	being_ptr->backpack[item_index] = NULL;
	return 1;
	break;
    case 3:
	being_ptr->hp -= being_ptr->backpack[item_index]->hp_buff;
	being_ptr->attack -= being_ptr->backpack[item_index]->attack_buff;
	being_ptr->defense -= being_ptr->backpack[item_index]->defense_buff;
	free_item( being_ptr->backpack[item_index] );
	return 1;
	break;
    case 4: 
	being_ptr->hp -= being_ptr->backpack[item_index]->hp_buff;
	being_ptr->attack -= being_ptr->backpack[item_index]->attack_buff;
	being_ptr->defense -= being_ptr->backpack[item_index]->defense_buff;
	free_item( being_ptr->backpack[item_index] );
	return 1;
	break;
    default: return -1;
    }
}

int add_item( struct being *being_ptr, struct item *item ) {
    int i = 0;
    switch( item->type ) {
    case 1:
	for (; i < 3; i++) {
	    if (being_ptr->backpack[i] == NULL) {
		being_ptr->backpack[i] = item;
                return 1;
            }
	}

        remove_item( being_ptr, 0 );
        being_ptr->backpack[0] = item;
        return 1;
        break;
    case 2:
        if( being_ptr->backpack[3] == NULL ) {
	    printf("is null\n");
	    being_ptr->backpack[3] = item;
            being_ptr->hp += item->hp_buff;
            /* printf( "[%d]\n",item->attack_buff ); */
            /* printf( "[%d]\n",item->hp_buff ); */
            being_ptr->attack += item->attack_buff;
            being_ptr->defense += item->defense_buff;            
        } else {
            printf("not-null\n");
	    print_backpack( being_ptr->backpack );
            int r = remove_item( being_ptr, 3);
            if (r == -1) {
                printf("error: remove item\n");
		return 1;
            }
            being_ptr->backpack[3] = item;
            being_ptr->hp += item->hp_buff;

            /* printf( "[%d]\n",item->attack_buff ); */
            /* printf( "[%d]\n",item->hp_buff ); */
            being_ptr->attack += item->attack_buff;
            being_ptr->defense += item->defense_buff;            
        }
        return 1;
        break;
    case 3:
        if( being_ptr->backpack[4] == NULL ) {
            being_ptr->backpack[4] = item;
            being_ptr->hp += item->hp_buff;
            being_ptr->attack += item->attack_buff;
            being_ptr->defense += item->defense_buff;            

        } else {
            int r = remove_item( being_ptr, 4);
            if (r == -1) {
                printf("error: remove item\n");
		return 1;
            }
            being_ptr->backpack[4] = item;
            being_ptr->hp += item->hp_buff;
            being_ptr->attack += item->attack_buff;
            being_ptr->defense += item->defense_buff;            
        }
        return 1;
        break;
    default:
        return -1;
    }        	
}
