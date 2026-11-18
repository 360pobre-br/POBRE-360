#include "pobre360.h"

static Uint32 rgb(SDL_Surface *s, Uint8 r, Uint8 g, Uint8 b) {
    return SDL_MapRGB(s->format, r, g, b);
}

static void fill(SDL_Surface *s, int x, int y, int w, int h, Uint32 color) {
    SDL_Rect r = {(Sint16)x, (Sint16)y, (Uint16)w, (Uint16)h};
    SDL_FillRect(s, &r, color);
}

/* Sem fonte externa nesta primeira compilação: blocos e textos serão adicionados
   quando a biblioteca SDL_ttf estiver validada no ambiente Xenon. */
const char *p360_menu_label(int index) {
    static const char *labels[P360_MENU_ITEMS] = {
        "BIBLIOTECA GOD", "APLICATIVOS", "CONFIGURACOES", "SAIR"
    };
    if (index < 0 || index >= P360_MENU_ITEMS) return "";
    return labels[index];
}

void p360_draw_ui(SDL_Surface *screen, int selected, int page, const GameCatalog *catalog) {
    (void)page;
    SDL_FillRect(screen, NULL, rgb(screen, 12, 17, 28));

    fill(screen, 0, 0, P360_SCREEN_W, 104, rgb(screen, 20, 31, 49));
    fill(screen, 42, 30, 12, 42, rgb(screen, 0, 190, 170));
    fill(screen, 70, 28, 390, 46, rgb(screen, 38, 55, 78));

    /* Cartões de navegação */
    for (int i = 0; i < P360_MENU_ITEMS; i++) {
        Uint32 c = (i == selected) ? rgb(screen, 0, 125, 120) : rgb(screen, 28, 41, 60);
        fill(screen, 48, 145 + i * 92, 330, 68, c);
        fill(screen, 62, 160 + i * 92, 8, 38,
             (i == selected) ? rgb(screen, 230, 245, 245) : rgb(screen, 90, 112, 135));
        /* Marcador visual; os rótulos completos estão no README até integrar fonte. */
        fill(screen, 86, 164 + i * 92, 210 - (i * 13), 28, rgb(screen, 170, 190, 210));
    }

    /* Painel de conteúdo */
    fill(screen, 420, 145, 810, 430, rgb(screen, 20, 30, 45));
    for (int i = 0; i < catalog->count && i < 4; i++) {
        int x = 455 + i * 185;
        fill(screen, x, 190, 155, 210, rgb(screen, 36, 54, 75));
        fill(screen, x + 16, 210, 123, 135, rgb(screen, 50 + i * 8, 78 + i * 6, 100 + i * 5));
        fill(screen, x + 16, 360, 123, 10, rgb(screen, 180, 195, 210));
        fill(screen, x + 16, 380, 85, 7, rgb(screen, 95, 130, 155));
    }

    fill(screen, 48, 640, 1184, 2, rgb(screen, 45, 65, 85));
    fill(screen, 48, 660, 220, 12, rgb(screen, 90, 112, 135));
    fill(screen, 280, 660, 160, 12, rgb(screen, 60, 90, 115));
}
