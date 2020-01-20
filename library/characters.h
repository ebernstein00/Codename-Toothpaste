struct being {
    char *type;
    int hp;
    int attack;
    int defense;
    int level;
    struct item **backpack;
    int is_guarding;
};

/* ---------- CREATING CHARACTERS ---------- */
struct being * create_mage( int level );
struct being * create_knight( int level );
struct being * create_rogue( int level );
struct being * create_fighter( int level );
struct being * create_dedede( int level );
struct being * create_waddledee( int level );
struct being * create_waddledoo( int level );
struct being * free_being( struct being *pointer );

int is_guarding(struct being *being);
int set_hp(struct being *pointer, int new_hp);
int set_attack(struct being *pointer, int new_attack);
int set_defense(struct being *pointer, int new_defense);
int guard(struct being *pointer);
int unguard(struct being *pointer);


int get_hp(struct being *pointer);
int get_attack(struct being *pointer);
int get_defense(struct being *pointer);
struct item ** get_backpack(struct being *pointer);

struct being * print_being( struct being *pointer);
int remove_item ( struct being *being_ptr, int item_index );
int add_item( struct being *being_ptr, struct item *item );

