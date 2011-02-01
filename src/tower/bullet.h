/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#ifndef BULLET
#define BULLET

#include <stdio.h>

#include "typeBul.h"

typedef struct {
	int x;
	int y;
	TypeBul* type;
} Bullet;

Bullet* createBullet(int x, int y, TypeBul* type);

#endif
