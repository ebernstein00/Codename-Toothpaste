#include "dededeIdle.h"

SDL_Rect DIframe1 = {578, 7, 58, 57 }; //45 370
SDL_Rect DIframe2 = {641, 9, 60, 55 };//128 368
SDL_Rect DIframe3 = {706, 8, 60, 56 };// 211 369
SDL_Rect DIframe4 = {771, 6, 58, 58 }; //292 370
SDL_Rect DIdstrect = {0,0,2000,150};
SDL_Rect DIhealthrect = {0,0,0,0};
int DIsprite = 0;
SDL_Renderer* DIrenderer = NULL;
SDL_Surface* DIimage = NULL;
SDL_Texture* DItexture = NULL;
int DIframeTime  = 0;

void initDededeIdle(SDL_Renderer* sdlRenderer)
{
    DIrenderer = sdlRenderer;
    DIimage = IMG_Load("./sprites/dedede.png");
    SDL_SetColorKey(DIimage, SDL_TRUE, SDL_MapRGB (DIimage->format, 176, 160, 208));
    DItexture = SDL_CreateTextureFromSurface(DIrenderer, DIimage);
    DIframeTime = 28;

}

void displayDededeIdle(int x, int y) {
    DIdstrect.x = x;
    DIdstrect.y = y;
    DIsprite++;
    DIsprite%= DIframeTime;
    if (DIsprite < DIframeTime-21) {
        DIdstrect.x = x+8;
        DIdstrect.y = y;
        DIdstrect.w = 232;
        DIdstrect.h = 228;
        SDL_RenderCopy(DIrenderer, DItexture, &DIframe1, &DIdstrect);
    }
    else if (DIsprite < DIframeTime-14) {
        DIdstrect.x = x+4;
        DIdstrect.y = y+8;
        DIdstrect.w = 240;
        DIdstrect.h = 220;
        SDL_RenderCopy(DIrenderer, DItexture, &DIframe2, &DIdstrect);
    }
    else if (DIsprite < DIframeTime-7) {
        DIdstrect.x = x+8;
        DIdstrect.y = y+4;
        DIdstrect.w = 240;
        DIdstrect.h = 224;
        SDL_RenderCopy(DIrenderer, DItexture, &DIframe3, &DIdstrect);
    }

    else {
        DIdstrect.x = x+12;
        DIdstrect.y = y-4;
        DIdstrect.w = 232;
        DIdstrect.h = 232;
        SDL_RenderCopy(DIrenderer, DItexture, &DIframe4, &DIdstrect);
    }
}

void destroyDededeIdle() {
    SDL_DestroyTexture(DItexture);
    SDL_FreeSurface(DIimage);
}
