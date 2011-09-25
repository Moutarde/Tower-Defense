/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */


#include <stdbool.h>

#include "map/map.h"
#include "enemy/enemy.h"
#include "tower/tower.h"
#include "utils/viewport.h"
#include "event/event.h"
#include "list/list.h"


// Global variables

Map* _map;
char* _path;
Case _cell; // for debug (candy_cane)

/**
 * \fn void initPath(char* argv0)
 * \brief 
 *
 * \param argv0 
 * \return 
 */
void initPath(char* argv0) {
	int trimLength = strrchr(argv0, '/') + 1 - argv0;
	_path = calloc(trimLength, 1);
	strncat(_path, argv0, trimLength);
}

/**
 * \fn char* getPath(char* resource)
 * \brief 
 *
 * \param resource 
 * \return 
 */
char* getPath(char* resource) {
	char* fullPath = calloc(strlen(_path) + strlen(resource), 1);
	return strcat(strcat(fullPath, _path), resource);
}

int main(int argc, char* argv[]) {
	// Init
	initPath(argv[0]);
	SDL_Surface* screen = NULL;
	SDL_Event event;
	bool isInPlay = true;
	void* seed;
	srand((int)seed);
	int previousTime = 0, currentTime = 0;

	SDL_Init(SDL_INIT_VIDEO);
	
	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Tower Defense", NULL);
	
	Map* map = createMap(getPath("resources/Forest.png"));
	_map = map;
	
	SDL_Rect surface = {0, 0, 640, 480};
	Viewport* viewport = createViewport(surface, map);
	
	// Creation of the enemies
	TypeEn* whiteCat = createTypeEn(100, 5, false, true, true, false, 1, getPath("resources/white_transparent_cat.png"));
	TypeEn* blackCat = createTypeEn(100, 5, false, true, true, false, 1, getPath("resources/black_transparent_cat.png"));
	TypeEn* zombie = createTypeEn(100, 5, false, true, true, false, 1, getPath("resources/zombie.png"));
	
	Enemy* cat1 = createEnemy(1, 1, whiteCat);
	Enemy* cat2 = createEnemy(1, 10, whiteCat);
	
	Enemy* cat3 = createEnemy(5, 5, blackCat);
	Enemy* cat4 = createEnemy(21, 4, blackCat);
	
	Enemy* zombie1 = createEnemy(4, 4, zombie);
	Enemy* zombie2 = createEnemy(9, 4, zombie);
	Enemy* zombie3 = createEnemy(9, 9, zombie);
	Enemy* zombie4 = createEnemy(7, 14, zombie);
	
	// Add enemy in the List
	List* catList = newList(cat4);
	pushList((void*)catList, cat2);
	pushList((void*)catList, cat3);
	pushList((void*)catList, cat1);
	
	List* zombieList = newList(zombie1);
	pushList((void*)zombieList, zombie2);
	pushList((void*)zombieList, zombie3);
	pushList((void*)zombieList, zombie4);
	
	//   removeEnemyFromList(cat4,catList);
	
	//TOWER
	TypeTo* tower = createTypeTo(0, 0, 0, 0, false, false, false, false, NULL, NULL, getPath("resources/tower.png"));
	upgradeTypeTo(tower, 0.5, getPath("resources/towerUP.png"));
	Tower* tower1 = createTower(4, 7, tower);
	
	// Main loop
	while(isInPlay) {
		// Managing the events
		SDL_PollEvent(&event);
		isInPlay = manageEvents(event, viewport);
		
		// Clean the objects on the map
		cleanMap(map);
		
		///////////////////////////// DEBUG WALL /////////////////////////////
		SDL_Rect position;
		
		for(int i=0; i < _map->nbCaseW; i++) {
			for(int j=0; j < _map->nbCaseH; j++) {
				Case cell = *getCase(i, j);
				position.x = cell.x;
				position.y = cell.y;
				if(map->matrice[i][j].hasTower == true) {
					SDL_Surface* wall = IMG_Load(getPath("resources/enemy.gif"));
					SDL_BlitSurface(wall, NULL, map->bg, &position);
				}
			}
		}
		_cell = *getCase(7, 11);
		position.x = _cell.x;
		position.y = _cell.y;
		SDL_BlitSurface(IMG_Load(getPath("resources/candy_cane.png")), NULL, map->bg, &position);
		/////////////////////////////////////////////////////////////////////
		
		// Blit enemies
		drawEnemyList(zombieList);
		drawEnemyList(catList);
		
		// Blit TOWER
		if(event.key.keysym.sym == SDLK_u) {
			upgrade(tower1);
		}
		drawTower(tower1);
		
		// Move enemies
		//moveEnemyList(zombieList);
		moveEnemyList(catList);
		
		// Blit map
		drawMap(map, &(viewport->surface), screen);
		//SDL_Delay(100);
		
		
		SDL_Flip(screen);
		
		// Managing frames
		currentTime = SDL_GetTicks();
		if (currentTime - previousTime <= 20) {
			SDL_Delay(20 - (currentTime - previousTime));
		}
		previousTime = SDL_GetTicks();
	}
	SDL_Quit();
	
	return EXIT_SUCCESS;
}
