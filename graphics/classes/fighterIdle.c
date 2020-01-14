#include "fighterIdle.h"

SDL_Rect FIsrcrect = { 13, 10, 35, 35 };
SDL_Rect FIdstrect = { 30, 30, 140, 140 };
int FIframes = 4;
int FIxval[4] = {13,52,90,52};
int FIsprite = 0;
SDL_Renderer* FIrenderer = NULL;
SDL_Surface* FIimage = NULL;
SDL_Texture* FItexture = NULL;

void initFighterIdle(SDL_Renderer* sdlRenderer)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    FIrenderer = sdlRenderer;
    FIimage = IMG_Load("./sprites/fighter.png");
    SDL_SetColorKey(FIimage, SDL_TRUE, SDL_MapRGB (FIimage->format, 0x78, 0xB8, 0x70));
    FItexture = SDL_CreateTextureFromSurface(FIrenderer, FIimage);

}

void displayFighterIdle() {
    FIsprite++;
    FIsprite %=240;
    if (FIsprite < 225) {
        FIsrcrect.x = FIxval[0];
    }
    else if (FIsprite < 230) {
        FIsrcrect.x = FIxval[1];
    }
    else if (FIsprite < 235){
        FIsrcrect.x = FIxval[2];
    }
    else {
        FIsrcrect.x = FIxval[1];
    }
    SDL_RenderCopy(FIrenderer, FItexture, &FIsrcrect, &FIdstrect);
}

void destroyFighterIdle() {
    SDL_DestroyTexture(FItexture);
    SDL_FreeSurface(FIimage);
}
