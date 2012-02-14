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
	
	// Initializes the displayed map surface to 0,0 and with specified size
	viewport->mapsurface.x = 0;
	viewport->mapsurface.y = 0;
	viewport->mapsurface.w = surface.w;
	viewport->mapsurface.h = surface.h;

	// Initialize the viewport's screen position to given surface
	// NOTE: Doesnt actually work (the offset is not taking into consideration yet, it'll always be drawn in 0,0)
	viewport->screensurface = surface;

	viewport->map = map;
	viewport->screen = screen;

	// FIXME This should realloc. Or something like that.
	viewport->revertrects = malloc(sizeof(SDL_Rect) * 200);
	viewport->revertcount = 0;
	viewport->completeredraw = 1;
	
	return viewport;
}

/**
 * \fn void drawViewport(Viewport* viewport)
 * \brief Draws a map on the screen.
 *
 * \param viewport Viewport to draw on the screen
 */
void redrawViewport(Viewport* viewport) {
	// FIXME Need a system to manage SetClipRect without slowing down the game (one call per drawing sequence)
	SDL_SetClipRect(viewport->screen, &viewport->screensurface);

	SDL_BlitSurface(viewport->map->bg, &(viewport->mapsurface), viewport->screen, NULL);
}


/**
 * 
 */
void updateViewport(Viewport *viewport) {
	int i;
	SDL_Rect target;
		
	if(viewport->completeredraw) {
		redrawViewport(viewport);
		viewport->completeredraw = 0;	
	} else {
		for(i = 0; i < viewport->revertcount; i++) {
			target = viewport->revertrects[i];
			target.x -= viewport->mapsurface.x;
			target.y -= viewport->mapsurface.y;	

			SDL_BlitSurface(viewport->map->bg, &(viewport->revertrects[i]), viewport->screen, &target);
		}
	}

	viewport->revertcount = 0;
}

/**
 * \fn void blitToViewport(Viewport *viewport, SDL_Surface* src, SDL_Rect src_rect, SDL_Rect dest)
 * \brief Blit the specified image to destination, on the viewport
 *
 * \param viewport The viewport element to draw on
 * \param src_sprite Surface to draw
 * \param relsrc Rectangle of the source sprite to draw
 * \param reldest Map relative rectangle where to draw the sprite
 */
 void blitToViewport(Viewport *viewport, SDL_Surface* src_sprite, SDL_Rect* relsrc, SDL_Rect* reldest) {
	// Shift the destination from map relative coordinates to screen displayed ones	
	reldest->x -= viewport->mapsurface.x;
	reldest->y -= viewport->mapsurface.y;
	
	// Blit the image onto specified position
	SDL_BlitSurface(src_sprite, relsrc, viewport->screen, reldest);

	// If we actually blitted something
	if(!reldest->w || !reldest->h) return;

	// Add the blitted element to the list of stuff to de-blit later
	viewport->revertrects[viewport->revertcount] = *reldest;
	// Don't forget to make it a map relative value again!
	viewport->revertrects[viewport->revertcount].x += viewport->mapsurface.x;
	viewport->revertrects[viewport->revertcount].y += viewport->mapsurface.y;

	viewport->revertcount++;
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
			viewport->mapsurface.y -= 5;
			if (viewport->mapsurface.y < 0) {
				viewport->mapsurface.y = 0;
			}
			viewport->completeredraw = 1;
		break;

		case DOWN:
			viewport->mapsurface.y += 5;
			if (viewport->mapsurface.y > viewport->map->h - viewport->mapsurface.h) {
				viewport->mapsurface.y = viewport->map->h - viewport->mapsurface.h;
			}
			viewport->completeredraw = 1;
		break;

		case LEFT:
			viewport->mapsurface.x -= 5;
			if (viewport->mapsurface.x < 0) {
				viewport->mapsurface.x = 0;
			}
			viewport->completeredraw = 1;
		break;

		case RIGHT:
			viewport->mapsurface.x += 5;
			if (viewport->mapsurface.x > viewport->map->w - viewport->mapsurface.w) {
				viewport->mapsurface.x = viewport->map->w - viewport->mapsurface.w;
			}
			viewport->completeredraw = 1;
		break;
	}
}


