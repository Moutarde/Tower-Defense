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
		case SDL_KEYUP:
		case SDL_MOUSEBUTTONDOWN:
			return 1;
		default:
			return 0;
	}
}

/**
 * \fn bool manageEvent(SDL_Event event, Viewport* viewport)
 * \brief Manage an event.
 *
 * \param event The event to manage.
 * \param viewport The viewport that can be moved.
 * \return False if the the game ends, true if not.
 */
void manageEvent(SDL_Event event, Viewport* viewport, Events *flags, Action *actionList){
	switch(event.type) {
		// Quit game
		case SDL_QUIT:
			actionList[QUIT].boolean = (void*)1;
			break;
			
		// Key pressed
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym) {
				// Quit game
				case SDLK_ESCAPE:
					actionList[QUIT].boolean = (void*)1;
					break;
					
				// Move view
				case SDLK_UP:
					actionList[ARROW_UP].boolean = (void*)1;
				  break;
					
				case SDLK_DOWN:
					actionList[ARROW_DOWN].boolean = (void*)1;
				  break;
					
				case SDLK_LEFT:
					actionList[ARROW_LEFT].boolean = (void*)1;
				  break;
					
				case SDLK_RIGHT:
					actionList[ARROW_RIGHT].boolean = (void*)1;
				  break;
					
				default:
					break;
			}
		   break;
		// Key released
		case SDL_KEYUP:
			switch(event.key.keysym.sym) {
					
					// Stop Moving view
					case SDLK_UP:
						actionList[ARROW_UP].boolean = NULL;
					  break;
					case SDLK_DOWN:
						actionList[ARROW_DOWN].boolean = NULL;
					  break;
					case SDLK_LEFT:
						actionList[ARROW_LEFT].boolean = NULL;
					  break;
					case SDLK_RIGHT:
						actionList[ARROW_RIGHT].boolean = NULL;
					  break;
					default:
					  break;
		  }

      // Mouse left click
      case SDL_MOUSEBUTTONDOWN:
         if(event.button.button == SDL_BUTTON_LEFT) {
		   	actionList[CASE_CLICKED].boolean = whichCase(event.button.x, event.button.y);
         }
         break;
			
		default:
			break;
	}
}
void manageEvents(Viewport* viewport, Events *flags, Action *actionList) {
	SDL_Event event;
	// Process events until game exit, or there's none left
	SDL_PollEvent(&event);
	manageEvent(event, viewport, flags, actionList);
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
