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
 * \fn bool manageEvents(SDL_Event event)
 * \brief Manage the events.
 *
 * \param event The event to manage.
 * \param viewport The viewport that can be moved.
 * \return False if the the game ends, true if not.
 */

bool manageEvents(SDL_Event event, Viewport* viewport) {
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
			
		default:
			break;
	}
	
	return isInPlay;
}
