/*
dev: Mickeymouse, Moutarde and Nepta
manager: Word
Copyright © 2011
You should have received a copy of the
GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.
*/


#include "viewport.h"

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
