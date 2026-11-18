#include <stdio.h>
#include <SDL/SDL.h>
#include "pobre360.h"

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
        fprintf(stderr, "SDL_Init falhou: %s\n", SDL_GetError());
        return 1;
    }

    SDL_ShowCursor(SDL_DISABLE);
    SDL_Surface *screen = SDL_SetVideoMode(P360_SCREEN_W, P360_SCREEN_H, 32, SDL_SWSURFACE);
    if (!screen) {
        fprintf(stderr, "SDL_SetVideoMode falhou: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    if (SDL_NumJoysticks() > 0) SDL_JoystickOpen(0);

    GameCatalog catalog;
    p360_catalog_load_demo(&catalog);

    int selected = 0;
    int page = 0;
    int running = 1;
    Uint32 last_move = 0;

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) running = 0;
                if (event.key.keysym.sym == SDLK_UP) selected = (selected + P360_MENU_ITEMS - 1) % P360_MENU_ITEMS;
                if (event.key.keysym.sym == SDLK_DOWN) selected = (selected + 1) % P360_MENU_ITEMS;
                if (event.key.keysym.sym == SDLK_RETURN && selected == 3) running = 0;
            }
            if (event.type == SDL_JOYBUTTONDOWN) {
                if (event.jbutton.button == 0 && selected == 3) running = 0; /* A/confirm */
                if (event.jbutton.button == 1) selected = 0; /* B/back */
            }
            if (event.type == SDL_JOYHATMOTION) {
                if (event.jhat.value & SDL_HAT_UP) selected = (selected + P360_MENU_ITEMS - 1) % P360_MENU_ITEMS;
                if (event.jhat.value & SDL_HAT_DOWN) selected = (selected + 1) % P360_MENU_ITEMS;
            }
        }

        /* Repetição simples do direcional analógico via eventos de eixo pode ser adicionada
           após validar a numeração de eixos no driver SDL do console. */
        (void)last_move;

        p360_draw_ui(screen, selected, page, &catalog);
        SDL_Flip(screen);
        SDL_Delay(16);
    }

    SDL_Quit();
    return 0;
}
