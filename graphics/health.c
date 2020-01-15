#include "health.h"

void displayHealth(double health, SDL_Rect rect, SDL_Renderer* renderer) {
    SDL_Rect barEmpty = {rect.x, rect.y + rect.h + 10, 100, 10};
    SDL_Rect barHealth =  {rect.x, rect.y + rect.h + 10, (int)(100 * health), 10};
    SDL_SetRenderDrawColor(renderer, 135, 0, 0, 200);
    SDL_RenderFillRect(renderer, &barEmpty);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 200);
    SDL_RenderFillRect(renderer, &barHealth);

}
