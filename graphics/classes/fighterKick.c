#include "fighterKick.h"

SDL_Rect FKsrcrect = {713, 10, 25, 25 };
SDL_Rect FKdstrect = { 100, 100, 75, 75 };
int FKframes = 5;
int FKxval[5] = {713,756,795,840,888};
int FKyval[5] = {163, 163, 160, 160, 160};
int FKsprite = 0;
SDL_Renderer* FKrenderer = NULL;
SDL_Surface* FKimage = NULL;
SDL_Texture* FKtexture = NULL;

void initFighterKick(SDL_Renderer* sdlRenderer)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    FKrenderer = sdlRenderer;
    FKimage = IMG_Load("./sprites/fighter.png");
    FKtexture = SDL_CreateTextureFromSurface(FKrenderer, FKimage);

}

void displayFighterKick() {
    FKsprite++;
    FKsprite %=120;
    int x = 0;
    if (FKsprite < 25) {
        x = 0;
    }
    else if (FKsprite < 50) {
        x = 1;
    }
    else if (FKsprite < 75) {
        x = 2;
    }
    else if (FKsprite < 100) {
        x = 3;
    }
    else if (FKsprite < 125) {
        x = 4;
    }
    FKsrcrect.x = FKxval[x];
    FKsrcrect.y = FKyval[x];


    SDL_RenderCopy(FKrenderer, FKtexture, &FKsrcrect, &FKdstrect);
}

void destroyFighterKick() {
    SDL_DestroyTexture(FKtexture);
    SDL_FreeSurface(FKimage);
}
