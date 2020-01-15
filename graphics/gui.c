#include "gui.h"

SDL_Rect GUIsrcrect1 = { 0, 0, 192, 46 };
SDL_Rect GUIsrcrect2 = { 0, 46, 192, 46 };
SDL_Rect GUIsrcrect3 = { 0, 92, 192, 46 };
SDL_Rect GUIsrcrect4 = { 0, 138, 192, 46 };
SDL_Rect GUIsrcrect5 = { 0, 184, 192, 46 };
SDL_Rect GUIdstrect1 = { 58, 150, 384, 92 };
SDL_Rect GUIdstrect2 = { 58, 270, 384, 92 };
SDL_Rect GUIdstrect3 = { 58, 390, 384, 92 };
SDL_Rect GUIdstrect4 = { 58, 510, 384, 92 };
SDL_Rect GUIdstrect5 = { 58, 630, 384, 92 };
SDL_Renderer* GUIrenderer = NULL;
SDL_Surface* GUIimage = NULL;
SDL_Texture* GUItexture = NULL;
int GUIticks = 0;

void initGUI(SDL_Renderer* sdlRenderer) {
    GUIrenderer = sdlRenderer;
    GUIimage = IMG_Load("./sprites/buttons.png");
    GUItexture = SDL_CreateTextureFromSurface(GUIrenderer, GUIimage);
    }

void displayGUI(int index) {
    if (index == 1) {
        GUIsrcrect1.x = 192;
    }
    else if (index == 2) {
        GUIsrcrect2.x = 192;
    }
    else if (index == 3) {
        GUIsrcrect3.x = 192;
    }
    else if (index == 4) {
        GUIsrcrect4.x = 192;
    }
    else if (index == 5) {
        GUIsrcrect5.x = 192;
    }
    SDL_RenderCopy(GUIrenderer, GUItexture, &GUIsrcrect1, &GUIdstrect1);
    SDL_RenderCopy(GUIrenderer, GUItexture, &GUIsrcrect2, &GUIdstrect2);
    SDL_RenderCopy(GUIrenderer, GUItexture, &GUIsrcrect3, &GUIdstrect3);
    SDL_RenderCopy(GUIrenderer, GUItexture, &GUIsrcrect4, &GUIdstrect4);
    SDL_RenderCopy(GUIrenderer, GUItexture, &GUIsrcrect5, &GUIdstrect5);

}

void resetButtons() {
    GUIsrcrect1.x = 0;
    GUIsrcrect2.x = 0;
    GUIsrcrect3.x = 0;
    GUIsrcrect4.x = 0;
    GUIsrcrect5.x = 0;
}
int inputGUI(SDL_Event e) {
    GUIticks ++;
    if (e.type == SDL_MOUSEBUTTONUP) {
        resetButtons();
    }
    else if (e.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        // printf("%d,%d", mouseX, mouseY);
        int index = 1;
<<<<<<< HEAD
        for (; index < 6; index++ ) {
=======
        for (; index ++; index < 5) {
>>>>>>> 6fac653d6eafd6dd5fa29bbbe6f98482dff7b7c5
            if (mouseX > 1158 && mouseX < 1542 && mouseY > (30+ index * 120) && mouseY < (122+ index * 120)) {
                printf("%d \n", index);
                if (index > 5) {
                    return 1;
                }
                else {
                    return index;
                }
            }
        }
        // resetButtons();
    }
    return 0;
}


// }
