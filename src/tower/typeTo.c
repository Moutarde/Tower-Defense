/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "typeTo.h"

TypeTo* createTypeTo(
           int iniDamages,
		     int iniRange,
		     int iniAttSpeed,
		     int price,
           bool isSplash,
		     bool isSlower,
           bool canAttackFlying,
           bool canPoison,
	 	     TypeBul *typeBul,
	 	     char* image) {

	TypeTo* typeTo = (TypeTo*)malloc( sizeof(TypeTo) );

	typeTo->iniDamages = iniDamages;
	typeTo->iniRange = iniRange;
	typeTo->iniAttSpeed = iniAttSpeed;
	typeTo->price = price;
	typeTo->isSplash = isSplash;
	typeTo->isSlower = isSlower;
	typeTo->canAttackFlying = canAttackFlying;
	typeTo->canPoison = canPoison;
	typeTo->typeBul = typeBul;
	typeTo->image = IMG_Load(image);

	return typeTo;
}
