/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "enemy.h"

Enemy* createEnemy(int x, int y, TypeEn* type) {
	Enemy* enemy = (Enemy*)malloc( sizeof(Enemy) );

	enemy->x = x;
	enemy->y = y;
	enemy->life = type->maxLife;
	enemy->speed = type->normalSpeed;
	enemy->type = type;
	enemy->isPoisoned = false;

	return enemy;
}
