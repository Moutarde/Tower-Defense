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

//Could use some enum here instead
//enum directions {RIGHT, LEFT, UP, DOWN};
//Huh.... All these defines are used in enemy.c, but not in the menu.
#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

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
	SDL_Rect surface; 			//!< the surface of the menu
	SDL_Surface* background;	//!< background image of the menu

	Button** button;    		//!< buttons of the menu
	int buttonAmount; 			//!< Amount of buttons in the array currently

	void *minimap;   			//!< the minimap
} Menu;

Menu* menu_create(SDL_Rect surface);
void menu_render(Menu* menu);
void menu_addButton(Menu* menu, Button* newButton);
void menu_free(Menu* menu);
void menu_loadBackground(Menu* menu, char* resource);
#endif
