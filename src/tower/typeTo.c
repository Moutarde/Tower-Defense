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
           int damages,
		     int range,
		     int attSpeed,
		     int price,
           bool isSplash,
		     bool isSlower,
           bool canAttackFlying,
           bool canPoison,
	 	     TypeBul *typeBul,
	 	     TypeTo *nextType,
	 	     char* image) {

	TypeTo* typeTo = (TypeTo*)malloc( sizeof(TypeTo) );

	typeTo->damages = damages;
	typeTo->range = range;
	typeTo->attSpeed = attSpeed;
	typeTo->price = price;
	typeTo->isSplash = isSplash;
	typeTo->isSlower = isSlower;
	typeTo->canAttackFlying = canAttackFlying;
	typeTo->canPoison = canPoison;
	typeTo->typeBul = typeBul;
	typeTo->nextType = nextType;
	typeTo->image = IMG_Load(image);

	return typeTo;
}
