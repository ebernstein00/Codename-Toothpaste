#include "fighterKick.h"

SDL_Rect srcrect = {713, 10, 25, 25 };
SDL_Rect dstrect = { 100, 100, 75, 75 };
int frames = 5;
int xval[5] = {713,756,795,840,888};
int yval[5] = {163, 163, 160, 160, 160};
int sprite = 0;
SDL_Renderer* renderer = NULL;
SDL_Surface* image = NULL;
SDL_Texture* texture = NULL;

void initFighterKick(SDL_Renderer* sdlRenderer)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    renderer = sdlRenderer;
    image = IMG_Load("fighter.png");
    texture = SDL_CreateTextureFromSurface(renderer, image);

}

void displayFighterKick() {
    sprite++;
    sprite %=120;
    int x = 0;
    if (sprite < 25) {
        x = 0;
    }
    else if (sprite < 50) {
        x = 1;
    }
    else if (sprite < 75) {
        x = 2;
    }
    else if (sprite < 100) {
        x = 3;
    }
    else if (sprite < 125) {
        x = 4;
    }
    srcrect.x = x;


    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}

void destroyFighterKick() {
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
}
