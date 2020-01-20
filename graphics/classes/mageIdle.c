#include "mageIdle.h"

SDL_Rect MIframe1 = {1, 53, 30, 29 };
SDL_Rect MIframe2 = {32, 53, 30, 29};
SDL_Rect MIframe3 = {63, 53, 30, 29};
SDL_Rect MIdstrect = { 30, 200, 120, 116 };
int MIframes = 4;
int MIsprite = 0;
SDL_Renderer* MIrenderer = NULL;
SDL_Surface* MIimage = NULL;
SDL_Texture* MItexture = NULL;
int MIframeTime = 0;

void initMageIdle(SDL_Renderer* sdlRenderer)
{
    MIrenderer = sdlRenderer;
    MIimage = IMG_Load("./graphics/sprites/mage.png");
    SDL_SetColorKey(MIimage, SDL_TRUE, SDL_MapRGB (MIimage->format, 101, 141, 209));
    MItexture = SDL_CreateTextureFromSurface(MIrenderer, MIimage);
    MIframeTime = rand()%120 + 240;

}

void displayMageIdle(int x, int y) {
    MIdstrect.x = x;
    MIdstrect.y = y;
    MIsprite++;
    MIsprite %=MIframeTime;
    if (MIsprite < MIframeTime - 15) {
        SDL_RenderCopy(MIrenderer, MItexture, &MIframe1, &MIdstrect);
    }
    else if (MIsprite < MIframeTime - 10) {
        SDL_RenderCopy(MIrenderer, MItexture, &MIframe2, &MIdstrect);
    }
    else if (MIsprite < MIframeTime - 5){
        SDL_RenderCopy(MIrenderer, MItexture, &MIframe3, &MIdstrect);
    }
    else {
        SDL_RenderCopy(MIrenderer, MItexture, &MIframe2, &MIdstrect);
    }
}

void destroyMageIdle() {
    SDL_DestroyTexture(MItexture);
    SDL_FreeSurface(MIimage);
}
