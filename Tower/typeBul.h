	#include <stdio.h>
	#include <SDL.h>

typedef struct {
	SDL_Surface* image;
	int speed;
} TypeBul;

TypeBul *createTypeBul(SDL_Surface* image, int speed);
