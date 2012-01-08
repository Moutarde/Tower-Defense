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


/**
 *	\struct EventList event.h
 * \brief List of all key pressed
 */
typedef struct{
	Action quit		//!< Escape Key
	Action arrow[4];		//!< Arrow keys
	Action caseClicked;	//!< Mouse button
}ActionList; //!\ liste chaîner


/**
 * \struct Events event.h
 * \brief An List of event to manage.
 */

typedef struct{
   bool enemy_Path_Calculation;	//!< 
   TypeTo *selectedTower;   		//!< 
   List *towerList;					//!< 
	EventList *eventList;			//!<
}Events;


int eventFilter(SDL_Event* event);
EventList* manageEvent(SDL_Event event, Viewport* viewport, Events *flags);
bool manageEvents(Viewport* viewport, Events* flags);
char* getPath(char* resource);
Events* createEventFlags();
void pathReCalculation(List *enemyList);

#endif
