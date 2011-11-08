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

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

#include <SDL/SDL.h>

#include "../map/map.h"

/**
 * \struct Menu menu.h
 * \brief The menu
 */

typedef struct {
	SDL_Rect surface; //!< the surface of the menu
	void *button;     //!< buttons of the menu
	void *minimap;    //!< the minimap
} Menu;

Menu* createMenu(SDL_Rect surface);
void* selectTower(void* flags);
#endif
