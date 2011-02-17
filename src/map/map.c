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
	map->w = map->bg->w;
	map->h = map->bg->h;
	map->nbCaseW = map->w/CSIZE;
	map->nbCaseH = map->h/CSIZE;

	map->matrice = (Case**)malloc( sizeof(Case*) * (map->nbCaseH) );
	Case* tabint = (Case*)malloc( sizeof(Case) * (map->nbCaseW) * (map->nbCaseH) );

	for(int i = 0; i < (map->nbCaseW); i++) {
		map->matrice[i] = &tabint[i*(map->nbCaseW)];
	}


	return map;
}

/**
 * \fn SDL_Surface *loadMap(char* mapName)
 * \brief load the background of the map
 *
 * \param mapName Name of the image
 * \return The array of the image
 */

SDL_Surface *loadMap(char* mapName){
	SDL_Surface* background;
	background=IMG_Load(mapName);
	if(background == NULL){
		printf("failed to load the background map\n");
		printf("IMG_Load: %s\n", IMG_GetError());
		exit(-1);
	}
	
	return background;
}
