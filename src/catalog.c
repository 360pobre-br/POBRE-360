#include <string.h>
#include "pobre360.h"

void p360_catalog_load_demo(GameCatalog *catalog) {
    memset(catalog, 0, sizeof(*catalog));

    strcpy(catalog->games[0].id, "DEMO001");
    strcpy(catalog->games[0].name, "Meu jogo GOD");
    strcpy(catalog->games[0].category, "Biblioteca local");
    strcpy(catalog->games[0].description, "Entrada de demonstração; configure seu próprio conteúdo.");

    strcpy(catalog->games[1].id, "DEMO002");
    strcpy(catalog->games[1].name, "Aplicativo homebrew");
    strcpy(catalog->games[1].category, "Aplicativos");
    strcpy(catalog->games[1].description, "Espaço reservado para aplicativos homebrew.");

    catalog->count = 2;
}
