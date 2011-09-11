/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "tower.h"

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

int getSellPrice(Tower *tower) {
	return (70*tower->type->price)/100;
}

void upgrade(Tower* t) {
   if(t->type->nextType){
	   t->type = t->type->nextType;
	}
}

/**
 * \fn void drawTower(Tower tower)
 * \brief draw a tower in the map
 * \param tower a tower to drawEnemy
 */
 
void drawTower(Tower *tower){
   SDL_Rect position;
   Case *cell = getCase(tower->x,tower->y);
   position.x = cell->x;
   position.y = cell->y;
   cell->hasTower = true;
   SDL_BlitSurface(tower->type->image, NULL, _map->bg, &position);
}
