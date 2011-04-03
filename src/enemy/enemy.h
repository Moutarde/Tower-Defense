/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#ifndef ENNEMY_H
#define ENNEMY_H

#include <stdio.h>
#include <stdbool.h>

#include "typeEn.h"
#include "../map/map.h"

typedef struct {
	int x;
	int y;
	int life;
	int speed;
	bool isPoisoned;
	TypeEn* type;
} Enemy;

Enemy* createEnemy(int x, int y, TypeEn* type);
void drawEnemy(Enemy* enemy, Map* map);

#endif
