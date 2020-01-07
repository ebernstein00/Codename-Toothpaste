struct being {
    char *type;
    int hp;
    int attack;
    int defense;
    int level;
    char *status[3];
    char *ability;
};

/* ---------- CREATING CHARACTERS ---------- */
struct being * create_mage( int level );
struct being * create_knight( int level );
struct being * create_rogue( int level );
struct being * create_slime( int level );
struct being * create_zombie( int level );
struct being * create_bat( int level );
struct being * free_being( struct being *pointer );
