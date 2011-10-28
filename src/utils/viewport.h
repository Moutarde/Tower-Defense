/*
dev: Mickeymouse, Moutarde and Nepta
manager: Word
Copyright © 2011

You should have received a copy of the
GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef VIEWPORT
#define VIEWPORT

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

#include <SDL/SDL.h>

#include "../map/map.h"


typedef struct {
	SDL_Rect surface;
	Map* map;
} Viewport;

Viewport* createViewport(SDL_Rect surface, Map* map);
void moveViewport(Viewport* viewport, short direction);

#endif
