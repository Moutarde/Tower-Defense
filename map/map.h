#ifndef MAP
#define MAP

#include <stdio.h>

#include <SDL/SDL.h>

#include "case.h"

typedef struct {
	int w;
	int h;
	int nbCaseW;
	int nbCaseH;
	Case** matrice;
	SDL_Surface* bg;
} Map;

Map* createMap(int w, int h, SDL_Surface* bg);

#endif
