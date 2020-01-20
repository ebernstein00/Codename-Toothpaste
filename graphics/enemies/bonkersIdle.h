#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

extern SDL_Rect BIhealthrect;
extern SDL_Rect BIdstrect;

void initBonkersIdle(SDL_Renderer* sdlRenderer);
void displayBonkersIdle(int x, int y);
void destroyBonkersIdle();
