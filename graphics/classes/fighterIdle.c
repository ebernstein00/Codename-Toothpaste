#include "fighterIdle.h"

SDL_Rect FIsrcrect = { 13, 10, 26, 23 };
SDL_Rect FIdstrect = { 300, 300, 104, 92 };
int FIframes = 4;
int FIxval[4] = {13,52,90,52};
int FIsprite = 0;
SDL_Renderer* FIrenderer = NULL;
SDL_Surface* FIimage = NULL;
SDL_Texture* FItexture = NULL;
int FIframeTime  = 0;

void initFighterIdle(SDL_Renderer* sdlRenderer)
{
    FIrenderer = sdlRenderer;
    FIimage = IMG_Load("./sprites/fighter.png");
    SDL_SetColorKey(FIimage, SDL_TRUE, SDL_MapRGB (FIimage->format, 0x78, 0xB8, 0x70));
    FItexture = SDL_CreateTextureFromSurface(FIrenderer, FIimage);
    FIframeTime = rand()%120 + 240;
    printf("frametime: FIframeTime %d \n", FIframeTime);

}

void displayFighterIdle(int x, int y) {
    FIdstrect.x = x;
    FIdstrect.y = y;
    FIsprite++;
    FIsprite %= FIframeTime;
    if (FIsprite < FIframeTime - 15) {
        FIsrcrect.x = FIxval[0];
    }
    else if (FIsprite < FIframeTime - 10) {
        FIsrcrect.x = FIxval[1];
    }
    else if (FIsprite < FIframeTime - 5){
        FIsrcrect.x = FIxval[2];
    }
    else {
        FIsrcrect.x = FIxval[3];
    }
    SDL_RenderCopy(FIrenderer, FItexture, &FIsrcrect, &FIdstrect);
}

void destroyFighterIdle() {
    SDL_DestroyTexture(FItexture);
    SDL_FreeSurface(FIimage);
}
