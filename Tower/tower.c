	#include "tower.h"

Tower* createTower(int x, int y, TypeTo type) {
	Tower* tower = (Tower*)malloc( sizeof(Tower) );

	tower->x = x;
	tower->y = y;
	tower->level = 1;
	tower->kills = 0;
	tower->TypeTo = type;
	tower->damages = type->iniDamages;
	tower->range = type->iniRange;
	tower->attSpeed = type->iniAttSpeed;
	tower->sellPrice = get_price(type->price);

	return tower;
}

int get_price(int iniPrice) {
	return (70*iniPrice)/100;
}

void upgrade(Tower* t) {
	t->level++;
}
