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

/*#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3*/
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#include <SDL/SDL.h>

#include "../map/map.h"

/**
 *	\struct Viewport
 * \brief The displayed screen
 */
typedef struct {
	SDL_Rect screensurface;	//!< Screen surface is where the viewport is displayed

	SDL_Rect mapsurface;		//!< Map surface is what part of the map the viewport displays

	Map* map;
	SDL_Surface* screen;

	SDL_Rect* revertrects;
	int revertcount;			//!< Info to revert the displayed sprites
	
	int completeredraw;		//!< Indicates the viewport's background should be redrawn completely on next frame
} Viewport;

extern Viewport* _viewport;
void drawViewport(Viewport* viewport);
Viewport* createViewport(SDL_Surface* screen, SDL_Rect surface, Map* map);
void moveViewport(Viewport* viewport, short direction);
void blitToViewport(Viewport* viewport, SDL_Surface* src, SDL_Rect* src_rect, SDL_Rect* dest);
void cleanViewport(Viewport *viewport);
void updateViewport(Viewport *viewport);

#endif
