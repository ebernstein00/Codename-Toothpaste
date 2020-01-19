#include "bonkersIdle.h"

SDL_Rect BIframe1 = {706, 292, 37, 44 };
SDL_Rect BIframe2 = {661, 290, 41, 46};
SDL_Rect BIframe3 = {616, 289, 40, 47};
SDL_Rect BIdstrect = {0,0,144,192};
SDL_Rect BIhealthrect = {0,0,0,0};
int BIsprite = 0;
SDL_Renderer* BIrenderer = NULL;
SDL_Surface* BIimage = NULL;
SDL_Texture* BItexture = NULL;
int BIframeTime  = 0;

void initBonkersIdle(SDL_Renderer* sdlRenderer)
{
    BIrenderer = sdlRenderer;
    BIimage = IMG_Load("./sprites/chef.png");
    SDL_SetColorKey(BIimage, SDL_TRUE, SDL_MapRGB (BIimage->format, 123, 198, 255));
    BItexture = SDL_CreateTextureFromSurface(BIrenderer, BIimage);
    BIframeTime = 36;
}

void displayBonkersIdle(int x, int y) {
    BIdstrect.x = x;
    BIdstrect.y = y;
    BIsprite++;
    BIsprite %= BIframeTime;
    if (BIsprite < BIframeTime-27) {
        BIdstrect.x = x-4;
        BIdstrect.y = y-24;
        BIdstrect.w = 164;
        BIdstrect.h = 200;
        SDL_RenderCopy(BIrenderer, BItexture, &BIframe2, &BIdstrect);
    }
    else if (BIsprite < BIframeTime-18) {

        BIdstrect.x = x-8;
        BIdstrect.y = y-12;
        BIdstrect.w = 160;
        BIdstrect.h = 188;
        SDL_RenderCopy(BIrenderer, BItexture, &BIframe3, &BIdstrect);
    }

    else if (BIsprite < BIframeTime-9) {
        BIdstrect.x = x;
        BIdstrect.y = y;
        BIdstrect.w = 148;
        BIdstrect.h = 176;
        SDL_RenderCopy(BIrenderer, BItexture, &BIframe1, &BIdstrect);
    }
    else {
        BIdstrect.x = x-8;
        BIdstrect.y = y-12;
        BIdstrect.w = 160;
        BIdstrect.h = 188;
        SDL_RenderCopy(BIrenderer, BItexture, &BIframe3, &BIdstrect);
    }
}

void destroyBonkersIdle() {
    SDL_DestroyTexture(BItexture);
    SDL_FreeSurface(BIimage);
}
