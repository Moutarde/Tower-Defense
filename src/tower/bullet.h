#ifndef BULLET
#define BULLET

#include <stdio.h>

#include "typeBul.h"

typedef struct {
	int x;
	int y;
	TypeBul type;
} Bullet;

Bullet* createBullet(int x, int y, TypeBul type);

#endif
