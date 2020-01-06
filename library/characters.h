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
    struct being base;
};

struct knight {
    // Default Knight config, at lv 1
    struct being base;
};


struct rogue {
    // Default Rogue config, at lv 1
    struct being base;
};

/*---------- MONSTERS ---------- */

struct slime {
    // Default Slime config, at lv 1
    struct being base;
};

struct zombie {
    // Default zombie config, at lv 1
    struct being base;
};

struct bat {
    // Default Rogue config, at lv 1
    struct being base;
};

/* ---------- CREATING CHARACTERS ---------- */
struct being * create_mage( int level );
struct being * create_knight( int level );
struct being * create_rogue( int level );
struct being * create_slime( int level );
struct being * create_zombie( int level );
struct being * create_bat( int level );
struct being * free_being( struct being *pointer );
