#include "knucklejoeIdle.h"

SDL_Rect JIframe1 = {184, 42, 30, 31 }; //45 370
SDL_Rect JIframe2 = {149, 41, 30, 31 };//128 368
SDL_Rect JIframe3 = {113, 42, 31, 31 };// 211 369
SDL_Rect JIdstrect = {0,0,0,0};
int JIsprite = 0;
SDL_Renderer* JIrenderer = NULL;
SDL_Surface* JIimage = NULL;
SDL_Texture* JItexture = NULL;
int JIframeTime  = 0;

void initKnucklejoeIdle(SDL_Renderer* sdlRenderer)
{
    JIrenderer = sdlRenderer;
    JIimage = IMG_Load("./sprites/knucklejoe.png");
    SDL_SetColorKey(JIimage, SDL_TRUE, SDL_MapRGB (JIimage->format, 160, 208, 98));
    JItexture = SDL_CreateTextureFromSurface(JIrenderer, JIimage);
    JIframeTime = 36;

}

void displayKnucklejoeIdle(int x, int y) {
    JIsprite++;
    JIsprite%= JIframeTime;
    if (JIsprite < JIframeTime-27) {
        JIdstrect.x = x;
        JIdstrect.y = y;
        JIdstrect.w = 120;
        JIdstrect.h = 124;
        SDL_RenderCopy(JIrenderer, JItexture, &JIframe1, &JIdstrect);
    }
    else if (JIsprite < JIframeTime-18) {
        JIdstrect.x = x;
        JIdstrect.y = y+4;
        JIdstrect.w = 120;
        JIdstrect.h = 124;
        SDL_RenderCopy(JIrenderer, JItexture, &JIframe2, &JIdstrect);
    }

    else if (JIsprite < JIframeTime-9) {
        JIdstrect.x = x;
        JIdstrect.y = y+4;
        JIdstrect.w = 124;
        JIdstrect.h = 124;
        SDL_RenderCopy(JIrenderer, JItexture, &JIframe3, &JIdstrect);
    }
    else {
        JIdstrect.x = x;
        JIdstrect.y = y-4;
        JIdstrect.w = 120;
        JIdstrect.h = 124;
        SDL_RenderCopy(JIrenderer, JItexture, &JIframe2, &JIdstrect);
    }
}

void destroyKnucklejoeIdle() {
    SDL_DestroyTexture(JItexture);
    SDL_FreeSurface(JIimage);
}
