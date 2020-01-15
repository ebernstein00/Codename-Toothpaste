#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

extern SDL_Rect GIdstrect;

void initGalactaIdle(SDL_Renderer* sdlRenderer);
void displayGalactaIdle(int x, int y);
void destroyGalactaIdle();
