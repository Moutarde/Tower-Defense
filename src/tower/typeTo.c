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
	typeTo->nextType = NULL;
	typeTo->image = IMG_Load(image);

	return typeTo;
}

/**
 * \fn void *upgradeTypeTo(Tower *tower, float percent,char *image)
 * \brief create a new type of tower, with same property (slow, poison...) and a little bit more efficient
 * \param tower the previous version of the tower
 * \param percent the percent of upgrade
 * \param image the new picture of the tower
 */
void upgradeTypeTo(TypeTo *tower, float percent,char* image){
   percent += 1;
   TypeTo *newType = createTypeTo(
                     tower->damages * percent,
	                  tower->range * percent,
	                  tower->attSpeed * percent,
	                  tower->price * percent,
	                  tower->isSplash,
	                  tower->isSlower,
	                  tower->canAttackFlying,
	                  tower->canPoison,
	                  tower->typeBul,
	                  tower->nextType,
	                  image
                    );
   tower->nextType = newType;
}
