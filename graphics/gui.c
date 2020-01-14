#include "gui.h"

SDL_Rect GUIsrcrect1 = { 0, 0, 192, 46 };
SDL_Rect GUIsrcrect2 = { 0, 46, 192, 46 };
SDL_Rect GUIsrcrect3 = { 0, 92, 192, 46 };
SDL_Rect GUIsrcrect4 = { 0, 138, 192, 46 };
SDL_Rect GUIsrcrect5 = { 0, 184, 192, 46 };
SDL_Rect GUIdstrect1 = { 8, 150, 384, 92 };
SDL_Rect GUIdstrect2 = { 8, 270, 384, 92 };
SDL_Rect GUIdstrect3 = { 8, 390, 384, 92 };
SDL_Rect GUIdstrect4 = { 8, 510, 384, 92 };
SDL_Rect GUIdstrect5 = { 8, 630, 384, 92 };
int GUIframes = 4;
int xval[4] = {13,52,90,52};
int GUIsprite = 0;
SDL_Renderer* GUIrenderer = NULL;
SDL_Surface* GUIimage = NULL;
SDL_Texture* GUItexture = NULL;

void initGUI(SDL_Renderer* sdlRenderer) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    GUIrenderer = sdlRenderer;
    GUIimage = IMG_Load("./sprites/buttons.png");
    GUItexture = SDL_CreateTextureFromSurface(GUIrenderer, GUIimage);
    }

void displayGUI() {
    SDL_RenderCopy(GUIrenderer, GUItexture, &GUIsrcrect1, &GUIdstrect1);
    SDL_RenderCopy(GUIrenderer, GUItexture, &GUIsrcrect2, &GUIdstrect2);
    SDL_RenderCopy(GUIrenderer, GUItexture, &GUIsrcrect3, &GUIdstrect3);
    SDL_RenderCopy(GUIrenderer, GUItexture, &GUIsrcrect4, &GUIdstrect4);
    SDL_RenderCopy(GUIrenderer, GUItexture, &GUIsrcrect5, &GUIdstrect5);

}
// char* guiInput(SDL_PollEvent e) {}


// }
