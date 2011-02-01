#include "tower.h"

Tower* createTower(int x, int y, TypeTo* type) {
	Tower* tower = (Tower*)malloc( sizeof(Tower) );

	tower->x = x;
	tower->y = y;
	tower->level = 1;
	tower->kills = 0;
	tower->type= type;
	tower->damages = type->iniDamages;
	tower->range = type->iniRange;
	tower->attSpeed = type->iniAttSpeed;
	tower->sellPrice = getPrice(type->price);

	return tower;
}

int getPrice(int iniPrice) {
	return (70*iniPrice)/100;
}

void upgrade(Tower* t) {
	t->level++;
}
