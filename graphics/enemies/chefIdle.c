#include "chefIdle.h"

SDL_Rect CIframe1 = {672, 33, 36, 48 };
SDL_Rect CIframe2 = {631, 33, 36, 48};
SDL_Rect CIframe3 = {590, 33, 36, 48};
SDL_Rect CIdstrect = {0,0,144,192};
int CIsprite = 0;
SDL_Renderer* CIrenderer = NULL;
SDL_Surface* CIimage = NULL;
SDL_Texture* CItexture = NULL;
int CIframeTime  = 300;

void initChefIdle(SDL_Renderer* sdlRenderer)
{
    CIrenderer = sdlRenderer;
    CIimage = IMG_Load("./graphics/sprites/chef.png");
    SDL_SetColorKey(CIimage, SDL_TRUE, SDL_MapRGB (CIimage->format, 123, 198, 255));
    CItexture = SDL_CreateTextureFromSurface(CIrenderer, CIimage);
    CIframeTime = rand()%120 + 240;

}

void displayChefIdle(int x, int y) {
    CIdstrect.x = x;
    CIdstrect.y = y;
    CIsprite++;
    CIsprite %= CIframeTime;
    if (CIsprite < CIframeTime - 15) {
        SDL_RenderCopy(CIrenderer, CItexture, &CIframe1, &CIdstrect);
    }
    else if (CIsprite < CIframeTime - 10) {
        SDL_RenderCopy(CIrenderer, CItexture, &CIframe2, &CIdstrect);
    }
    else if (CIsprite < CIframeTime - 5){
        SDL_RenderCopy(CIrenderer, CItexture, &CIframe3, &CIdstrect);
    }
    else {
        SDL_RenderCopy(CIrenderer, CItexture, &CIframe2, &CIdstrect);
    }
}

void destroyChefIdle() {
    SDL_DestroyTexture(CItexture);
    SDL_FreeSurface(CIimage);
}
