/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/
#include <CUnit/Console.h>

int main()
{
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();


	CU_console_run_tests();

	CU_cleanup_registry();

	return CU_get_error();
}

