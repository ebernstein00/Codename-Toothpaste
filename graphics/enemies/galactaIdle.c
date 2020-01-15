#include "galactaIdle.h"

SDL_Rect GIframe1 = {12, 344, 79, 47 };
SDL_Rect GIframe2 = {95, 337, 76, 52 };
SDL_Rect GIframe3 = {283, 148, 24, 31 };
SDL_Rect GIframe4 = {283, 148, 24, 31 };
SDL_Rect GIdstrect = {0,0,200,150};
int GIsprite = 0;
SDL_Renderer* GIrenderer = NULL;
SDL_Surface* GIimage = NULL;
SDL_Texture* GItexture = NULL;
int GIframeTime  = 0;

void initGalactaIdle(SDL_Renderer* sdlRenderer)
{
    GIrenderer = sdlRenderer;
    GIimage = IMG_Load("./sprites/galacta.png");
    SDL_SetColorKey(GIimage, SDL_TRUE, SDL_MapRGB (GIimage->format, 96, 152, 96));
    GItexture = SDL_CreateTextureFromSurface(GIrenderer, GIimage);
    GIframeTime = 30;
    printf("frametime: GIframeTime %d \n", GIframeTime);

}

void displayGalactaIdle(int x, int y) {
    GIdstrect.x = x;
    GIdstrect.y = y;
    GIsprite++;
    GIsprite %= GIframeTime;
    if (GIsprite < GIframeTime - 10) {
        SDL_RenderCopy(GIrenderer, GItexture, &GIframe1, &GIdstrect);
    }
    else if (GIsprite < GIframeTime ) {
        SDL_RenderCopy(GIrenderer, GItexture, &GIframe2, &GIdstrect);
    }
    // else if (GIsprite < GIframeTime - 5){
    //     SDL_RenderCopy(GIrenderer, GItexture, &GIframe3, &GIdstrect);
    // }
    // else {
    //     SDL_RenderCopy(GIrenderer, GItexture, &GIframe2, &GIdstrect);
    // }
}

void destroyGalactaIdle() {
    SDL_DestroyTexture(GItexture);
    SDL_FreeSurface(GIimage);
}
