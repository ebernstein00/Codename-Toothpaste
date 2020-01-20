#include "waddledooIdle.h"

SDL_Rect OIframe1 = {715, 53, 24, 27 }; //45 370
SDL_Rect OIframe2 = {687, 53, 25, 27 };//128 368
SDL_Rect OIframe3 = {657, 51, 27, 29 };// 211 369
SDL_Rect OIdstrect = {0,0,0,0};
SDL_Rect OIhealthrect = {0,0,0,0};
int OIsprite = 0;
SDL_Renderer* OIrenderer = NULL;
SDL_Surface* OIimage = NULL;
SDL_Texture* OItexture = NULL;
int OIframeTime  = 0;

void initWaddledooIdle(SDL_Renderer* sdlRenderer)
{
    OIrenderer = sdlRenderer;
    OIimage = IMG_Load("./graphics/sprites/waddledoo.png");
    SDL_SetColorKey(OIimage, SDL_TRUE, SDL_MapRGB (OIimage->format, 84, 109, 142));
    OItexture = SDL_CreateTextureFromSurface(OIrenderer, OIimage);
    OIframeTime = 36;

}

void displayWaddledooIdle(int x, int y) {
    OIsprite++;
    OIsprite%= OIframeTime;
    if (OIsprite < OIframeTime-27) {
        OIdstrect.x = x;
        OIdstrect.y = y;
        OIdstrect.w = 96;
        OIdstrect.h = 108;
        SDL_RenderCopy(OIrenderer, OItexture, &OIframe1, &OIdstrect);
    }
    else if (OIsprite < OIframeTime-18) {
        OIdstrect.x = x-8;
        OIdstrect.y = y;
        OIdstrect.w = 100;
        OIdstrect.h = 108;
        SDL_RenderCopy(OIrenderer, OItexture, &OIframe2, &OIdstrect);
    }

    else if (OIsprite < OIframeTime-9) {
        OIdstrect.x = x-12;
        OIdstrect.y = y-8;
        OIdstrect.w = 104;
        OIdstrect.h = 116;
        SDL_RenderCopy(OIrenderer, OItexture, &OIframe3, &OIdstrect);
    }
    else {
        OIdstrect.x = x-8;
        OIdstrect.y = y;
        OIdstrect.w = 100;
        OIdstrect.h = 108;
        SDL_RenderCopy(OIrenderer, OItexture, &OIframe2, &OIdstrect);
    }
}

void destroyWaddledooIdle() {
    SDL_DestroyTexture(OItexture);
    SDL_FreeSurface(OIimage);
}
