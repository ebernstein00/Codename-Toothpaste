#include "background.h"

SDL_Rect BGdstrect = {0,0,900,900};
SDL_Rect GBGdstrect = {0, 0, 400, 900};
SDL_Renderer* BGrenderer = NULL;
SDL_Surface* BGimage = NULL;
SDL_Texture* BGtexture = NULL;
SDL_Surface* GBGimage = NULL;
SDL_Texture* GBGtexture = NULL;
int BGticks = 0;

void initBackground(SDL_Renderer* sdlRenderer) {
    BGrenderer = sdlRenderer;
    BGimage = IMG_Load("./graphics/sprites/grassbackground.png");
    BGtexture = SDL_CreateTextureFromSurface(BGrenderer, BGimage);
    GBGimage = IMG_Load("./graphics/sprites/guibackground.png");
    GBGtexture = SDL_CreateTextureFromSurface(BGrenderer, GBGimage);
    }

void displayBackground() {
    SDL_RenderCopy(BGrenderer, BGtexture, NULL, &BGdstrect);
}

void displayGUIBackground() {
    SDL_RenderCopy(BGrenderer, GBGtexture, NULL, &GBGdstrect);
}
