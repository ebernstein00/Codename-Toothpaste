#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void initGUI(SDL_Renderer* sdlRenderer);

void displayGUI(int index);

int inputGUI(SDL_Event e);

int targetGUI(SDL_Event e, SDL_Rect enemy1, SDL_Rect enemy2);

void resetButtons();
