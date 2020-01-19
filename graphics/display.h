#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./classes/fighterIdle.h"
#include "./classes/mageIdle.h"
#include "./classes/rogueIdle.h"
#include "./classes/knightIdle.h"
#include "./enemies/galactaIdle.h"
#include "./enemies/dededeIdle.h"
#include "./enemies/waddledeeIdle.h"
#include "./enemies/waddledooIdle.h"
#include "./enemies/knucklejoeIdle.h"
#include "./enemies/chefIdle.h"
#include "./enemies/bonkersIdle.h"

void displayInit();

void displayHealth(double health, SDL_Rect rect);

void displayCharacter(int id, double health, int x, int y);
