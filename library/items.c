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

struct item * create_backpack () {
    
    return backpack;
}  
