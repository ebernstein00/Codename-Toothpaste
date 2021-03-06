#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

#define CONSUM_TYPE 1;
#define SWORD_TYPE 2;
#define ARMOR_TYPE 3;
#define NUM_ITEMS 23;


struct item {
    char *name;
    int hp_buff;
    int attack_buff;
    int defense_buff;
    int type;
    // 1: consumable
    // 2: sword
    // 3: armor
    int id;
};

/* //ITEM POOL */
/* struct item ** make_item_pool(){ */
/* 		struct item **item_pool = malloc(sizeof(struct item) * 33); */
/* 		item_pool[0][0] = create_wood_sword(); */
/* 		item_pool[0][1] = create_iron_sword(); */
/* 		item_pool[0][2] = create_steel_sword(); */
/* 		item_pool[0][3] = create_armoring_wooden_sword(); */
/* 		item_pool[0][4] = create_armoring_iron_sword(); */
/* 		item_pool[0][5] = create_armoring_steel_sword(); */
/* 		item_pool[0][6] = create_rigidity_wooden_sword(); */
/* 		item_pool[0][7] = create_rigidity_iron_sword(); */
/* 		item_pool[0][8] = create_rigidity_steel_sword(); */
/* 		item_pool[0][9] = create_leather_armor(); */
/* 		item_pool[0][10] = create_iron_armor(); */
/* 		item_pool[0][11] = create_steel_armor(); */
/* 		item_pool[0][12] = create_mithril_armor(); */
/* 		item_pool[0][13] = create_rigidity_leather_armor(); */
/* 		item_pool[0][14] = create_rigidity_iron_armor(); */
/* 		item_pool[0][15] = create_rigidity_steel_armor(); */
/* 		item_pool[0][16] = create_rigidity_mithril_armor(); */
/* 		item_pool[0][17] = create_strength_leather_armor(); */
/* 		item_pool[0][18] = create_strength_iron_armor(); */
/* 		item_pool[0][19] = create_strength_steel_armor(); */
/* 		item_pool[0][20] = create_strength_mithril_armor(); */
/* 		item_pool[0][21] = create_health_potion(); */
/* 		item_pool[0][22] = create_health_potion(); */
/* 		item_pool[0][23] = create_health_potion(); */
/* 		item_pool[0][24] = create_health_potion(); */
/* 		item_pool[0][25] = create_health_potion(); */
/* 		item_pool[0][26] = create_health_potion(); */
/* 		item_pool[0][27] = create_health_potion(); */
/* 		item_pool[0][28] = create_health_potion(); */
/* 		item_pool[0][29] = create_health_potion(); */
/* 		item_pool[0][30] = create_strength_potion(); */
/* 		item_pool[0][31] = create_strength_potion(); */
/* 		item_pool[0][32] = create_strength_potion(); */
/* 		item_pool[0][33] = create_strength_potion(); */
/*		return item_pool; */
/* } */

/* //RANDOM DROP */
/* struct item * random_drop(){ */
/* 	int n = rand() % 34; */
/* 	return loot_pool[0][n]; */
/* } */
	

//SWORDS
struct item * create_wood_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Wooden Sword";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 0;
    item_ptr->type = SWORD_TYPE;
    item_ptr->id = 0;
    return item_ptr;
}

struct item * create_iron_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Iron Sword";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 0;
    item_ptr->type = SWORD_TYPE;
    item_ptr->id = 1;
    return item_ptr;
}

struct item * create_steel_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Steel Sword";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 15;
    item_ptr->defense_buff = 0;
    item_ptr->type = SWORD_TYPE;
    item_ptr->id = 2;
    return item_ptr;
}

struct item * create_armoring_wooden_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Wooden Sword of Armoring";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 3;
    item_ptr->type = SWORD_TYPE;
    item_ptr->id = 3;
    return item_ptr;
}

struct item * create_armoring_iron_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Iron Sword of Armoring";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 3;
    item_ptr->type = SWORD_TYPE;
    item_ptr->id = 4;
    return item_ptr;
}

struct item * create_armoring_steel_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Steel Sword of Armoring";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 15;
    item_ptr->defense_buff = 3;
    item_ptr->type = SWORD_TYPE;
    item_ptr->id = 5;
    return item_ptr;
}

struct item * create_rigidity_wooden_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Wooden Sword of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 0;
    item_ptr->type = SWORD_TYPE;
    item_ptr->id = 6;
    return item_ptr;
}

