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

struct being {
    int hp;
    int attack;
    int defense;
    int level;
    char *status[3];
    char *ability;
};

/*---------- PROTAGONISTS ----------*/
struct mage {
    // Default Mage config, at lv 1
    struct being base = {
	hp = 50,
	attack = 20,
	defense = 5,
	level = 1,
	status = NULL,
	ability = "burned"
    }
};


struct knight {
    // Default Knight config, at lv 1
    struct being base = {
	hp = 75,
	attack = 10,
	defense = 10,
	level = 1,
	status = NULL,
	ability = "bleeding",
    }
};


struct rogue {
    // Default Rogue config, at lv 1
    struct being base = {
	hp = 100,
	attack = 5,
	defense = 15,
	level = 1,
	status = NULL,
	ability = "poisoned"
    }
};

/*---------- MONSTERS ---------- */

struct slime {
    // Default Slime config, at lv 1
    struct being base = {
	hp = 100,
	attack = 10,
	defense = 5,
	level = 1,
	status = NULL,
	ability = "sticky"
    }

};

struct zombie {
    // Default zombie config, at lv 1
    struct being base = {
	hp = 75,
	attack = 5,
	defense = 15,
	level = 1,
	status = NULL,
	ability = "lazy"
    }
};

struct bat {
    // Default Rogue config, at lv 1
    struct being base = {
	hp = 50,
	attack = 15,
	defense = 5,
	level = 1,
	status = NULL,
	ability = "confused"
    }
};


int main() {
    return 0;
}
