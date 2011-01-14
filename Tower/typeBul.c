	#include "typeBul.h"

TypeBul* createTypeBul(SDL_Surface* image, int speed) {

	TypeBul* typeBul = (TypeBul*)malloc( sizeof(TypeBul) );

	typeBul->image = image;
	typeBul->speed = speed;

	return typeBul;
}
