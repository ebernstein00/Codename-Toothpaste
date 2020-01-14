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

struct game {
    struct being *player1;
    struct being *player2;
    struct being *monster1;
    struct being *monster2;
};

int attack(struct being * attacker, struct being * target){
    int damage;
    damage = attacker->attack - target->defense;
    target->hp -= damage;    
    printf("%s attacked %s for %d damage!", attacker->type, target->type, damage);
    return 0;
}

int use_item(struct being * user, int item_index){
    if( user->backpack[item_index] == NULL ){
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
    user->defense += 20;
    printf("Guard Initiated (Defense +20)\n");
    return 0;
}

int guard_end(struct being * user){
    user->defense -= 20;
    printf("Guard Ended (Defense -20)\n");
    return 0;
}

int playerturn( struct being *player, struct game *game ) {
    char *input = (char *)calloc(12, sizeof( char ));
    int player_move;
    int selected_enemy;

    /* printf("--- Attacking Player ---\n"); */
    /* print_being( player ); */
    if( player->is_guarding ) {
	guard_end( player );
    }

    printf("%s move:\n", player->type);
    printf("Potion 1: [1]\n");
    printf("Potion 2: [2]\n");
    printf("Potion 3: [3]\n");
    printf("  Attack: [4]\n");
    printf("   Guard: [5]\n");
    printf("> ");
    
    fgets( input, 12, stdin );
    *strchr( input, '\n' ) = 0;
    
    // convert string to int.
    player_move = atoi(input);


    switch( player_move ) {
    case(1):
	return use_item( player, 0);	
        break;
    case(2):
	return use_item( player, 1);
        break;
    case(3):
	return use_item( player, 2);
        break;
    case(4):
	printf("Choose the enemy you wish to attack:\n");
        printf("%s: [1]\n", game->monster1->type);
        printf("%s: [2]\n", game->monster2->type);
	printf("> ");
	fgets( input, 12, stdin );
	*strchr( input, '\n' ) = 0;
	selected_enemy = atoi( input );
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
    return 0;        
}

int freegame( struct game *game ) {
    free_being( game->player1 );
    free_being( game->player2 );
    free_being( game->monster1 );
    free_being( game->monster2 );
    free( game );
}

struct game *newgame() {
    struct game *game = (struct game *)calloc(1, sizeof(struct game));
    return game;
}

void printgame( struct game *game ) {
    printf("Game:\n");
    print_being( game->player1 );
    print_being( game->player2 );
    print_being( game->monster1 );
    print_being( game->monster2 );
}
