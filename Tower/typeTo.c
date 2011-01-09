	#include "typeTo.h"

TypeTo *createTypeTo(SDL_Surface* image, int iniDamages, int iniRange, int iniAttSpeed, int price, int isSplash, int isSlower, int canAttackFlying, int canPoison, TypeBul typeBul){

	TypeTo *typeTo = (TypeTo*)malloc( sizeof(TypeTo) );

	typeTo->image = image;
	typeTo->iniDamages = iniDamages;
	typeTo->iniRange = iniRange;
	typeTo->iniAttSpeed = iniAttSpeed;
	typeTo->price = price;
	typeTo->isSplash = isSplash;
	typeTo->isSlower = isSlower;
	typeTo->canAttackFlying = canAttackFlying;
	typeTo->canPoison = canPoison;
	typeTo->typeBul = typeBul;

	return typeTo;
}
