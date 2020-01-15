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
<<<<<<< HEAD
#include "./enemies/galactaIdle.h"
#include "background.h"
#include "gui.h"
#include "health.h"
=======
#include "background.h"
#include "gui.h"
>>>>>>> 6fac653d6eafd6dd5fa29bbbe6f98482dff7b7c5

//Screen dimension constants
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

//The window we'll be rendering to
SDL_Window* window = NULL;

SDL_Renderer* renderer = NULL;

SDL_Rect field = {0, 0 , 1100, SCREEN_HEIGHT };
SDL_Rect gui = {1100, 0, 500, SCREEN_HEIGHT};
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
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
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
				initFighterIdle(renderer);
				initMageIdle(renderer);
				initKnightIdle(renderer);
				initRogueIdle(renderer);
<<<<<<< HEAD
				initGalactaIdle(renderer);
=======
>>>>>>> 6fac653d6eafd6dd5fa29bbbe6f98482dff7b7c5
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
<<<<<<< HEAD
	destroyKnightIdle();
	destroyMageIdle();
	destroyRogueIdle();
=======
>>>>>>> 6fac653d6eafd6dd5fa29bbbe6f98482dff7b7c5
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
				displayFighterIdle(100,300);
				displayMageIdle(220,420);
				displayKnightIdle(100,500);
				displayRogueIdle(250,700);
<<<<<<< HEAD
				displayGalactaIdle(700,500);
				displayHealth(0.6, FIdstrect, renderer);
=======
>>>>>>> 6fac653d6eafd6dd5fa29bbbe6f98482dff7b7c5
				SDL_RenderSetViewport(renderer, &gui);
				// SDL_Rect button = {50,50, 200, 200};
				// SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
				// SDL_RenderFillRect(renderer, &gui);
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
