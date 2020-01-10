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
};

struct consumable {
    char *name;
    int heal_factor;
    int damage_factor;
};

//SWORDS
struct item * create_woodensword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Wooden Sword");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 0;
    return item_ptr;
}

struct item * create_ironsword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Iron Sword");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 25;
    item_ptr->defense_buff = 0;
    return item_ptr;
}

struct item * create_steelsword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Steel Sword");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 50;
    item_ptr->defense_buff = 0;
    return item_ptr;
}

struct item * create_armoringwoodensword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Wooden Sword of Armoring");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 5;
    return item_ptr;
}

struct item * create_armoringironsword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Iron Sword of Armoring");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 25;
    item_ptr->defense_buff = 5;
    return item_ptr;
}

struct item * create_armoringsteelsword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Steel Sword of Armoring");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 50;
    item_ptr->defense_buff = 5;
    return item_ptr;
}

struct item * create_rigiditywoodensword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Wooden Sword of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 0;
    return item_ptr;
}

struct item * create_rigidityironsword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Iron Sword of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 25;
    item_ptr->defense_buff = 0;
    return item_ptr;
}


struct item * create_rigiditysteelsword(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Steel Sword of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 50;
    item_ptr->defense_buff = 0;
    return item_ptr;
}

//ARMORS
struct item * create_leatherarmor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Leather Armor");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 10;
    return item_ptr;
}

struct item * create_ironarmor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Iron Armor");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 20;
    return item_ptr;
}

struct item * create_steelarmor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Steel Armor");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 30;
    return item_ptr;
}

struct item * create_mithrilarmor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Mithril Armor");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 50;
    return item_ptr;
}

struct item * create_rigidityleatherarmor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Leather Armor of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 10;
    return item_ptr;
}

struct item * create_rigidityironarmor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Iron Armor of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 20;
    return item_ptr;
}

struct item * create_rigiditysteelarmor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Steel Armor of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 30;
    return item_ptr;
}

struct item * create_rigiditymithrilarmor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Mithril Armor of Rigidity");
    item_ptr->hp_buff = 5;
    item_ptr->attack_buff = 0;
    item_ptr->defense_buff = 50;
    return item_ptr;
}

struct item * create_strengthleatherarmor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Leather Armor of Strength");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 10;
    return item_ptr;
}

struct item * create_strengthironarmor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Iron Armor of Strength");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 20;
    return item_ptr;
}

struct item * create_strengthsteelarmor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Steel Armor of Strength");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 30;
    return item_ptr;
}

struct item * create_strengthmithrilarmor(){
    struct item * item_ptr = (struct item *)calloc(1, sizeof(struct item));
    strcpy(item_ptr->name, "Mithril Armor of Strength");
    item_ptr->hp_buff = 0;
    item_ptr->attack_buff = 10;
    item_ptr->defense_buff = 50;
    return item_ptr;
}

//POTIONS

struct consumable * create_healthpotion(){
    struct consumable * cons_ptr = (struct consumable *)calloc(1, sizeof(struct consumable));
    strcpy(cons_ptr->name, "Health Potion");
    cons_ptr->health_factor = 20;
    cons_ptr->damage_factor = 0;
    return cons_ptr;
}

struct consumable * create_strengthpotion(){
    struct consumable * cons_ptr = (struct consumable *)calloc(1, sizeof(struct consumable));
    strcpy(cons_ptr->name, "Strength Potion");
    cons_ptr->health_factor = 0;
    cons_ptr->damage_factor = 20;
    return cons_ptr;
}


struct item * create_backpack () {
    
    return backpack;
}  
