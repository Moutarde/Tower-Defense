/*
dev: Mickeymouse, Moutarde and Nepta
manager: Word
Copyright © 2011

You should have received a copy of the
GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef MENU
#define MENU

#define MENU_BUTTON_STANDARD_SIZE 32
#define MENU_BUTTON_DISPLAY_OFFSET 20

#include <SDL/SDL.h>

#include "../map/map.h"
#include "../utils/button.h"

/**
 * \struct Menu menu.h
 * \brief The menu
 */

typedef struct {
	SDL_Surface* screen;		// Where to draw the menu
	SDL_Rect surface; 			//!< the surface of the menu
	SDL_Surface* background;	//!< background image of the menu

	Button** button;    		//!< buttons of the menu
	int buttonAmount; 			//!< Amount of buttons in the array currently

	void *minimap;   			//!< the minimap
} Menu;

Menu* menu_create(SDL_Surface* screen, SDL_Rect surface);
void menu_render(Menu* menu);
void menu_addButton(Menu* menu, Button* newButton);
void menu_free(Menu* menu);
void menu_loadBackground(Menu* menu, char* resource);
#endif
