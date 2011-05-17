/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "enemy.h"

/**
 * \fn Enemy* createEnemy(int x, int y, TypeEn* type)
 * \brief Function which creates an enemy.
 *
 * \param x Define the horizontal position of the enemy.
 * \param y Define the vertical position of the enemy.
 * \param type The type of the enemy.
 * \return The pointer on the enemy, in order to use it.
 */
Enemy* createEnemy(int x, int y, TypeEn* type) {
	Enemy* enemy = (Enemy*)malloc( sizeof(Enemy) );

	enemy->x = x;
	enemy->y = y;
	enemy->life = type->maxLife;
	enemy->speed = type->normalSpeed;
	enemy->type = type;
	enemy->isPoisoned = false;

	return enemy;
}

/**
 * \fn void* drawEnemy(Enemy* enemy, Map* map)
 * \brief Draws an enemy on the map
 *
 * \param enemy Enemy to draw.
 * \param map The map where the enemy has to be drawn.
 */
void drawEnemy(Enemy* enemy, Map* map) {
	SDL_Rect position;
	position.x = map->matrice[enemy->x][enemy->y].x;
	position.y = map->matrice[enemy->x][enemy->y].y;
	
	SDL_BlitSurface(enemy->type->image, NULL, map->bg, &position);
}
