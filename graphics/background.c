#include "background.h"

SDL_Rect BGdstrect = {0,0,1100,900};
SDL_Renderer* BGrenderer = NULL;
SDL_Surface* BGimage = NULL;
SDL_Texture* BGtexture = NULL;
int BGticks = 0;

void initBackground(SDL_Renderer* sdlRenderer) {
    BGrenderer = sdlRenderer;
    BGimage = IMG_Load("./sprites/grassbackground.png");
    BGtexture = SDL_CreateTextureFromSurface(BGrenderer, BGimage);
    }

void displayBackground() {
    SDL_RenderCopy(BGrenderer, BGtexture, NULL, &BGdstrect);
}
