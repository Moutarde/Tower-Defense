/*
dev: Mickeymouse, Moutarde and Nepta
manager: Word
Copyright © 2011

You should have received a copy of the
GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef BUTTON
#define BUTTON

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../tower/typeTo.h"

typedef enum {
	NONE,		// Do nothing
	BUILD,		// Build a tower
	UPGRADE		// Upgrade a tower
} buttonType;

typedef struct {
	buttonType type;	// The Button action type
	void* target;		// The Button's target. EG. A tower type for a build button.
	SDL_Surface* image;	// The displayed Image of the button
} Button;

Button* button_createBuildButton(TypeTo* towerType);

#endif
