#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

extern SDL_Rect FIdstrect;

void initFighterIdle(SDL_Renderer* sdlRenderer);
void displayFighterIdle(int x, int y);
void destroyFighterIdle();
