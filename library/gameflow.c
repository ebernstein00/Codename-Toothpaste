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
#include "characters.h"

struct game {
    struct being *player1;
    struct being *player2;
    struct being *monster1;
    struct being *monster2;
};

struct item * rand_item() {
    int i = 0;
    int num = 0;
    struct item *rand_item;
    num = (rand() % 23);
    printf("random num[%d]\n", num);
    switch( num ){
    case(0):
        rand_item = create_wood_sword();
        break;
    case(1):
        rand_item = create_iron_sword();
        break;
    case(2):
        rand_item = create_steel_sword();
        break;
    case(3):
        rand_item = create_armoring_wooden_sword();
        break;
    case(4):
        rand_item = create_armoring_iron_sword();
        break;
    case(5):
        rand_item = create_armoring_steel_sword();
        break;
    case(6):
        rand_item = create_rigidity_wooden_sword();
        break;
    case(7):
        rand_item = create_rigidity_iron_sword();
        break;
    case(8):
        rand_item = create_rigidity_steel_sword();
        break;
    case(9):
        rand_item = create_leather_armor();
        break;
    case(10):
        rand_item = create_iron_armor();
        break;
    case(11):
        rand_item = create_steel_armor();
        break;
    case(12):
        rand_item = create_mithril_armor();
        break;
    case(13):
        rand_item = create_rigidity_leather_armor();
        break;
    case(14):
        rand_item = create_rigidity_iron_armor();
        break;
    case(15):
        rand_item = create_rigidity_steel_armor();
        break;
    case(16):
        rand_item = create_rigidity_mithril_armor();
        break;
    case(17):
        rand_item = create_strength_leather_armor();
        break;
    case(18):
        rand_item = create_strength_iron_armor();
        break;
    case(19):
        rand_item = create_strength_steel_armor();
        break;
    case(20):
        rand_item = create_strength_mithril_armor();
        break;
    case(21):
        rand_item = create_health_potion();
        break;
    case(22):
        rand_item = create_strength_potion();
        break;
    default:
        return NULL;
    }
    return rand_item;
}

int coinflip() {
    int randomBit;
    int i;
    randomBit = rand() % 2;
    /* printf("%d\n", randomBit); */
    return randomBit;
}

int attack(struct being * attacker, struct being * target){
    int damage;
    int currenthp;
    damage = get_attack( attacker ) - get_defense( target );
    if(damage <= 0) damage = 0;
    currenthp = get_hp(target);
    set_hp( target, (currenthp - damage));
    printf("*** ATTACK ***\n%s attacked %s for %d damage!\n*** ATTACK ***\n", attacker->type, target->type, damage);
    return 0;
}

int use_item(struct being *user, int item_index){
    if( get_backpack( user )[item_index] == NULL ){
	printf("Nothing in that slot\n");
	return 1;
    }
    if ((strcmp(user->backpack[item_index]->name, "Health Potion") == 0) ||
	(strcmp(user->backpack[item_index]->name, "Strength Potion") == 0)){
        user->hp += user->backpack[item_index]->hp_buff;
        user->attack += user->backpack[item_index]->attack_buff;
    }
    remove_item(user, item_index);
    return 0;
}

int guard_start(struct being * user){
    set_defense( user, (get_defense(user) + 15));
    guard(user);
    printf("*** GUARD ***\nGuard Initiated (Defense +15)\n*** GUARD ***\n");
    return 0;
}

int guard_end(struct being * user){
    set_defense( user, (get_defense(user) - 15));
    unguard(user);
    printf("*** ENDGUARD ***\nGuard Ended (Defense -15)\n*** GUARDEND ***\n");
    return 0;
}

