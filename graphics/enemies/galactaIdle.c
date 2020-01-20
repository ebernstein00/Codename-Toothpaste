#include "galactaIdle.h"

SDL_Rect GIframe1 = {12, 344, 79, 47 }; //45 370
SDL_Rect GIframe2 = {95, 337, 76, 52 };//128 368
SDL_Rect GIframe3 = {178, 337, 73, 52 };// 211 369
SDL_Rect GIframe4 = {259, 337, 73, 52 }; //292 370
SDL_Rect GIdstrect = {0,0,2000,150};
int GIsprite = 0;
SDL_Renderer* GIrenderer = NULL;
SDL_Surface* GIimage = NULL;
SDL_Texture* GItexture = NULL;
int GIframeTime  = 0;

void initGalactaIdle(SDL_Renderer* sdlRenderer)
{
    GIrenderer = sdlRenderer;
    GIimage = IMG_Load("./graphics/sprites/galacta.png");
    SDL_SetColorKey(GIimage, SDL_TRUE, SDL_MapRGB (GIimage->format, 79, 151, 66));
    GItexture = SDL_CreateTextureFromSurface(GIrenderer, GIimage);
    GIframeTime = rand()%30 + 60;

}

void displayGalactaIdle(int x, int y) {
    GIdstrect.x = x;
    GIdstrect.y = y;
    GIsprite++;
    GIsprite%= GIframeTime;
    if (GIsprite < GIframeTime-21) {
        GIdstrect.x = x;
        GIdstrect.y = y;
        GIdstrect.w = 316;
        GIdstrect.h = 188;
        SDL_RenderCopy(GIrenderer, GItexture, &GIframe1, &GIdstrect);
    }
    else if (GIsprite < GIframeTime-14) {
        GIdstrect.x = x;
        GIdstrect.y = y-20;
        GIdstrect.w = 304;
        GIdstrect.h = 208;
        SDL_RenderCopy(GIrenderer, GItexture, &GIframe2, &GIdstrect);
    }
    else if (GIsprite < GIframeTime-7) {
        GIdstrect.x = x;
        GIdstrect.y = y-24;
        GIdstrect.w = 292;
        GIdstrect.h = 208;
        SDL_RenderCopy(GIrenderer, GItexture, &GIframe3, &GIdstrect);
    }
    // else if (GIsprite < 32) {
    //     GIdstrect.x = x;
    //     GIdstrect.y = y-28;
    //     GIdstrect.w = 292;
    //     GIdstrect.h = 208;
    //     SDL_RenderCopy(GIrenderer, GItexture, &GIframe4, &GIdstrect);
    // }
    // else if (GIsprite < 40 ) {
    //     GIdstrect.x = x;
    //     GIdstrect.y = y-24;
    //     GIdstrect.w = 292;
    //     GIdstrect.h = 208;
    //     SDL_RenderCopy(GIrenderer, GItexture, &GIframe3, &GIdstrect);
    // }
    else {
        GIdstrect.x = x;
        GIdstrect.y = y-20;
        GIdstrect.w = 304;
        GIdstrect.h = 208;
        SDL_RenderCopy(GIrenderer, GItexture, &GIframe2, &GIdstrect);
    }
}

void destroyGalactaIdle() {
    SDL_DestroyTexture(GItexture);
    SDL_FreeSurface(GIimage);
}
