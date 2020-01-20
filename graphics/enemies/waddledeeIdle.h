#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

extern SDL_Rect WIhealthrect;
extern SDL_Rect WIdstrect;

void initWaddledeeIdle(SDL_Renderer* sdlRenderer);
void displayWaddledeeIdle(int x, int y);
void destroyWaddledeeIdle();
