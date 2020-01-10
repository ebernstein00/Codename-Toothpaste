
struct item {
    char *name;
    int hp_buff;
    int attack_buff;
    int defense_buff;
    int isconsumable;
};

//SWORDS
struct item * create_wood_sword();
struct item * create_iron_sword();
struct item * create_steel_sword();
struct item * create_armoring_wooden_sword();
struct item * create_armoring_iron_sword();
struct item * create_armoring_steel_sword();
struct item * create_rigidity_wooden_sword();
struct item * create_rigidity_iron_sword();
struct item * create_rigidity_steel_sword();

//ARMORS
struct item * create_leather_armor();
struct item * create_iron_armor();
struct item * create_steel_armor();
struct item * create_mithril_armor();
struct item * create_rigidity_leather_armor();
struct item * create_rigidity_iron_armor();
struct item * create_rigidity_steel_armor();
struct item * create_rigidity_mithril_armor();
struct item * create_strength_leather_armor();
struct item * create_strength_iron_armor();
struct item * create_strength_steel_armor();
struct item * create_strength_mithril_armor();

//POTIONS
struct item * create_health_potion();
struct item * create_strength_potion();
void print_item( struct item *item_ptr );
struct item * free_item( struct item *item_ptr );

// Backpack
struct item ** create_backpack ();
struct item ** free_backpack( struct item **backpack_ptr );
void print_backpack( struct item **backpack_ptr );
