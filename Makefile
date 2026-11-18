# Ajuste SDL_CFLAGS e SDL_LIBS para sua instalação de libSDLXenon.
CROSS ?= xenon-
CC := $(CROSS)gcc
CFLAGS ?= -O2 -Wall -Wextra -Iinclude
SDL_CFLAGS ?=
SDL_LIBS ?= -lSDL
LDFLAGS ?=

SOURCES := src/main.c src/ui.c src/catalog.c
OBJECTS := $(SOURCES:.c=.o)
TARGET := build/pobre360.elf

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p build
	$(CC) $(OBJECTS) $(LDFLAGS) $(SDL_LIBS) -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
