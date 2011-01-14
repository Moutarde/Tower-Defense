	#include "map.h"

Map* createMap(int w, int h, SDL_Surface* bg){
	Map* map = (Map*)malloc( sizeof(Map) );
	map->w = w;
	map->h = h;
	map->nbCaseW = w/CSIZE;
	map->nbCaseH = h/CSIZE;

	map->matrice = (Case**)malloc( sizeof(Case*)*Ch );
	Case* tabint = (Case*)malloc( sizeof(Case)*Cw*Ch );

	for(int i=0 ; i<Cw ; i++) {
		map->matrice[i] = &tabint[i*Cw];
	}

	map->bg = bg;

	return map;
}
