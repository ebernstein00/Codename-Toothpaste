#include "gui.h"

SDL_Rect GUIsrcrect2 = { 0, 138, 192, 46 };
SDL_Rect GUIsrcrect3 = { 0, 184, 192, 46 };
SDL_Rect GUIsrcrect4 = { 0, 0, 192, 46 };
SDL_Rect GUIsrcrect5 = { 0, 46, 192, 46 };
SDL_Rect GUIsrcrect1 = { 0, 92, 192, 46 };
SDL_Rect GUIdstrect1 = { 8, 150, 384, 92 };
SDL_Rect GUIdstrect2 = { 8, 270, 384, 92 };
SDL_Rect GUIdstrect3 = { 8, 390, 384, 92 };
SDL_Rect GUIdstrect4 = { 8, 510, 384, 92 };
SDL_Rect GUIdstrect5 = { 8, 630, 384, 92 };
SDL_Renderer* GUIrenderer = NULL;
SDL_Surface* GUIimage = NULL;
SDL_Texture* GUItexture = NULL;
int GUIticks = 0;

void initGUI(SDL_Renderer* sdlRenderer) {
    GUIrenderer = sdlRenderer;
    GUIimage = IMG_Load("./graphics/sprites/buttons.png");
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
    if (e.type == SDL_MOUSEBUTTONUP) {
        resetButtons();
    }
    else if (e.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        // printf("%d,%d", mouseX, mouseY);
        int index = 1;
        for (; index < 6; index++ ) {
            if (mouseX > 908 && mouseX < 1292 && mouseY > (30+ index * 120) && mouseY < (122+ index * 120)) {
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
int targetGUI (SDL_Event e, SDL_Rect enemy1, SDL_Rect enemy2) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        enemy1.x = 650;
        enemy1.y = 350;
        enemy2.x = 600;
        enemy2.y = 625;
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        printf("Mouse click: %d,%d \n", mouseX, mouseY);
        printf("enemy1: %d, %d, %d, %d \n", enemy1.x, enemy1.y, enemy1.w, enemy1.h);
        if (mouseX > enemy1.x && mouseX < enemy1.x + enemy1.w && mouseY > enemy1.y && mouseY < enemy1.y + enemy1.h) {
            return 1;
        }
        if (mouseX > enemy2.x && mouseX < enemy2.x + enemy2.w && mouseY > enemy2.y && mouseY < enemy2.y + enemy2.h) {
            return 2;
        }
    }
    return 0;
}




// }
