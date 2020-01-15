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
};

/* //ITEM POOL */
/* struct item ** make_item_pool(){ */
/* 	struct item **item_pool = malloc(sizeof(struct item) * 23); */
/* 	item_pool[0] = create_wood_sword(); */
/* 	item_pool[1] = create_iron_sword(); */
/* 	item_pool[2] = create_steel_sword(); */
/* 	item_pool[3] = create_armoring_wooden_sword(); */
/* 	item_pool[4] = create_armoring_iron_sword(); */
/* 	item_pool[5] = create_armoring_steel_sword(); */
/* 	item_pool[6] = create_rigidity_wooden_sword(); */
/* 	item_pool[7] = create_rigidity_iron_sword(); */
/* 	item_pool[8] = create_rigidity_steel_sword(); */
/* 	item_pool[9] = create_iron_sword(); */
/* 	item_pool[10] = create_iron_sword(); */
/* 	item_pool[11] = create_iron_sword(); */
/* 	item_pool[12] = create_iron_sword(); */
/* 	item_pool[13] = create_iron_sword(); */
/* 	item_pool[14] = create_iron_sword(); */
/* 	item_pool[15] = create_iron_sword(); */
/* 	item_pool[16] = create_iron_sword(); */
/* 	item_pool[17] = create_iron_sword(); */
/* 	item_pool[18] = create_iron_sword(); */
/* 	item_pool[19] = create_iron_sword(); */
/* 	item_pool[20] = create_iron_sword(); */
/* 	item_pool[21] = create_iron_sword(); */
/* 	item_pool[22] = create_iron_sword(); */
/* 	item_pool[23] = create_iron_sword(); */
/* 	//item_pool[1] = create_iron_sword(); */
/* 	//item_pool[1] = create_iron_sword(); */
/* 	//item_pool[1] = create_iron_sword(); */
/* 	//item_pool[1] = create_iron_sword(); */
/* 	//item_pool[1] = create_iron_sword(); */
/* 	//item_pool[1] = create_iron_sword(); */
/* 	//item_pool[1] = create_iron_sword(); */
	

//SWORDS
struct item * create_wood_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Wooden Sword";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 1;
    item_ptr->type = SWORD_TYPE;
    return item_ptr;
}

struct item * create_iron_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Iron Sword";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 0;
    item_ptr->type = SWORD_TYPE;
    return item_ptr;
}

struct item * create_steel_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Steel Sword";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 15;
    item_ptr->defense_buff = 0;
    item_ptr->type = SWORD_TYPE;
    return item_ptr;
}

struct item * create_armoring_wooden_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Wooden Sword of Armoring";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 3;
    item_ptr->type = SWORD_TYPE;
    return item_ptr;
}

struct item * create_armoring_iron_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Iron Sword of Armoring";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 3;
    item_ptr->type = SWORD_TYPE;
    return item_ptr;
}

struct item * create_armoring_steel_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Steel Sword of Armoring";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 15;
    item_ptr->defense_buff = 3;
    item_ptr->type = SWORD_TYPE;
    return item_ptr;
}

struct item * create_rigidity_wooden_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Wooden Sword of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 0;
    item_ptr->type = SWORD_TYPE;
    return item_ptr;
}

struct item * create_rigidity_iron_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Iron Sword of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 0;
    item_ptr->type = SWORD_TYPE;
    return item_ptr;
}


struct item * create_rigidity_steel_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Steel Sword of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 15;
    item_ptr->defense_buff = 0;
    item_ptr->type = SWORD_TYPE;
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
    return item_ptr;
}

struct item * create_iron_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Iron Armor";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 10;
    item_ptr->type = ARMOR_TYPE;
    return item_ptr;
}

struct item * create_steel_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Steel Armor";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 15;
    item_ptr->type = ARMOR_TYPE;
    return item_ptr;
}

struct item * create_mithril_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Mithril Armor";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 25;
    item_ptr->type = ARMOR_TYPE;
    return item_ptr;
}

struct item * create_rigidity_leather_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Leather Armor of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 5;
    item_ptr->type = ARMOR_TYPE;
    return item_ptr;
}

struct item * create_rigidity_iron_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Iron Armor of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 10;
    item_ptr->type = ARMOR_TYPE;
    return item_ptr;
}

struct item * create_rigidity_steel_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Steel Armor of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 15;
    item_ptr->type = ARMOR_TYPE;
    return item_ptr;
}

struct item * create_rigidity_mithril_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Mithril Armor of Rigidity";
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 25;
    item_ptr->type = ARMOR_TYPE;
    return item_ptr;
}

struct item * create_strength_leather_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Leather Armor of Strength";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 5;
    item_ptr->type = ARMOR_TYPE;
    return item_ptr;
}

struct item * create_strength_iron_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Iron Armor of Strength";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 10;
    item_ptr->type = ARMOR_TYPE;
    return item_ptr;
}

struct item * create_strength_steel_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Steel Armor of Strength";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 15;
    item_ptr->type = ARMOR_TYPE;
    return item_ptr;
}

struct item * create_strength_mithril_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Mithril Armor of Strength";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 25;
    item_ptr->type = ARMOR_TYPE;
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
    return item_ptr;
}

struct item * create_strength_potion(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name ="Strength Potion";
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 0;
    item_ptr->type = CONSUM_TYPE;
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

