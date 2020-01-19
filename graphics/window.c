#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./classes/fighterIdle.h"
#include "./classes/mageIdle.h"
#include "./classes/rogueIdle.h"
#include "./classes/knightIdle.h"
#include "./enemies/galactaIdle.h"
#include "./enemies/dededeIdle.h"
#include "./enemies/waddledeeIdle.h"
#include "./enemies/waddledooIdle.h"
#include "./enemies/knucklejoeIdle.h"
#include "./enemies/chefIdle.h"
#include "./enemies/bonkersIdle.h"
#include "background.h"
#include "gui.h"
#include "display.h"

//Screen dimension constants
#define SCREEN_WIDTH 1300
#define SCREEN_HEIGHT 900

//The window we'll be rendering to
SDL_Window* window = NULL;

SDL_Renderer* renderer = NULL;

SDL_Rect field = {0, 0 , 900, SCREEN_HEIGHT };
SDL_Rect gui = {900, 0, 500, SCREEN_HEIGHT};

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
		//Set texture filtering to linear
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
				//Initialize renderer color
				SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
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

	//Destroy window
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	window = NULL;
	renderer = NULL;
	destroyFighterIdle();
	destroyKnightIdle();
	destroyMageIdle();
	destroyRogueIdle();
	destroyDededeIdle();
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{

			bool quit = false;
			int inputClick = 0;
			//Event handler
			SDL_Event e;

			//Current animation frame

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					inputClick = inputGUI(e);
					if (inputClick) {
						printf("GUI input: %d \n", inputClick);
					}
				}
				//Clear screen
				SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( renderer );
				SDL_RenderSetViewport(renderer, &field);
				//Render current frame
				displayBackground();
				displayCharacter(0, 0.6, 100,300);
				displayCharacter(1, 0.7, 220,420);
				displayCharacter(2, 0.8, 100,500);
				displayCharacter(3, 0.9, 250,700);
				displayCharacter(4, 1, 700,500);
				displayCharacter(5, 0.8, 800,200);
				displayCharacter(6, 0.7, 700,100);
				displayCharacter(7, 0.2, 700,300);
				displayCharacter(8, 0, 600,700);
				// displayCharacter(800,700);
				// displayCharacter(600,500);
				SDL_RenderSetViewport(renderer, &gui);
				// SDL_Rect button = {50,50, 200, 200};
				// SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
				// SDL_RenderFillRect(renderer, &gui);
				displayGUIBackground();
				displayGUI(inputClick);
				// SDL_RenderClear(renderer);
				//Update screen
				SDL_RenderPresent( renderer );
				//Go to next frame
				//Cycle animation
			}
		}
	// }

	//Free resources and close SDL
	windowClose();

	return 0;
}
