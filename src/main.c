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
#include <stdbool.h>

int main(int argc, char *argv[]) {
	// Init
	SDL_Surface* screen = NULL;
	SDL_Event event;
	bool isInPlay = true;
	SDL_Rect viewport = {0, 0, 640, 480};
	
	int previousTime = 0, currentTime = 0;

	SDL_Init(SDL_INIT_VIDEO);
	
	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Tower Defense", NULL);
	
	Map* map = createMap("resources/Forest.png");
	
	// Creation of the enemies
	TypeEn* mario = createTypeEn(100, IMG_Load("resources/enemy.gif"), 5, false, true, true, false, 1);
	Enemy* mario1 = createEnemy(10, 15, mario);
	Enemy* mario2 = createEnemy(1, 5, mario);
	
	// Main loop
	while(isInPlay) {
		SDL_PollEvent( &event );
		switch(event.type) {
			// Quit game
			case SDL_QUIT:
				isInPlay = false;
				break;
			
			// Key pressed
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					// Quit game
					case SDLK_ESCAPE:
						isInPlay = false;
						break;
					
					// Move view
					case SDLK_UP:
						viewport.y -= 5;
						if (viewport.y < 0) {
							viewport.y = 0;
						}
						break;
						
					case SDLK_DOWN:
						viewport.y += 5;
						if (viewport.y > map->h - viewport.h) {
							viewport.y = map->h - viewport.h;
						}
						break;
						
					case SDLK_LEFT:
						viewport.x -= 5;
						if (viewport.x < 0) {
							viewport.x = 0;
						}
						break;
						
					case SDLK_RIGHT:
						viewport.x += 5;
						if (viewport.x > map->w - viewport.w) {
							viewport.x = map->w - viewport.w;
						}
						break;
						
					default:
						break;
				}
				break;
				
			default:
				break;
		}
		
		// Managing frames
		currentTime = SDL_GetTicks();
		if (currentTime - previousTime <= 20)
		{
			SDL_Delay(20 - (currentTime - previousTime));
		}
		previousTime = SDL_GetTicks();
		
		// Show map
		drawMap(map, &viewport, screen);
		
		// Show enemies
		drawEnemy(mario1, map);
		drawEnemy(mario2, map);
		
		SDL_Flip(screen);
	}

	SDL_Quit();
	
	return EXIT_SUCCESS;
}
