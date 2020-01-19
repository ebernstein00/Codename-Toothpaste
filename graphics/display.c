#include "display.h"

SDL_Renderer* DSIrenderer = NULL;
void displayInit(SDL_Renderer* renderer) {
    DSIrenderer = renderer;
    initFighterIdle(renderer);
    initMageIdle(renderer);
    initKnightIdle(renderer);
    initRogueIdle(renderer);
    initGalactaIdle(renderer);
    initDededeIdle(renderer);
    initWaddledeeIdle(renderer);
    initWaddledooIdle(renderer);
    initKnucklejoeIdle(renderer);
    initChefIdle(renderer);
    initBonkersIdle(renderer);
}

void displayHealth(double health, SDL_Rect rect) {
    SDL_Rect barEmpty = {rect.x, rect.y + rect.h + 10, 100, 10};
    SDL_Rect barHealth =  {rect.x, rect.y + rect.h + 10, (int)(100 * health), 10};
    SDL_SetRenderDrawColor(DSIrenderer, 135, 0, 0, 200);
    SDL_RenderFillRect(DSIrenderer, &barEmpty);
    SDL_SetRenderDrawColor(DSIrenderer, 255, 0, 0, 200);
    SDL_RenderFillRect(DSIrenderer, &barHealth);

}

void displayCharacter(int id, double health, int x, int y) {
    if (id == 0) {
        displayFighterIdle(x,y);
        displayHealth(health, FIdstrect);
    }
    else if (id == 1) {
        displayKnightIdle(x,y);
        displayHealth(health, KIdstrect);
    }
    else if (id == 2) {
        displayMageIdle(x,y);
        displayHealth(health, MIdstrect);
    }
    else if (id == 3) {
        displayRogueIdle(x,y);
        displayHealth(health, RIdstrect);
    }
    else if (id == 4) {
        displayBonkersIdle(x,y);
        BIhealthrect.x = x;
        BIhealthrect.y = y;
        BIhealthrect.w = 232;
        BIhealthrect.h = 228;
        displayHealth(health, BIhealthrect);
    }
    else if (id == 5) {
        displayDededeIdle(x,y);
        DIhealthrect.x = x;
        DIhealthrect.y = y;
        DIhealthrect.w = 232;
        DIhealthrect.h = 228;
        displayHealth(health, DIhealthrect);
    }
    else if (id == 6) {
        displayKnucklejoeIdle(x,y);
        JIhealthrect.x = x;
        JIhealthrect.y = y;
        JIhealthrect.w = 120;
        JIhealthrect.h = 124;
        displayHealth(health, JIhealthrect);
    }
    else if (id == 7) {
        displayWaddledeeIdle(x,y);
        WIhealthrect.x = x;
        WIhealthrect.y = y;
        WIhealthrect.w = 140;
        WIhealthrect.h = 184;
        displayHealth(health, WIhealthrect);
    }
    else if (id == 8) {
        displayWaddledooIdle(x,y);
        OIhealthrect.x = x;
        OIhealthrect.y = y;
        OIhealthrect.w = 96;
        OIhealthrect.h = 108;
        displayHealth(health, OIhealthrect);
    }

}
