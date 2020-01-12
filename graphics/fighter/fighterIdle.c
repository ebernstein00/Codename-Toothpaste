#include "fighterIdle.h"

SDL_Rect srcrect = { 13, 10, 25, 25 };
SDL_Rect dstrect = { 10, 10, 75, 75 };
int frames = 4;
int xval[4] = {13,52,90,52};
int sprite = 0;
SDL_Renderer* renderer = NULL;
SDL_Surface* image = NULL;
SDL_Texture* texture = NULL;

void initFighterIdle(SDL_Renderer* sdlRenderer)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    renderer = sdlRenderer;
    image = IMG_Load("fighter.png");
    texture = SDL_CreateTextureFromSurface(renderer, image);

}

void displayFighterIdle() {
    sprite++;
    sprite %=240;
    if (sprite < 225) {
        srcrect.x = xval[0];
    }
    else if (sprite < 230) {
        srcrect.x = xval[1];
    }
    else if (sprite < 235){
        srcrect.x = xval[2];
    }
    else {
        srcrect.x = xval[1];
    }
    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}

void destroyFighterIdle() {
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
}
