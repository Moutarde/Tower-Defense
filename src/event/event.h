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

#include "../list/list.h"
#include <SDL/SDL.h>
#include <stdbool.h>
#include "../utils/viewport.h"
#include "../tower/tower.h"
#include "../enemy/action.h"
#include "../utils/flag.h"


int eventFilter(SDL_Event* event);
void manageEvent(SDL_Event event, Viewport* viewport, Events *flags, Action *actionList);
void manageEvents(Viewport* viewport, Events* flags, Action *actionList);
char* getPath(char* resource);
Events* createEventFlags();
void pathReCalculation(List *enemyList);

#endif
