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
#include "utils/viewport.h"
#include "event/event.h"
#include <stdbool.h>
#include "list/list.h"

Map *_map;
char* _path;

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
	
	int previousTime = 0, currentTime = 0;

	SDL_Init(SDL_INIT_VIDEO);
	
	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Tower Defense", NULL);
	
	Map* map = createMap(getPath("resources/Forest.png"));
   _map = map;
	
	SDL_Rect surface = {0, 0, 640, 480};
	Viewport* viewport = createViewport(surface, map);
	
	// Creation of the enemies
	TypeEn* cat = createTypeEn(100, 5, false, true, true, false, 1);
	Enemy* cat1 = createEnemy(0,0,cat,createAnimation(getPath("resources/white_transparent_cat.png")));
	Enemy* cat2 = createEnemy(1,4,cat,createAnimation(getPath("resources/black_transparent_cat.png")));

   //Add enemy in the List
   EnemyList *list = newEnemyList(cat1);
   popEnemy(list,cat2);

	// Main loop
	while(isInPlay) {
		// Managing the events
		SDL_PollEvent( &event );
		isInPlay = manageEvents(event, viewport);

		// Clean the objects on the map
		cleanMap(map);
		
		// Blit enemies
		drawEnemy(cat1,map);
		drawEnemy(cat2,map);

      // Move enemies
//      moveEnemy(cat1);
//      moveEnemy(cat2);
      
      //Move the List of enemy
      moveEnemyList(list);

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
