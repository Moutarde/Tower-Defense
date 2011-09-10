/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "enemy.h"
#include "../utils/pathFinding.h"
#include <stdlib.h>

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
	enemy->type = type;
	enemy->animation = createAnimation(type->picture);
	Case anim_start = *getCase(x,y);
   enemy->animPosition.x = anim_start.x;
   enemy->animPosition.y = anim_start.y;
   enemy->animPosition.h = rand()%_map->nbCaseH;   
   enemy->animPosition.w = rand()%_map->nbCaseW;
	enemy->life = type->maxLife;
	enemy->speed = type->normalSpeed;
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
void drawEnemy(Enemy* enemy) {
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
   SDL_Rect animOffset = enemy->animPosition;
   animOffset.x += animOffset.w;
   animOffset.y += animOffset.h;

	SDL_BlitSurface(enemy->animation.currentFrame, getRect(&enemy->animation), _map->bg, &animOffset);
}

SDL_Rect* getRect(Animation *anim){
   SDL_Rect *frame = &anim->animation_state[anim->direction];
   frame->x += anim->currentFrame->w/3;
   frame->x %= anim->currentFrame->w;
  return frame;
}

/**
 * \fn void moveEnemy(Enemy* enemy)
 * \brief move an enemy
 * the function move an enemy according to the nextMovement function
 * \see nextMovement
 * \param enemy an Enemy to move
 */
 
void moveEnemy(Enemy* enemy){
   SDL_Rect anim = enemy->animPosition;
   Case nextCase = *getCase(enemy->x,enemy->y);
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

   Case currentCase = *getCase(x,y);
   extern Case cell;       //debug (candy_cane)
   Case finalCase = cell; //debug (candy_cane)
   if(currentCase.xx == finalCase.xx && currentCase.yy == finalCase.yy){
      return STAY;
   }

   return searchPath(currentCase,finalCase);
}


/**
 * \fn void removeEnemy(Enemy enemy)
 * \brief fonction to kill an enemy
 * \param enemy the enemy to kills
 */
 
void removeEnemy(Enemy *enemy){
   free(enemy);
   enemy = NULL;
}
