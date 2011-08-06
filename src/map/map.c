/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "map.h"

/**
 * \fn Map* createMap(char* mapName)
 * \brief create a map.
 *
 * \param mapName The Path of map's background.
 * \return The array on the map, in order to use it.
 */

Map* createMap(char* mapName) {
	Map* map = (Map*)malloc( sizeof(Map) );
	map->bg = loadMap(mapName);
	map->bg_img = loadMap(mapName);
	map->w = map->bg->w;
	map->h = map->bg->h;
	map->nbCaseW = map->w/CSIZE;
	map->nbCaseH = map->h/CSIZE;
	
	map->matrice = (Case**)malloc( sizeof(Case*) * (map->nbCaseH) );
	Case* tabint = (Case*)malloc( sizeof(Case) * (map->nbCaseW) * (map->nbCaseH) );
	
	for(int i = 0; i < (map->nbCaseW); i++) {
		map->matrice[i] = &tabint[i*(map->nbCaseW)];
	}
	
   // initialization of Case
	for(int i = 0; i < (map->nbCaseW); i++) {
		for(int j = 0; j < (map->nbCaseH); j++) {
			map->matrice[i][j].x = i*CSIZE;
			map->matrice[i][j].y = j*CSIZE;
			map->matrice[i][j].hasEnemy = false;
			map->matrice[i][j].hasTower = false;
		}
	}
	
	return map;
}

/**
 * \fn SDL_Surface* loadMap(char* mapName)
 * \brief load the background of the map
 *
 * \param mapName Name of the image
 * \return The array of the image
 */

SDL_Surface* loadMap(char* mapName){
	SDL_Surface* background;
	background = IMG_Load(mapName);
	if(background == NULL){
		printf("failed to load the background map\n");
		printf("IMG_Load: %s\n", IMG_GetError());
		exit(-1);
	}
	
	return background;
}

/**
 * \fn void* drawMap(Map* map, SDL_Rect* viewport, SDL_Surface* screen)
 * \brief Draws a map on the screen
 *
 * \param map Map to draw
 * \param viewport Viewport
 * \param screen Where to draw
 */
void drawMap(Map* map, SDL_Rect* viewport, SDL_Surface* screen) {
	SDL_BlitSurface(map->bg, viewport, screen, NULL);
}

/**
 * \fn void* cleanMap(Map* map)
 * \brief Cleans the map.
 *
 * \param map Map to clean
 */
void cleanMap(Map* map) {
	SDL_BlitSurface(map->bg_img, NULL, map->bg, NULL);
}

/**
 * \fn Case* getCase(int x, int y, Map *map)
 * \brief geta Case from a map
 * \param x the x position of a cell
 * \param y the y position of a cell
 * \return a cell's pointer 
 */
Case getCase(int x, int y){
   return _map->matrice[x][y];
}