struct item * create_rigidity_iron_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Iron Sword of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 0;
    item_ptr->type = SWORD_TYPE;
    item_ptr->id = 7;
    return item_ptr;
}


struct item * create_rigidity_steel_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Steel Sword of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 15;
    item_ptr->defense_buff = 0;
    item_ptr->type = SWORD_TYPE;
    item_ptr->id = 8;
    return item_ptr;
}

//ARMORS
struct item * create_leather_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Leather Armor";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 5;
    item_ptr->type = ARMOR_TYPE;
    item_ptr->id = 9;
    return item_ptr;
}

struct item * create_iron_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Iron Armor";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 10;
    item_ptr->type = ARMOR_TYPE;
    item_ptr->id = 10;
    return item_ptr;
}

struct item * create_steel_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Steel Armor";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 15;
    item_ptr->type = ARMOR_TYPE;
    item_ptr->id = 11;
    return item_ptr;
}

struct item * create_mithril_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Mithril Armor";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 25;
    item_ptr->type = ARMOR_TYPE;
    item_ptr->id = 12;
    return item_ptr;
}

struct item * create_rigidity_leather_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Leather Armor of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 5;
    item_ptr->type = ARMOR_TYPE;
    item_ptr->id = 13;
    return item_ptr;
}

struct item * create_rigidity_iron_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Iron Armor of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 10;
    item_ptr->type = ARMOR_TYPE;
    item_ptr->id = 14;
    return item_ptr;
}

struct item * create_rigidity_steel_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Steel Armor of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 15;
    item_ptr->type = ARMOR_TYPE;
    item_ptr->id = 15;
    return item_ptr;
}

struct item * create_rigidity_mithril_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Mithril Armor of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 25;
    item_ptr->type = ARMOR_TYPE;
    item_ptr->id = 16;
    return item_ptr;
}

struct item * create_strength_leather_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Leather Armor of Strength";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 5;
    item_ptr->type = ARMOR_TYPE;
    item_ptr->id = 17;
    return item_ptr;
}

struct item * create_strength_iron_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Iron Armor of Strength";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 10;
    item_ptr->type = ARMOR_TYPE;
    item_ptr->id = 18;
    return item_ptr;
}

struct item * create_strength_steel_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Steel Armor of Strength";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 15;
    item_ptr->type = ARMOR_TYPE;
    item_ptr->id = 19;
    return item_ptr;
}

struct item * create_strength_mithril_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Mithril Armor of Strength";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 25;
    item_ptr->type = ARMOR_TYPE;
    item_ptr->id = 20;
    return item_ptr;
}

//POTIONS

struct item * create_health_potion(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Health Potion";
    item_ptr->hp_buff = 20;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 0;
    item_ptr->type = CONSUM_TYPE;
    item_ptr->id = 21;
    return item_ptr;
}

struct item * create_strength_potion(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name ="Strength Potion";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 0;
    item_ptr->type = CONSUM_TYPE;
    item_ptr->id = 22;
    return item_ptr;
}

void print_item( struct item *item_ptr ) {
    printf("\t%s: hp[%d] a[%d] d[%d] type[%d]\n",
           item_ptr->name,
           item_ptr->hp_buff,
           item_ptr->attack_buff,
           item_ptr->defense_buff,
           item_ptr->type
        );
}

void free_item( struct item *item_ptr ) {
    free(item_ptr);
}


// Backpack
struct item ** create_backpack () {
    struct item **backpack = (struct item **)calloc(5, sizeof(struct item *)); 
    return backpack;
}

void free_backpack( struct item **backpack_ptr ) {
    if(backpack_ptr != NULL){
	free_item( backpack_ptr[0] );
	free_item( backpack_ptr[1] );
	free_item( backpack_ptr[2] );
	free_item( backpack_ptr[3] );
	free_item( backpack_ptr[4] );
    } 
    free(backpack_ptr);    
}

void print_backpack( struct item **backpack_ptr ) {
    printf("Backpack:\n");
    if ( backpack_ptr == NULL ){
	printf("\t[]\n");	
    } else {
	int i = 0;
	for (; i < 5; i++) {
	    if (backpack_ptr[i] == NULL) {
		printf("\t[]\n");
	    } else {
		print_item( backpack_ptr[i] );
	    }
	}
    }
}

