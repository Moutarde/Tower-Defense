/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/
#include <CUnit/Console.h>

#include "test/enemy/test_enemy.h"

int main()
{
	CU_pSuite enemySuite = NULL;

	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	enemySuite = CU_add_suite("Suite_1", initEnemySuite, cleanEnemySuite);
	if (NULL == enemySuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(enemySuite, "Create Enemy", testCreateEnemy))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}


	CU_console_run_tests();

	CU_cleanup_registry();

	return CU_get_error();
}

