/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */


#include "event.h"


/**
 * \fn bool manageEvents(SDL_Event event, Viewport* viewport)
 * \brief Manage the events.
 *
 * \param event The event to manage.
 * \param viewport The viewport that can be moved.
 * \return False if the the game ends, true if not.
 */
bool manageEvents(SDL_Event event, Viewport* viewport, Events *flags) {
	bool isInPlay = true;
	
	switch(event.type) {
		// Quit game
		case SDL_QUIT:
			isInPlay = false;
			break;
			
		// Key pressed
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym) {
				// Quit game
				case SDLK_ESCAPE:
					isInPlay = false;
					break;
					
				// Move view
				case SDLK_UP:
					moveViewport(viewport, UP);
					break;
					
				case SDLK_DOWN:
					moveViewport(viewport, DOWN);
					break;
					
				case SDLK_LEFT:
					moveViewport(viewport, LEFT);
					break;
					
				case SDLK_RIGHT:
					moveViewport(viewport, RIGHT);
					break;
					
				default:
					break;
			}
		   break;

      // Mouse left click
      case SDL_MOUSEBUTTONDOWN:
         if(event.button.button == SDL_BUTTON_LEFT) {
            Case* caseClicked = whichCase(event.button.x, event.button.y);
            TypeTo* simpleTowerType = flags->selectedTower;
            Case *viewportOffset = whichCase(viewport->surface.x,viewport->surface.y);
            int mapPositionX = caseClicked->xx + viewportOffset->xx;
            int mapPositionY = caseClicked->yy + viewportOffset->yy;
            Tower *tower = createTower(mapPositionX, mapPositionY, simpleTowerType);
            if(tower){
               flags->enemy_Path_Calculation = true;
               pushList((void*)flags->towerList,tower);
               drawTower(tower);
            }
         }
         break;
			
		default:
			break;
	}
	
	return isInPlay;
}

Events* createEventFlags(){
   Events *flags = (Events*)malloc(sizeof *flags);
   flags->enemy_Path_Calculation = false;
  return flags;
}

void pathReCalculation(List *enemyList){
   while(enemyList->nextList){
      ((Enemy*)enemyList->item)->list = NULL;
      enemyList = enemyList->nextList;
   }
   ((Enemy*)enemyList->item)->list = NULL;
}
