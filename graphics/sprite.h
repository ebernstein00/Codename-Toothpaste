#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

struct sprite {
    SDL_Renderer * renderer = NULL;
    SDL_Surface * image =NULL;
    SDL_Texture * texture = NULL;
    int number = 0;
};
