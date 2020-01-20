#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

extern SDL_Rect JIhealthrect;
extern SDL_Rect JIdstrect;

void initKnucklejoeIdle(SDL_Renderer* sdlRenderer);
void displayKnucklejoeIdle(int x, int y);
void destroyKnucklejoeIdle();
