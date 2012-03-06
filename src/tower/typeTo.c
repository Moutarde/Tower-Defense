/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "typeTo.h"


TypeTo* createTypeTo(int damageMin,
					unsigned int damageRand,
					int range,
					unsigned int attSpeed,
					int price,
					unsigned int splashRadius,
					float slowFactor,
					bool canAttackFlying,
					TypeBul* typeBul,
					TypeTo* upgradeType,
					char* image) {

	TypeTo* typeTo = (TypeTo*)malloc( sizeof(TypeTo) );

	typeTo->damageMin = damageMin;
	typeTo->damageRand = damageRand;
	typeTo->range = range;
	typeTo->attSpeed = attSpeed;
	typeTo->price = price;
	typeTo->splashRadius = splashRadius;
	typeTo->slowFactor = slowFactor;
	typeTo->canAttackFlying = canAttackFlying;
	
	typeTo->typeBul = typeBul;
	typeTo->upgradeType = NULL;
	typeTo->image = IMG_Load(image);

	return typeTo;
}
