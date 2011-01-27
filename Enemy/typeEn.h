#ifndef TYPEEN_H
#define TYPEEN_H

#include <stdio.h>

#include <SDL/SDL.h>

typedef struct {
	int maxLife;
	SDL_Surface* image;
	int normalSpeed;
	int canFly;
	int canBeSlowed;
	int canBePoisoned;
	int invisible;
	int armor;
} TypeEn;

TypeEn* createTypeEn(int maxLife, SDL_Surface* image, int normalSpeed, int canFly, int canBeSlowed, int canBePoisoned, int invisible, int armor);

#endif

