#include "waddledeeIdle.h"

SDL_Rect WIframe1 = {689, 5, 35, 46 }; //45 370
SDL_Rect WIframe2 = {652, 1, 33, 50 };//128 368
SDL_Rect WIframe3 = {616, 2, 31, 49 };// 211 369
SDL_Rect WIdstrect = {0,0,2000,150};
SDL_Rect WIhealthrect = {0,0,0,0};
int WIsprite = 0;
SDL_Renderer* WIrenderer = NULL;
SDL_Surface* WIimage = NULL;
SDL_Texture* WItexture = NULL;
int WIframeTime  = 0;

void initWaddledeeIdle(SDL_Renderer* sdlRenderer)
{
    WIrenderer = sdlRenderer;
    WIimage = IMG_Load("./graphics/sprites/waddledee.png");
    SDL_SetColorKey(WIimage, SDL_TRUE, SDL_MapRGB (WIimage->format, 104, 184, 96));
    WItexture = SDL_CreateTextureFromSurface(WIrenderer, WIimage);
    WIframeTime = 32;

}

void displayWaddledeeIdle(int x, int y) {
    WIsprite++;
    WIsprite%= WIframeTime;
    if (WIsprite < WIframeTime-24) {
        WIdstrect.x = x;
        WIdstrect.y = y;
        WIdstrect.w = 140;
        WIdstrect.h = 184;
        SDL_RenderCopy(WIrenderer, WItexture, &WIframe1, &WIdstrect);
    }
    else if (WIsprite < WIframeTime-16) {
        WIdstrect.x = x+4;
        WIdstrect.y = y-16;
        WIdstrect.w = 132;
        WIdstrect.h = 200;
        SDL_RenderCopy(WIrenderer, WItexture, &WIframe2, &WIdstrect);
    }

    else if (WIsprite < WIframeTime-8) {
        WIdstrect.x = x+8;
        WIdstrect.y = y-12;
        WIdstrect.w = 124;
        WIdstrect.h = 196;
        SDL_RenderCopy(WIrenderer, WItexture, &WIframe3, &WIdstrect);
    }
    else {
        WIdstrect.x = x+4;
        WIdstrect.y = y-16;
        WIdstrect.w = 132;
        WIdstrect.h = 200;
        SDL_RenderCopy(WIrenderer, WItexture, &WIframe2, &WIdstrect);
    }
}

void destroyWaddledeeIdle() {
    SDL_DestroyTexture(WItexture);
    SDL_FreeSurface(WIimage);
}
