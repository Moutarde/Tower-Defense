/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */


#include "map/map.h"
#include "enemy/enemy.h"
#include "tower/tower.h"
#include "utils/viewport.h"
#include "event/event.h"
#include <stdbool.h>
#include "list/list.h"

Map *_map;
char* _path;
Case cell; // for debug (candy_cane)


void initPath(char* argv0){
   int trimLength = strrchr(argv0,'/')+1-argv0;
   _path = calloc(trimLength,1);
   strncat(_path,argv0,trimLength);
}

char* getPath(char* resource){
   char* fullPath = calloc(strlen(_path)+strlen(resource),1);
   return strcat(strcat(fullPath,_path),resource);
}

int main(int argc, char *argv[]) {
	// Init
	initPath(argv[0]);
	SDL_Surface* screen = NULL;
	SDL_Event event;
	bool isInPlay = true;
//   void* seed;
   int seed = 42;
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
	TypeEn* whiteCat = createTypeEn(100, 5, false, true, true, false, 1,getPath("resources/white_transparent_cat.png"));
	TypeEn* blackCat = createTypeEn(100, 5, false, true, true, false, 1,getPath("resources/black_transparent_cat.png"));
	Enemy* cat1 = createEnemy(1,1,whiteCat);
	Enemy* cat2 = createEnemy(1,10,whiteCat);
	Enemy* cat3 = createEnemy(5,5,blackCat);
	Enemy* cat4 = createEnemy(21,4,blackCat);
	
   TypeEn *zombie = createTypeEn(100,5,false,true,true,false,1,getPath("resources/zombie.png"));
   Enemy *zombie1 = createEnemy(4,4,zombie);
   Enemy *zombie2 = createEnemy(9,4,zombie);
   Enemy *zombie3 = createEnemy(9,9,zombie);
   Enemy *zombie4 = createEnemy(7,14,zombie);

   //Add enemy in the List
   EnemyList *catList = newEnemyList(cat4);
   popEnemy(catList,cat2);
   popEnemy(catList,cat3);
   popEnemy(catList,cat1);
   
   EnemyList *zombieList = newEnemyList(zombie1);
   popEnemy(zombieList,zombie2);
   popEnemy(zombieList,zombie3);
   popEnemy(zombieList,zombie4);
   

   //TOWER
   TypeTo *tower = createTypeTo(0,0,0,0,false,false,false,false,NULL,getPath("resources/tower.png"));
   Tower *tower1 = createTower(4,7,tower);


	// Main loop
	while(isInPlay) {
		// Managing the events
		SDL_PollEvent( &event );
		isInPlay = manageEvents(event, viewport);

		// Clean the objects on the map
		cleanMap(map);
///////////////////////////// DEBUG WALL /////////////////////////////
   SDL_Rect position;

	for(int i=0;i < _map->nbCaseW;i++){
		for(int j=0;j < _map->nbCaseH;j++){
		   Case cell = *getCase(i,j);
		   position.x = cell.x;
		   position.y = cell.y;
			if(map->matrice[i][j].hasTower == true){
            SDL_Surface *wall = IMG_Load(getPath("resources/enemy.gif"));
			   SDL_BlitSurface(wall,NULL,map->bg,&position);
			}
		}
	}
	cell = *getCase(7,11);
	position.x = cell.x;
	position.y = cell.y;
   SDL_BlitSurface(IMG_Load(getPath("resources/candy_cane.png")),NULL,map->bg,&position);
/////////////////////////////////////////////////////////////////////
		
		// Blit enemies
      drawEnemyList(zombieList);
      drawEnemyList(catList);
      //Blit TOWER
      drawTower(tower1);
      
      // Move enemies
      moveEnemyList(zombieList);
      moveEnemyList(catList);
      
		// Blit map
		drawMap(map, &(viewport->surface), screen);
//      SDL_Delay(100);



		SDL_Flip(screen);
		
		// Managing frames
		currentTime = SDL_GetTicks();
		if (currentTime - previousTime <= 20)
		{
			SDL_Delay(20 - (currentTime - previousTime));
		}
		previousTime = SDL_GetTicks();
	}
	SDL_Quit();
	
	return EXIT_SUCCESS;
}
