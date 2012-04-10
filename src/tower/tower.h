/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#ifndef TOWER
#define TOWER

#include <stdio.h>
#include "typeTo.h"
#include "../map/map.h"

extern Map* _map;
Tower* createTower(int x, int y, TypeTo* type);
void upgrade(Tower* t);
int getSellPrice(Tower* tower);
void drawTower(Tower* tower);
Case* searchEnemy(Tower *tower);
int isInCircle(int x, int y, int range, int a, int b);

#endif
