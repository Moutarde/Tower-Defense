/*
dev: Mickeymouse, Moutarde and Nepta
manager: Word
Copyright © 2011
You should have received a copy of the
GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.
*/


#include "viewport.h"


/**
 * \fn Viewport* createViewport(SDL_Rect suface, Map* map)
 * \brief Creates a viewport.
 *
 * \param suface The surface which is seen by the player.
 * \param map The entire map.
 * \return The array on the viewport, in order to use it.
 */
Viewport* createViewport(SDL_Surface* screen, SDL_Rect surface, Map* map) {
	Viewport* viewport = (Viewport*)malloc( sizeof(Viewport) );
	
	viewport->surface = surface;
	viewport->map = map;
	viewport->screen = screen;
	
	return viewport;
}

/**
 * \fn void drawViewport(Viewport* viewport)
 * \brief Draws a map on the screen.
 *
 * \param viewport Viewport to draw on the screen
 */
void drawViewport(Viewport* viewport) {
	SDL_BlitSurface(viewport->map->bg, &(viewport->surface), viewport->screen, NULL);
}

/**
 * \fn void blitToViewport(Viewport *viewport, SDL_Surface* src, SDL_Rect src_rect, SDL_Rect dest)
 * \brief Blit the specified image to destination, on the viewport
 *
 * \param viewport The viewport on which to draw
 * \param src Source ressource
 * \param src_rect Source area to blit
 * \param absdest Absolute map position to blit on, not taking into account viewport position
 */
 void blitToViewport(Viewport *viewport, SDL_Surface* src, SDL_Rect* src_rect, SDL_Rect* dest) {
 	// FIXME Need to take into account viewport's position
 	// FIXME Also should prevent stuff from drawing outside of the viewport
 	// NOTE Since SDL_BlitSurface change the dest rectangle anyway, we can change values in it
 	
 	SDL_BlitSurface(src, src_rect, viewport->screen, dest);
 }


/**
 * \fn void moveViewport(Viewport* viewport, short direction)
 * \brief Moves the viewports viewing coordinates
 *
 * \param viewport The viewport to move
 * \param direction Which direction to move (ENUM element)
 */
void moveViewport(Viewport* viewport, short direction) {
	switch(direction) {
		case UP:
			viewport->surface.y -= 5;
			if (viewport->surface.y < 0) {
				viewport->surface.y = 0;
			}
		break;

		case DOWN:
			viewport->surface.y += 5;
			if (viewport->surface.y > viewport->map->h - viewport->surface.h) {
				viewport->surface.y = viewport->map->h - viewport->surface.h;
			}
		break;

		case LEFT:
			viewport->surface.x -= 5;
			if (viewport->surface.x < 0) {
				viewport->surface.x = 0;
			}
		break;

		case RIGHT:
			viewport->surface.x += 5;
			if (viewport->surface.x > viewport->map->w - viewport->surface.w) {
				viewport->surface.x = viewport->map->w - viewport->surface.w;
			}
		break;
	}
}


