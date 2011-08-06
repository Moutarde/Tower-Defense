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

Map *_map;
int main(int argc, char *argv[]) {
	// Init
	SDL_Surface* screen = NULL;
	SDL_Event event;
	bool isInPlay = true;
	
	int previousTime = 0, currentTime = 0;

	SDL_Init(SDL_INIT_VIDEO);
	
	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Tower Defense", NULL);
	
	Map* map = createMap("resources/Forest.png");
	
	SDL_Rect surface = {0, 0, 640, 480};
	Viewport* viewport = createViewport(surface, map);
	
	// Creation of the enemies
	TypeEn* mario = createTypeEn(100, IMG_Load("resources/enemy.gif"), 5, false, true, true, false, 1);
	Enemy* mario1 = createEnemy(10, 15, mario);
	Enemy* mario2 = createEnemy(1, 5, mario);
	
	// Main loop
	while(isInPlay) {
		// Managing the events
		SDL_PollEvent( &event );
		isInPlay = manageEvents(event, viewport);
		
		// Clean the objects on the map
		cleanMap(map);
		
		// Blit enemies
		drawEnemy(mario1, map);
		drawEnemy(mario2, map);

      // Move enemies
      _map = map;
      moveEnemy(mario1);
      moveEnemy(mario2);
		// Blit map
		drawMap(map, &(viewport->surface), screen);
		
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
