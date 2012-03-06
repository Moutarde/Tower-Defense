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
	/* Deficient by design : the tower functions shouldn't need to know of the map state */
   Case *cell = getCase(x,y);
   if(cell->hasEnemy || cell->hasTower){
      return NULL;
   }/* */
   
   Tower* tower = (Tower*)malloc( sizeof(Tower) );
   
   tower->x = x;
   tower->y = y;
   tower->type= type;
   
   tower->damageMod = 1.0;
   tower->speedMod = 1.0;
   tower->refireCounter = 0;
   tower->kills = 0;
   
  return tower;
}

int getSellPrice(Tower* tower) {
	// FIXME The return value should not be hardcoded
	// Note: Should this function even be here? This might be related to game mode/state
	return (70 * tower->type->price) / 100;
}

void upgrade(Tower* t) {
	// FIXME Upgrading means redrawing the tower
	if(t->type->upgradeType) {
		t->type = t->type->upgradeType;
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
	
	// Deficient by design: again, this means the tower has to know of map state
	// Also, the tower is there regardless of being drawn
	cell->hasTower = true;
	blitToViewport(_viewport, tower->type->image, NULL, &position);
}
