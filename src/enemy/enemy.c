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
Enemy* createEnemy(int x, int y, TypeEn* type,Animation animation) {
	Enemy* enemy = (Enemy*)malloc( sizeof(Enemy) );

	enemy->x = x;
	enemy->y = y;
	enemy->animation = animation;
	Case anim_start = getCase(x,y);
   enemy->animPosition.x = anim_start.x;
   enemy->animPosition.y = anim_start.y;
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
   switch(enemy->animation.direction){
      case RIGHT:
         enemy->animPosition.x++;
        break;
      case LEFT:
         enemy->animPosition.x--;
        break;
      case UP:
         enemy->animPosition.y--;
        break;
      case DOWN:
         enemy->animPosition.y++;
        break;
      default:
        break;
   }

	SDL_BlitSurface(enemy->animation.currentFrame, getRect(&enemy->animation), map->bg, &enemy->animPosition);
}

SDL_Rect* getRect(Animation *anim){
   SDL_Rect *frame = &anim->animation_state[anim->direction];
   frame->x += anim->currentFrame->w/3;
   frame->x %= anim->currentFrame->w;
  return frame;
}

/**
 * \fn void moveEnemy(Enemy* enemy, Movement move);
 * \brief move an enemy
 * the function move an enemy according to the nextMovement function
 * \see nextMovement
 * \param enemy an Enemy to move
 */
 
void moveEnemy(Enemy* enemy){
   SDL_Rect anim = enemy->animPosition;
   Case nextCase = getCase(enemy->x,enemy->y);
   if(anim.x == nextCase.x && anim.y == nextCase.y){
      enemy->animation.direction = nextMovement(enemy);
      nextCase.hasEnemy--;
      switch(enemy->animation.direction){
         case RIGHT:
            enemy->x++;
           break;
         case LEFT:
            enemy->x--;
           break;
         case DOWN:
            enemy->y++;
           break;
         case UP:
            enemy->y--;
         default:
           break;
      }
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
   Case nearCase;
   if(x+1 < _map->nbCaseW && (nearCase = getCase(x+1,y), !nearCase.hasTower)){
      nearCase.hasEnemy++;
     return RIGHT;
   }else if(y+1 < _map->nbCaseH && (nearCase = getCase(x,y+1), !nearCase.hasTower)){
      nearCase.hasEnemy++;
     return DOWN;
   }else if(y-1 < _map->nbCaseH && (nearCase = getCase(x,y-1), !nearCase.hasTower)){
      nearCase.hasEnemy++;
     return UP;
   }else if(x-1 < _map->nbCaseW && (nearCase = getCase(x-1,y), !nearCase.hasTower)){
      nearCase.hasEnemy++;
     return LEFT;
   }else{
     return STAY;
   }
}
