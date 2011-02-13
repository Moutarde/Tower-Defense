/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "map/map.h"
#include <stdbool.h>

int main() {
	SDL_Surface* screen = NULL;
	SDL_Event event;
	bool isInPlay = true;
	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Tower Defense", NULL);

	Map* map = createMap(800,800,"resources/Forest.png");
	while(isInPlay) {
	SDL_WaitEvent(&event);
		switch(event.type) {
		case SDL_QUIT:
			isInPlay = false;
			break;
	    
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym) {
			case SDLK_ESCAPE:
				isInPlay = false;
				break;
			
			default:
				break;
			}
			break;
	    
		default:
			break;
		}
	}
	SDL_Quit();

	return EXIT_SUCCESS;
}
