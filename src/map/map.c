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
			map->matrice[i][j].xx = i;
			map->matrice[i][j].yy = j;
			map->matrice[i][j].hasEnemy = false;
			map->matrice[i][j].hasTower = false;
		}
	}
	
	// creation of external wall
	for(int i=0;i<map->nbCaseH;i++){
	   map->matrice[i][0].hasTower = true;
	   map->matrice[i][map->nbCaseW-1].hasTower = true;
	}
   for(int j=1;j<map->nbCaseW-1;j++){
	   map->matrice[0][j].hasTower = true;
	   map->matrice[map->nbCaseH-2][j].hasTower = true;
   }	
   
   //some test wall
	map->matrice[5][10].hasTower = true;
	map->matrice[5][12].hasTower = true;
	map->matrice[6][9].hasTower = true;
	map->matrice[6][10].hasTower = true;
	map->matrice[6][12].hasTower = true;
	map->matrice[6][13].hasTower = true;
	map->matrice[8][9].hasTower = true;
	map->matrice[8][10].hasTower = true;
	map->matrice[8][12].hasTower = true;
	map->matrice[8][13].hasTower = true;
	map->matrice[9][10].hasTower = true;
	map->matrice[9][12].hasTower = true;

/*       map->matrice[7][10].hasTower = true;*/
/*     map->matrice[6][11].hasTower = true;*/
/*       map->matrice[8][11].hasTower = true;*/
/*       map->matrice[6][12].hasTower = true;*/
/*       map->matrice[6][10].hasTower = true;*/
/*     map->matrice[8][12].hasTower = true;*/
/*     map->matrice[9][12].hasTower = true;*/
/*     map->matrice[10][12].hasTower = true;*/
/*     map->matrice[11][12].hasTower = true;*/
/*     map->matrice[6][13].hasTower = true;*/
/*     map->matrice[12][13].hasTower = true;*/
/*     map->matrice[7][14].hasTower = true;*/
/*     map->matrice[8][14].hasTower = true;*/
/*     map->matrice[9][14].hasTower = true;*/
/*     map->matrice[10][14].hasTower = true;*/
/*     map->matrice[12][14].hasTower = true;*/
/*     map->matrice[8][15].hasTower = true;*/
/*     map->matrice[12][15].hasTower = true;*/
/*     map->matrice[8][16].hasTower = true;*/
/*     map->matrice[10][16].hasTower = true;*/
/*     map->matrice[11][16].hasTower = true;*/



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
 * \fn Case* getCase(int xx, int yy)
 * \brief geta Case from a map
 * \param xx the x position of a cell
 * \param yy the y position of a cell
 * \return a cell's pointer 
 */
Case* getCase(int xx, int yy){
   return &(_map->matrice[xx][yy]);
}

/**
 * \fn Case* whiteCase(int x, int y)
 * \brief get a Case from a pixel position
 * 
 * \param x X coordinate
 * \param y Y coordinate
 * \return a cell's pointer
 */
 
Case* whichCase(int x, int y){
   x /= CSIZE;
   y /= CSIZE;
  return getCase(x,y); 
}
