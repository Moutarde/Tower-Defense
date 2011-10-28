/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "bullet.h"


Bullet* createBullet(int x, int y, TypeBul* type){
	Bullet* bullet = (Bullet*)malloc( sizeof(Bullet) );

	bullet->x = x;
	bullet->y = y;
	bullet->type = type;

	return bullet;
}
