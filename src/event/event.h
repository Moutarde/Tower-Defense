/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */

#ifndef EVENT
#define EVENT

#include <SDL/SDL.h>
#include <stdbool.h>
#include "../utils/viewport.h"
#include "../tower/tower.h"

bool manageEvents(SDL_Event event, Viewport* viewport);
char* getPath(char* resource);
#endif
