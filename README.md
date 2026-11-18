# POBRE 360 — projeto inicial

Loja/catálogo homebrew para Xbox 360 RGH/JTAG, com foco inicial em organizar **entradas de jogos GOD que o usuário já possui**.

## Estado desta versão
- Estrutura inicial do projeto.
- Interface SDL 1.2 simples: menu, navegação e catálogo de demonstração.
- Catálogo local de exemplo em `data/catalog.csv`.
- Código separado em interface, catálogo e entrada principal.
- Ainda **não** instala, descriptografa, baixa ou converte jogos GOD.
- Ainda não é um pacote XEX pronto. A saída inicial esperada com libXenon é ELF; o carregamento depende do ambiente homebrew do console.

## Plataforma
- Desenvolvimento: Android + GitHub (Termux para comandos Git/edição).
- Alvo: Xbox 360 RGH/JTAG.
- Linguagem: C.
- Gráficos: SDL 1.2 portado para libXenon (`libSDLXenon`).
- Toolchain: `xenon-gcc` / `DEVKITXENON`.

## Pastas
- `src/`: código C.
- `include/`: cabeçalhos do projeto.
- `data/`: catálogo local de demonstração.
- `assets/`: reservado para capas e fontes.
- `scripts/`: comandos auxiliares.
- `docs/`: notas de desenvolvimento.

## Compilar
Este repositório é um ponto de partida. A compilação para Xbox 360 exige toolchain libXenon e SDL Xenon instalados no ambiente de compilação. O Termux no Android pode editar e versionar o projeto, mas compilar a toolchain inteira no próprio telefone pode ser limitado; um runner Linux do GitHub Actions pode ser adicionado numa etapa posterior.

1. Instale/configure libXenon e o port SDL Xenon seguindo os projetos oficiais:
   - https://github.com/Free60Project/libxenon
   - https://github.com/LibxenonProject
   - https://github.com/lantus/libSDLXenon
2. Confirme que `xenon-gcc` está no `PATH` e que `DEVKITXENON` aponta para o SDK.
3. Ajuste `SDL_CFLAGS` e `SDL_LIBS` no `Makefile` conforme o local de instalação do SDL Xenon.
4. Execute `make`.

## Controles
- D-pad/analógico: mover seleção (quando o driver SDL expuser o controle como joystick).
- A: selecionar.
- B: voltar.
- START: sair.

## Catálogo GOD
O CSV é apenas metadado: `id,nome,categoria,descricao`.
Na próxima etapa vamos ler os dispositivos e pastas permitidas, mostrar capas e permitir que o usuário aponte para os próprios conteúdos. O aplicativo não inclui jogos comerciais nem links de cópias não autorizadas.

## Licença
Código original deste projeto: MIT. Bibliotecas externas mantêm suas próprias licenças.
