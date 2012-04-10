/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/

#ifndef __Bullet_H__
#define __Bullet_H__

#include "typeBul.h"
#include "tower.h"

#include "../enemy/enemy.h"
#include "../map/case.h"
#include "../utils/viewport.h"

typedef struct{
	Case *position;		//!< Bullet
	Enemy *target;
	TypeBul *type;
}Bullet;

Bullet* createBullet(Tower *tower);
void drawBullet(Bullet *bullet);

#endif /* __Bullet_H__ */

