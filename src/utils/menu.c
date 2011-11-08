/*
dev: Mickeymouse, Moutarde and Nepta
manager: Word
Copyright © 2011
You should have received a copy of the
GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.
*/


#include "menu.h"


/**
 * \fn Menu* createMenu(SDL_Rect surface)
 * \brief Create the menu
 *
 * \param suface The surface which the menu will be.
 * \return The Menu pointer
 */
Menu* createMenu(SDL_Rect surface){
	Menu* menu = (Menu*)malloc(sizeof *menu);
	
	menu->surface = surface;
	
  return menu;
}

void* selectTower(void* flags){
}
