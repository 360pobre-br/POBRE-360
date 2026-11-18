#ifndef POBRE360_H
#define POBRE360_H

#include <SDL/SDL.h>

#define P360_SCREEN_W 1280
#define P360_SCREEN_H 720
#define P360_MENU_ITEMS 4
#define P360_MAX_GAMES 32

typedef struct {
    char id[32];
    char name[96];
    char category[48];
    char description[160];
} GameEntry;

typedef struct {
    GameEntry games[P360_MAX_GAMES];
    int count;
} GameCatalog;

void p360_draw_ui(SDL_Surface *screen, int selected, int page, const GameCatalog *catalog);
void p360_catalog_load_demo(GameCatalog *catalog);
const char *p360_menu_label(int index);

#endif