int monsterturn( struct being *monster, struct game *game ) {
    printf("Monster turn! \n");
    int move;
    int target;
    if (is_guarding(monster) == 1) {
        guard_end(monster);
    }
    move = coinflip();
    // 0: attack
    // 1: defend
    if( move == 0 ){
        guard_start( monster );
        return 0;
    }

    // Otherwise, If Both players are still alive
    if (( game->player1 != NULL ) && (game->player2 != NULL)) {
        target = coinflip();
        switch( target ){
        case 0:
            attack( monster, game->player1 );
            break;
        case 1:
            attack( monster, game->player2 );
            break;
        default:
            printf("error: monster turn\n");
            return 1;
        }
        return 0;

        // if only p1 is alive
    } else if (( game->player1 != NULL ) && ( game->player2 == NULL )) {
        attack( monster, game->player1 );
        return 0;
        // if only p2 is alive
    } else if (( game->player1 == NULL ) && ( game->player2 != NULL )) {
        attack( monster, game->player2 );
        return 0;
        // if both are dead (should already be done by now, just in case tho)
    } else {
        printf("error: monster turn: all players dead\n");
        return 0;
    }
}

int playerturn( struct being *player, struct game *game , int player_move, int selected_enemy) {
    char *input = (char *)calloc(3, sizeof( char ));

    printf("--- Attacking Player ---\n");
    print_being( player );
    if( is_guarding( player ) ) {
	guard_end( player );
    }
    /* printf("%s hp[%d] a[%d] d[%d] move:\n", player->type, player->hp, player->attack, player->defense); */

    // convert string to int.

    switch( player_move ) {
    case(1):
	use_item( player, 0);
        break;
    case(2):
	use_item( player, 1);
        break;
    case(3):
	use_item( player, 2);
        break;
    case(4):
	   switch( selected_enemy ) {
    	case(1):
    	    attack( player, game->monster1);
    	    break;
    	case(2):
    	    attack( player, game->monster2);
    	    break;
    	default:
    	    printf("Not a valid input\n");
    	    return 1;
    	}
        break;
    case(5):
        guard_start( player );
        break;
    default:
	printf("Not a valid input\n");
    }
    free( input );
    return 0;
}

void dropItem(struct item *dropped_item) {
    print_item(dropped_item);
    printf("Pick Up the Item? (ENTER to pick up, BACKSPACE to leave it) \n");
}

void addItem(struct being *player, struct item *dropped_item, int input) {
    if(input) {
        add_item(player, dropped_item);
        printf("Item added\n");
    }
    else {
        free(dropped_item);
        printf("Item not added\n");
    }
}

int freegame( struct game *game ) {
    free_being( game->player1 );
    free_being( game->player2 );
    free_being( game->monster1 );
    free_being( game->monster2 );
    free( game );
    return 0;
}

struct game *newgame() {
    struct game *game = (struct game *)calloc(1, sizeof(struct game));
    return game;
}

void printgame( struct game *game ) {
    printf("Game:\n");
    if (game->player1 != NULL) {
        print_being( game->player1 );
    }
    if (game->player2 != NULL) {
        print_being( game->player2 );
    }
    if (game->monster1 != NULL) {
        print_being( game->monster1 );
    }
    if (game->monster2 != NULL) {
        print_being( game->monster2 );
    }
}


int garbage_collector( struct game *game ) {
    if (game->player1 != NULL) {
        if (get_hp(game->player1) <= 0) {
    	free_being( game->player1 );
    	game->player1 = NULL;
        }
    }
    if (game->player2 != NULL) {
        if (get_hp(game->player2) <= 0) {
    	free_being( game->player2 );
    	game->player2 = NULL;
        }
    }
    if (game->monster1 != NULL) {
        if (get_hp(game->monster1) <= 0) {
    	free_being( game->monster1 );
    	game->monster1 = NULL;
        }
    }
    if (game->monster2 != NULL) {
        if (get_hp(game->monster2) <= 0) {
    	free_being( game->monster2 );
    	game->monster2 = NULL;
        }
    }
    if (game->player1 == NULL || game->player2 == NULL) {
        printf ("You lost. Better luck next time! \n");
        return 1;
    }
    else if (game->monster1 == NULL && game->monster2 == NULL) {
        printf("Congratulations! You won the battle! \n");
        return 1;
    }

    return 0;
}
