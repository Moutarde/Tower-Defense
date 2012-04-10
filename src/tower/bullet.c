/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/

#include "bullet.h"

Bullet* createBullet(TypeBul *type, Tower *tower){
	Bullet *bullet = malloc(sizeof (Bullet));
	bullet->type = type;
	bullet->position = searchEnemy(tower);
  return bullet;
}

