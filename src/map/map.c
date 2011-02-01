#include "map.h"

Map* createMap(int w, int h, SDL_Surface* bg) {
	Map* map = (Map*)malloc( sizeof(Map) );
	map->w = w;
	map->h = h;
	map->nbCaseW = w/CSIZE;
	map->nbCaseH = h/CSIZE;

	map->matrice = (Case**)malloc( sizeof(Case*) * (map->nbCaseH) );
	Case* tabint = (Case*)malloc( sizeof(Case) * (map->nbCaseW) * (map->nbCaseH) );

	for(int i = 0; i < (map->nbCaseW); i++) {
		map->matrice[i] = &tabint[i*(map->nbCaseW)];
	}

	map->bg = bg;

	return map;
}
