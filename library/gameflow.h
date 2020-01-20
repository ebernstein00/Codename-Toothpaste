struct game {
    struct being *player1;
    struct being *player2;
    struct being *monster1;
    struct being *monster2;
};


int attack(struct being * attacker, struct being * target);
int use_item(struct being * user, int item_index);
int guard_start(struct being * user);
int guard_end(struct being * user);
int monsterturn( struct being *monster, struct game *game );
int playerturn( struct being *player, struct game *game );
int freegame( struct game *game);
struct game *newgame();
void printgame( struct game *game );
int coinflip();
int garbage_collector( struct game *game );
struct item * rand_item();
