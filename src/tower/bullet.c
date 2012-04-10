/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/

#include "bullet.h"

Bullet* createBullet(Tower *tower){
	Bullet *bullet = malloc(sizeof (Bullet));
	bullet->type = tower->type->typeBul;
	bullet->position = searchEnemy(tower);
  return bullet;
}

/**
 * \fn void drawBullet(Bullet *bullet)
 * \brief draw a bullet
 *
 * \param bullet a bullet to draw
 */
 
void drawBullet(Bullet *bullet){
	SDL_Rect position;
	position.x = bullet->position->x;
	position.y = bullet->position->y;
	blitToViewport(_viewport, bullet->type->image, NULL, &position);
}


