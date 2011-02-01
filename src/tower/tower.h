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

typedef struct {
	int x;
	int y;
	TypeTo* type;
	int kills;
	int level;
	int damages;
	int range;
	int attSpeed;
	int sellPrice;
} Tower;

Tower* createTower(int x, int y, TypeTo* type);
int getPrice(int iniPrice);

#endif
