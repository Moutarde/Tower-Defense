/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */


#include "event.h"


int eventFilter(SDL_Event* event) {
	switch(event->type) {
		case SDL_QUIT:
		case SDL_KEYDOWN:
		case SDL_MOUSEBUTTONDOWN:
			return 1;
		default:
			return 0;
	}
}

/**
 * \fn EventList* newEventList()
 * \brief Create a new event list
 */
 
EventList* newEventList(){
	return (EventList*)malloc(sizeof(EventList));
}

/**
 * \fn bool manageEvent(SDL_Event event, Viewport* viewport)
 * \brief Manage an event.
 *
 * \param event The event to manage.
 * \param viewport The viewport that can be moved.
 * \return False if the the game ends, true if not.
 */
EventList* manageEvent(SDL_Event event, Viewport* viewport, Events *flags, ActionList **actionList){
	//enum actionlist.h
	switch(event.type) {
		// Quit game
		case SDL_QUIT:
			actionlist[QUIT]->boolean = true;
			break;
			
		// Key pressed
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym) {
				// Quit game
				case SDLK_ESCAPE:
					actionlist[QUIT]->boolean = true;
					break;
					
				// Move view
				case SDLK_UP:
					actionlist[ARROW_UP]->boolean = true;
				  break;
					
				case SDLK_DOWN:
					actionlist[ARROW_DOWN]->boolean = true;
				  break;
					
				case SDLK_LEFT:
					actionlist[ARROW_LEFT]->boolean = true;
				  break;
					
				case SDLK_RIGHT:
					actionlist[ARROW_RIGHT]->boolean = true;
				  break;
					
				default:
					break;
			}
		   break;

      // Mouse left click
      case SDL_MOUSEBUTTONDOWN:
         if(event.button.button == SDL_BUTTON_LEFT) {
		   	actionlist[CASE_CLICKED]->boolean = whichCase(event.button.x, event.button.y);
         }
         break;
			
		default:
			break;
	}
	
	return list;
}

bool manageEvents(Viewport* viewport, Events *flags) {
	SDL_Event event;
	// Process events until game exit, or there's none left
	while(SDL_PollEvent(&event)) {
		if(!manageEvent(event, viewport, flags)) return false;
	}
	return true;
}

/**
 * \fn createEventFlags()
 * \brief Deficient by design?
 *
 * \return hiden global variable :- °
 */

Events* createEventFlags(){
   Events *flags = (Events*)malloc(sizeof *flags);
   flags->enemy_Path_Calculation = false;
	flags->eventList = newEventList();
  return flags;
}

/**
 * \fn void pathReCalculation(List *enemyList)
 * \brief set the enemy in "waiting for path" state
 * \param enemyList a list of enemy who have to change there path
 */
 
void pathReCalculation(List *enemyList){
   while(enemyList->nextList){
      ((Enemy*)enemyList->item)->list = NULL;
      enemyList = enemyList->nextList;
   }
   ((Enemy*)enemyList->item)->list = NULL;
}
