/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#ifndef TYPETO
#define TYPETO

#include <stdio.h>
#include <stdbool.h>

#include <SDL/SDL_image.h>

#include "typeBul.h"


typedef struct TypeTo {
	int damageMin;
	int damageRand;
	int range;
	int attSpeed;
	int price;
	int splashRadius;
	float slowFactor;
	bool canAttackFlying;
	TypeBul* typeBul;
	// FIXME Only one upgrade type per tower?! BORING!
	struct TypeTo* upgradeType;
	SDL_Surface* image;
} TypeTo;


TypeTo* createTypeTo(int damageMin,
					unsigned int damageRand,
					int range,						/* In pixels ? */
					unsigned int attSpeed,					/* In miliseconds ? */
					int price,
					unsigned int splashRadius,		/* Same unit than range */
					float slowFactor,
					bool canAttackFlying,
					TypeBul* typeBul,
					TypeTo* upgradeType,
					char* image);					/* Path, maybe revert directly to SDL_Surface pointer */

#endif
