#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

extern SDL_Rect OIhealthrect;
extern SDL_Rect OIdstrect;

void initWaddledooIdle(SDL_Renderer* sdlRenderer);
void displayWaddledooIdle(int x, int y);
void destroyWaddledooIdle();
