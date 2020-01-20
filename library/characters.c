#include "characters.h"

/*---------- PROTAGONISTS ----------*/
struct being * create_mage( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    being_pointer->type = "mage";
    being_pointer->id = 0;
    being_pointer->hp = 50;
    being_pointer->maxhp =50;
    being_pointer->attack = 25;
    being_pointer->defense = 0;
    being_pointer->level = level;
    being_pointer->backpack = create_backpack();
    being_pointer->is_guarding = 0;
    being_pointer->rect = MIdstrect;
    return being_pointer;
}

struct being * create_knight( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    being_pointer->type = "knight";
	being_pointer->id = 1;
    being_pointer->hp = 100;
    being_pointer->maxhp = 100;
    being_pointer->attack = 10;
    being_pointer->defense = 0;
    being_pointer->level = level;
    being_pointer->backpack = create_backpack();
    being_pointer->is_guarding = 0;
    being_pointer->rect = KIdstrect;
    return being_pointer;
}

struct being * create_rogue( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    being_pointer->type = "rogue";
	being_pointer->id = 2;
    being_pointer->hp = 70;
    being_pointer->maxhp = 70;
    being_pointer->attack = 20;
    being_pointer->defense = 0;
    being_pointer->level = level;
    being_pointer->backpack = create_backpack();
    being_pointer->is_guarding = 0;
    being_pointer->rect = RIdstrect;
    return being_pointer;
}

struct being * create_fighter( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));
    being_pointer->type = "fighter";
	being_pointer->id = 3;
    being_pointer->hp = 85;
    being_pointer->maxhp = 85;
    being_pointer->attack = 15;
    being_pointer->defense = 0;
    being_pointer->level = level;
    being_pointer->backpack = create_backpack();
    being_pointer->is_guarding = 0;
    being_pointer->rect = MIdstrect;
    return being_pointer;
}


/*---------- ANTAGONISTS ----------*/

struct being * create_dedede( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));

    being_pointer->type = "dedede";
    being_pointer->id = 5;
    being_pointer->hp = 100;
    being_pointer->maxhp = 100;
    being_pointer->attack = 10;
    being_pointer->defense = 5;
    being_pointer->level = level;

    //BEASTS HAVE NULL BACKPACKS
    being_pointer->backpack = NULL;
    being_pointer->is_guarding = 0;
    being_pointer->rect = DIdstrect;
    return being_pointer;
}

struct being * create_waddledee( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));

    being_pointer->type = "waddledee";
    being_pointer->id = 7;
    being_pointer->hp = 75;
    being_pointer->maxhp = 75;
    being_pointer->attack = 5;
    being_pointer->defense = 15;
    being_pointer->level = level;
    being_pointer->backpack = NULL;
    being_pointer->is_guarding = 0;
    being_pointer->rect = WIdstrect;
    return being_pointer;

}

struct being * create_waddledoo( int level ) {
    struct being *being_pointer = (struct being *)calloc(1, sizeof(struct being));

    being_pointer->type = "waddledoo";
    being_pointer->id = 8;
    being_pointer->hp = 50;
    being_pointer->maxhp = 50;
    being_pointer->attack = 15;
    being_pointer->defense = 5;
    being_pointer->level = level;
    being_pointer->backpack = NULL;
    being_pointer->is_guarding = 0;
    being_pointer->rect = OIdstrect;

    return being_pointer;

}


// HELPER FUNKS

int is_guarding( struct being *being ) {
    return being->is_guarding;
}
struct being * free_being( struct being *pointer ) {
    free_backpack(pointer->backpack);
    free(pointer);
    return pointer;
}

struct being * print_being( struct being *pointer) {
    printf("Type[%s]\t", pointer->type);
    printf("HP[%d]\t", pointer->hp);
    printf("Att[%d]\t", pointer->attack);
    printf("Def[%d]\t", pointer->defense);
    printf("Lev[%d]\t", pointer->level);
    printf("Guard?[%d]\n", pointer->is_guarding);
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

int set_hp(struct being *pointer, int new_hp) {
    pointer->hp = new_hp;
    return 0;
}

int set_attack(struct being *pointer, int new_attack) {
    pointer->attack = new_attack;
    return 0;
}
int set_defense(struct being *pointer, int new_defense) {
    pointer->defense = new_defense;
    return 0;
}

int guard( struct being *pointer) {
    pointer->is_guarding = 1;
    return 0;
}

int unguard( struct being *pointer) {
    pointer->is_guarding = 0;
    return 0;
}

int get_id(struct being *pointer) {
    return pointer->id;
}

int get_hp(struct being *pointer) {
    return pointer->hp;
}

int get_maxhp(struct being *pointer) {
    return pointer->maxhp;
}
int get_attack(struct being *pointer) {
    return pointer->attack;
}
int get_defense(struct being *pointer) {
    return pointer->defense;
}

struct item ** get_backpack( struct being *pointer ) {
    return pointer->backpack;
}
