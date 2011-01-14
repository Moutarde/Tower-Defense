	#include "bullet.h"

Bullet* createBullet(int x, int y, TypeBul type){
	Bullet* bullet = (Bullet*)malloc( sizeof(Bullet) );

	bullet->x = x;
	bullet->y = y;
	bullet->TypeBul = type;

	return bullet;
}
