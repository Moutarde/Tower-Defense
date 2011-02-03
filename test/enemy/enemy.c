/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/

#include <stdbool.h>

#include <CUnit/Basic.h>

#include "src/enemy/enemy.h"

TypeEn* typeEnemy = NULL;

int initEnemySuite()
{
	typeEnemy = createTypeEn(0, NULL, 0,false, false, false, false, 0);

	if(typeEnemy == NULL) {
		return 1;
	}

	return 0;
}

int cleanEnemySuite()
{
	free(typeEnemy);

	return 0;
}

void testCreateEnemy()
{
	Enemy* enemy = createEnemy(3, 4, typeEnemy);

	CU_ASSERT(3 == enemy->x);
	CU_ASSERT(4 == enemy->y);
	CU_ASSERT(typeEnemy == enemy->type);

}

