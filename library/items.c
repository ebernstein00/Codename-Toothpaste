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

struct item {
    char *name;
    int hp_buff;
    int attack_buff;
    int defense_buff;
    int isconsumable;
};

//SWORDS
struct item * create_wood_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Wooden Sword");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 0;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_iron_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Iron Sword");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 0;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_steel_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Steel Sword");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 15;
    item_ptr->defense_buff = 0;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_armoring_wooden_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Wooden Sword of Armoring");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 3;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_armoring_iron_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Iron Sword of Armoring");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 3;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_armoring_steel_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Steel Sword of Armoring");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 15;
    item_ptr->defense_buff = 3;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_rigidity_wooden_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Wooden Sword of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 0;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_rigidity_iron_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Iron Sword of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 0;
    item_ptr->isconsumable = 0;
    return item_ptr;
}


struct item * create_rigidity_steel_sword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Steel Sword of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 15;
    item_ptr->defense_buff = 0;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

//ARMORS
struct item * create_leather_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Leather Armor");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 5;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_iron_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Iron Armor");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 10;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_steel_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Steel Armor");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 15;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_mithril_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Mithril Armor");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 25;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_rigidity_leather_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Leather Armor of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 5;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_rigidity_iron_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Iron Armor of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 10;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_rigidity_steel_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Steel Armor of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 15;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_rigidity_mithril_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Mithril Armor of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 25;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_strength_leather_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Leather Armor of Strength");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 5;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_strength_iron_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Iron Armor of Strength");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 10;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_strength_steel_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Steel Armor of Strength");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 15;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

struct item * create_strength_mithril_armor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Mithril Armor of Strength");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 5;
    item_ptr->defense_buff = 25;
    item_ptr->isconsumable = 0;
    return item_ptr;
}

//POTIONS

struct item * create_health_potion(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    item_ptr->name = "Health Potion";
    item_ptr->hp_buff = 20;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 0;
    item_ptr->isconsumable = 1;
    return item_ptr;
}

struct item * create_strength_potion(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Strength Potion");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 0;
    item_ptr->isconsumable = 1;
    return item_ptr;
}

void print_item( struct item *item_ptr ) {
    printf("\t%s: hp[%d] a[%d] d[%d] cons?[%d]\n",
           item_ptr->name,
           item_ptr->hp_buff,
           item_ptr->attack_buff,
           item_ptr->defense_buff,
           item_ptr->isconsumable
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
    free_item( backpack_ptr[0] );
    free_item( backpack_ptr[1] );
    free_item( backpack_ptr[2] );
    free_item( backpack_ptr[3] );
    free_item( backpack_ptr[4] );
    free(backpack_ptr);
    
}

void print_backpack( struct item **backpack_ptr ) {
    printf("Backpack:\n");

    int i = 0;
    for (; i < 5; i++) {
        if (backpack_ptr[i] == NULL) {
            printf("\t[]\n");
        } else {
            printf("\t%s: hp[%d] a[%d] d[%d] cons?[%d]\n",
                   backpack_ptr[i]->name,
                   backpack_ptr[i]->hp_buff,
                   backpack_ptr[i]->attack_buff,
                   backpack_ptr[i]->defense_buff,
                   backpack_ptr[i]->isconsumable
                );
        }
    }
}

