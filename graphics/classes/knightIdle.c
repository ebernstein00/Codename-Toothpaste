#include "knightIdle.h"

SDL_Rect KIframe1 = {261, 46, 31, 48 };
SDL_Rect KIframe2 = {297, 46, 31, 48};
SDL_Rect KIframe3 = {333, 46, 31, 48};
SDL_Rect KIdstrect = {0,0,124,192};
int KIsprite = 0;
SDL_Renderer* KIrenderer = NULL;
SDL_Surface* KIimage = NULL;
SDL_Texture* KItexture = NULL;
int KIframeTime  = 150;

void initKnightIdle(SDL_Renderer* sdlRenderer)
{
    KIrenderer = sdlRenderer;
    KIimage = IMG_Load("./graphics/sprites/knight.png");
    SDL_SetColorKey(KIimage, SDL_TRUE, SDL_MapRGB (KIimage->format, 144, 208, 136));
    KItexture = SDL_CreateTextureFromSurface(KIrenderer, KIimage);
    KIframeTime = rand()%120 + 240;

}

void displayKnightIdle(int x, int y) {
    KIdstrect.x = x;
    KIdstrect.y = y;
    KIsprite++;
    KIsprite %= KIframeTime;
    if (KIsprite < KIframeTime - 15) {
        SDL_RenderCopy(KIrenderer, KItexture, &KIframe1, &KIdstrect);
    }
    else if (KIsprite < KIframeTime - 10) {
        SDL_RenderCopy(KIrenderer, KItexture, &KIframe2, &KIdstrect);
    }
    else if (KIsprite < KIframeTime - 5){
        SDL_RenderCopy(KIrenderer, KItexture, &KIframe3, &KIdstrect);
    }
    else {
        SDL_RenderCopy(KIrenderer, KItexture, &KIframe2, &KIdstrect);
    }
}

void destroyKnightIdle() {
    SDL_DestroyTexture(KItexture);
    SDL_FreeSurface(KIimage);
}
