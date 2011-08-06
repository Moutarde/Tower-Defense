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
 * \fn void drawEnemy(Enemy* enemy, Map* map)
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

/**
 * \fn void moveEnemy(Enemy* enemy, Movement move);
 * \brief move an enemy
 * the function move an enemy according to the nextMovement function
 * \see nextMovement
 * \param enemy an Enemy to move
 */
 
void moveEnemy(Enemy* enemy){
   Movement nextMove = nextMovement(enemy);
   switch(nextMove){
      case RIGHT:
         enemy->x++;
        break;
      case LEFT:
         enemy->x--;
        break;
      case UP:
         enemy->y++;
        break;
      case DOWN:
         enemy->y--;
      default:
        break;
   }
}

 
/**
 * \fn Movement nextMovement(Enemy* enemy);
 * \brief Compute where the monster must go
 * the function juste check the free cells against the enemy
 * and choose randomly one of them
 * \param enemy an Enemy whithout path
 */

Movement nextMovement(Enemy* enemy){
   int x = enemy->x;
   int y = enemy->y;
   if(x+1 < _map->nbCaseW && !getCase(x+1,y).hasTower){
     return RIGHT;
   }else if(++y < _map->nbCaseH && !getCase(x,y--).hasTower){
     return UP;
   }else if(--y < _map->nbCaseH && !getCase(x,y++).hasTower){
     return DOWN;
   }else if(++x < _map->nbCaseW && !getCase(x--,y).hasTower){
     return LEFT;
   }else{
     return STAY;
   }
}
