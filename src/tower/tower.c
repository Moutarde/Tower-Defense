/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "tower.h"
#include "../utils/viewport.h"

Tower* createTower(int x, int y, TypeTo* type) {
   Case *cell = getCase(x,y);
   if(cell->hasEnemy || cell->hasTower){
      return NULL;
   }
   Tower* tower = (Tower*)malloc( sizeof(Tower) );
   tower->x = x;
   tower->y = y;
   tower->kills = 0;
   tower->type= type;
   
   
  return tower;
}

int getSellPrice(Tower* tower) {
	return (70 * tower->type->price) / 100;
}

void upgrade(Tower* t) {
	if(t->type->nextType) {
		t->type = t->type->nextType;
	}
}

/**
 * \fn void drawTower(Tower* tower)
 * \brief Draws a tower in the map.
 * 
 * \param tower A tower to draw.
 */
void drawTower(Tower* tower) {
	SDL_Rect position;
	Case* cell = getCase(tower->x, tower->y);
	position.x = cell->x;
	position.y = cell->y;
	cell->hasTower = true;
	blitToViewport(_viewport, tower->type->image, NULL, &position);
}

/**
 * \fn Case searchEnemy(Tower *tower)
 * \brief search an enemy around the tower
 * \param tower the tower which search the enemy
 * \return the first cell which have an enemy and the tower position if there aren't any enemy in the range
 */

Case* searchEnemy(Tower *tower){
	int x = tower->x;
	int y = tower->y;
	int range = tower->type->range;
	Case *enemyPosition;
	for(int i=-range;i<=range;i++){
		for(int j=-range;j<=range;j++){
			if(isInCircle(i,j,range*2,x,y)){
				enemyPosition = whichCase(i, j);
				if(enemyPosition->hasEnemy){
					return enemyPosition;
				}
			}
		}
	}
	return whichCase(tower->x,tower->y);
}

/**
 * \fn int isInCircle(int x, int y, int range, int a, int b)
 * \brief Calcul if (x,y) is in the cercle C(a,b)
 * \param x x position of the point
 * \param y y position of the point
 * \param a x position of the circle
 * \param b y position of the circle
 * \param range length of the circle
 * \return true if the point is on or in the circle
 */
 
int isInCircle(int x, int y, int range, int a, int b){
  return (x - a)*(x - a) + (y - b)*(y - b)< (range * range);
}

