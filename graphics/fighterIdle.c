#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include "sprite.h"

SDL_Rect srcrect = { 0, 0, 32, 64 };
SDL_Rect dstrect = { 10, 10, 32, 64 };

sprite createFighterIdle(SDL_Window * window)
{
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    struct sprite fighter = {
    SDL_CreateRenderer(window, -1, 0),
    IMG_Load("fighter.png"),
    SDL_CreateTextureFromSurface(renderer, image),
    1
    };
    return fighter;
}

void displayFighterIdle(SDL_Renderer * renderer,
    SDL_Surface * image, SDL_Texture * texture, SDL_Rect, ) {
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

int destroyFighterIdle(SDL_Renderer * renderer,
    SDL_Surface * image, SDL_Texture * texture) {
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(image);
        SDL_DestroyRenderer(renderer);
}
