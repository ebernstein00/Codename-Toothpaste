#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./graphics/background.h"
#include "./graphics/gui.h"
#include "./graphics/display.h"
#include "./library/characters.h"
#include "./library/gameflow.h"

#define CONSUM_TYPE 1;
#define SWORD_TYPE 2;
#define ARMOR_TYPE 3;
#define NUM_ITEMS 34;

#define SCREEN_WIDTH 1100
#define SCREEN_HEIGHT 900

SDL_Window* window = NULL;

SDL_Renderer* renderer = NULL;

SDL_Rect field = {0, 0 , 700, SCREEN_HEIGHT };
SDL_Rect gui = {700, 0, 500, SCREEN_HEIGHT};
SDL_Rect defaultRect = {0,0,0,0};

bool init()
{
	//Initialization flag
	bool success = true;
	srand(time(NULL));
	//Initialframesize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "0" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( renderer == NULL )
			{
				printf( "renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
				{
				SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				// initFighterKick(renderer);
				displayInit(renderer);
				initBackground(renderer);
				initGUI(renderer);

				// This is where you load all the animations in!
			}
		}
	}

	return success;
}


void windowClose()
{

	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	window = NULL;
	renderer = NULL;
	destroyFighterIdle();
	destroyKnightIdle();
	destroyMageIdle();
	destroyRogueIdle();
	destroyDededeIdle();
	IMG_Quit();
	SDL_Quit();
}

void randomize( struct game *game) {
	int player1 = rand()%4;
	int player2 = rand()%4;
	while (player2 == player1) {
		player2 = rand()%4;
	}
	switch (player1)
	{
    case 0: game->player1 = create_fighter(1);
        break;
    case 1: game->player1 = create_knight(1);
        break;
	case 2: game->player1 = create_mage(1);
		break;
    default: game->player1 = create_rogue(1);
		break;
	}
	switch (player2)
	{
    case 0: game->player2 = create_fighter(1);
        break;
    case 1: game->player2 = create_knight(1);
        break;
	case 2: game->player2 = create_mage(1);
		break;
    default: game->player2 = create_rogue(1);
		break;
	}

	int monster1 = rand()%4;
	int monster2 = rand()%4;
	while (monster2 == monster1) {
		monster2 = rand()%4;
	}
	switch (player1)
	{
    case 0: game->monster1 = create_dedede(1);
        break;
    case 1: game->monster1 = create_knucklejoe(1);
        break;
	case 2: game->monster1 = create_waddledee(1);
		break;
    default: game->monster1 = create_waddledoo(1);
		break;
	}
	switch (player2)
	{
    case 0: game->monster2 = create_dedede(1);
        break;
    case 1: game->monster2 = create_knucklejoe(1);
        break;
	case 2: game->monster2 = create_waddledee(1);
		break;
    default: game->monster2 = create_waddledoo(1);
		break;
	}
}
void sighandler() {
	execlp("killall", "killall", "aplay", NULL);
}

