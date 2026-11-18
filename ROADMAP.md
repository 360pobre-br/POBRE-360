# Roteiro

## Etapa 1 — Base do projeto
- [x] Estrutura C/SDL.
- [x] Menu visual inicial.
- [x] Catálogo de demonstração.
- [ ] Validar compilação no toolchain escolhido.

## Etapa 2 — Interface real
- Adicionar fonte bitmap/SDL_ttf compatível.
- Exibir textos e nomes reais.
- Implementar navegação completa por D-pad e analógico.
- Criar tela de detalhes.

## Etapa 3 — Biblioteca GOD local
- Enumerar dispositivos de armazenamento suportados pelo ambiente.
- Permitir selecionar uma pasta de catálogo.
- Ler apenas metadados e apresentar entradas de conteúdos que o usuário possui.
- Não modificar os pacotes originais.

## Etapa 4 — Capas e configuração
- Cache de imagens.
- Arquivo de configuração.
- Preferências de tema e dispositivo.

## Etapa 5 — GitHub
- Versionar o código.
- Automatizar compilação em runner compatível, após validar dependências.
- Publicar artefatos de teste.

## Limites desta versão
A primeira versão não instala nem distribui jogos comerciais. O formato GOD pode envolver estruturas e metadados específicos; suporte de leitura será implementado depois de confirmar o método de acesso e o ambiente de execução no console.
