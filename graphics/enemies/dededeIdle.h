#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

extern SDL_Rect DIhealthrect;
extern SDL_Rect DIdstrect;

void initDededeIdle(SDL_Renderer* sdlRenderer);
void displayDededeIdle(int x, int y);
void destroyDededeIdle();