int main( int argc, char* args[] )
{
	int id = 0;
    init();
	//Start up SDL and create window
    srand(time(NULL));
	int d = fork();
	if (!d ) {
		printf("HELP ME GOD %d", getpid());
		execlp("aplay", "aplay", "greengreens.wav", NULL);
		signal(SIGHUP, sighandler);
	}
    struct game *game = newgame();
    randomize(game);
    printgame(game);

	bool quit = false;
	int inputClick = 0;
    int target = 0;
    int stage = 0;
	//Event handler
	SDL_Event e;
	//While application is running
	//&& garbage_collector(game) == 0
	printf("Player 1, select your action: \n");
	while( !quit && garbage_collector(game) == 0)
	{
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            inputClick = inputGUI(e);
        }
        //Clear screen
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
        SDL_RenderSetViewport(renderer, &field);
        //Render current frame
        displayBackground();
        if (game->player1 != NULL) {
            displayCharacter(get_id(game->player1),
                ((double)get_hp(game->player1))/get_maxhp(game->player1), 50,400);
        }
        if (game->player2 != NULL) {
            displayCharacter(get_id(game->player2),
                ((double)get_hp(game->player2))/get_maxhp(game->player2), 75,600);
        }
        if (game->monster1 != NULL) {
            displayCharacter(get_id(game->monster1),
                ((double)get_hp(game->monster1))/get_maxhp(game->monster1), 450,350);
        }
        if (game->monster2 != NULL) {
            displayCharacter(get_id(game->monster2),
                ((double)get_hp(game->monster2))/get_maxhp(game->monster2), 400,625);
        }
        // displayCharacter(800,700);
        // displayCharacter(600,500);
        SDL_RenderSetViewport(renderer, &gui);
        // SDL_Rect button = {50,50, 200, 200};
        // SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        // SDL_RenderFillRect(renderer, &gui);
        displayGUIBackground();
        displayGUI(inputClick);
        //Update screen
        SDL_RenderPresent( renderer );
		if (inputClick == 4) {
			printf("Please select a target \n");
			while (target == 0) {
				if ( SDL_PollEvent( &e ) != 0 ) {
					if (game->monster1 == NULL) {
						target = targetGUI(e, defaultRect, game->monster2->rect);
					}
					else if (game->monster2 == NULL) {
						target = targetGUI(e, game->monster1->rect, defaultRect);
					}
					else {
						target = targetGUI(e, game->monster1->rect, game->monster2->rect);
						resetButtons();
					}
				}
			}
		}
        if (inputClick > 0 ) {
            if (stage == 0) {
				resetButtons();
                playerturn( game->player1, game, inputClick, target);
                inputClick = 0;
                target = 0;
                stage ++;
				printf("Player 2, select your action: \n");
            }
            else if (stage == 1) {
				resetButtons();
                playerturn( game->player2, game, inputClick, target);
                inputClick = 0;
                target = 0;
                stage ++;
                // printgame( game );
			}
            }
            else if (stage == 2) {
                if (game->monster1 != NULL) {
                    monsterturn( game->monster1, game );
					if (garbage_collector(game)) {
						freegame(game);
						windowClose();
						return 0;
					}
                }

                if (game->monster2 != NULL) {
                    monsterturn( game->monster2, game );
					if (garbage_collector(game)) {
						freegame(game);
						windowClose();
						return 0;
					}
                }
                stage++;
            }
        if (stage == 3 ) {
	        struct item *dropped_item1 = rand_item();
	        struct item *dropped_item2 = rand_item();
			printf("Player 1 Found an Item!\n");
	        dropItem(dropped_item1);
	        while (stage == 3) {
	            if ( SDL_PollEvent( &e ) != 0 ) {
	                if (e.type == SDL_KEYDOWN) {
	                    if (e.key.keysym.sym == SDLK_RETURN) {
	                        addItem(game->player1, dropped_item1, 1);
	                        stage++;
	                    }
	                    else if (e.key.keysym.sym == SDLK_BACKSPACE) {
	                        addItem(game->player1, dropped_item1, 0);
	                        stage ++;
	                    }
	                }
	            }
	        }
			printgame(game);
			printf("Player 2 Found an Item!\n");
	        dropItem(dropped_item2);
	        while (stage == 4) {
	            if ( SDL_PollEvent( &e ) != 0 ) {
	                if (e.type == SDL_KEYDOWN) {
	                    if (e.key.keysym.sym == SDLK_RETURN) {
	                        addItem(game->player2, dropped_item2, 1);
	                        stage = 0;
	                    }
	                    else if (e.key.keysym.sym == SDLK_BACKSPACE) {
	                        addItem(game->player2, dropped_item2, 0);
	                        stage = 0;
	                    	}
	                	}
	            	}
	        	}
				printgame(game);
	        }
		}
	//Free resources and close SDLprintf("--------------------- \n KILL ME \n ------------------ \n");
	// execlp("killall", "killall", "aplay", NULL);
	// signal(SIGHUP, sighandler);
	kill(getppid() + 5, SIGTERM);
    freegame(game);
	windowClose();
	exit(0);
}
