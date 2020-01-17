#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

extern SDL_Rect KIdstrect;

void initKnightIdle(SDL_Renderer* sdlRenderer);
void displayKnightIdle(int x, int y);
void destroyKnightIdle();
