#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

extern SDL_Rect RIdstrect;

void initRogueIdle(SDL_Renderer* sdlRenderer);
void displayRogueIdle(int x, int y);
void destroyRogueIdle();
