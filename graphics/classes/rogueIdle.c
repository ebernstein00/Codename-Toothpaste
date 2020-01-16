#include "rogueIdle.h"

SDL_Rect RIframe1 = {225, 148, 24, 31 };
SDL_Rect RIframe2 = {254, 148, 24, 31 };
SDL_Rect RIframe3 = {283, 148, 24, 31 };
SDL_Rect RIdstrect = {0,0,96,124};
int RIsprite = 0;
SDL_Renderer* RIrenderer = NULL;
SDL_Surface* RIimage = NULL;
SDL_Texture* RItexture = NULL;
int RIframeTime  = 0;

void initRogueIdle(SDL_Renderer* sdlRenderer)
{
    RIrenderer = sdlRenderer;
    RIimage = IMG_Load("./sprites/rogue.png");
    SDL_SetColorKey(RIimage, SDL_TRUE, SDL_MapRGB (RIimage->format, 96, 152, 96));
    RItexture = SDL_CreateTextureFromSurface(RIrenderer, RIimage);
    RIframeTime = rand()%120 + 240;

}

void displayRogueIdle(int x, int y) {
    RIdstrect.x = x;
    RIdstrect.y = y;
    RIsprite++;
    RIsprite %= RIframeTime;
    if (RIsprite < RIframeTime - 15) {
        SDL_RenderCopy(RIrenderer, RItexture, &RIframe1, &RIdstrect);
    }
    else if (RIsprite < RIframeTime - 10) {
        SDL_RenderCopy(RIrenderer, RItexture, &RIframe2, &RIdstrect);
    }
    else if (RIsprite < RIframeTime - 5){
        SDL_RenderCopy(RIrenderer, RItexture, &RIframe3, &RIdstrect);
    }
    else {
        SDL_RenderCopy(RIrenderer, RItexture, &RIframe2, &RIdstrect);
    }
}

void destroyRogueIdle() {
    SDL_DestroyTexture(RItexture);
    SDL_FreeSurface(RIimage);
}
