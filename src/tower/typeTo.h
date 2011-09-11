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

#include <SDL/SDL_image.h>

#include <stdbool.h>
#include "typeBul.h"

typedef struct TypeTo{
	int damages;
	int range;
	int attSpeed;
	int price;
	bool isSplash;
	bool isSlower;
	bool canAttackFlying;
	bool canPoison;
	TypeBul *typeBul;
	struct TypeTo *nextType;
	SDL_Surface* image;
} TypeTo;

typedef struct {
	int x;
	int y;
	TypeTo* type;
	int kills;
	
} Tower;


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
		     TypeTo *nextType,
		     char* image);

void upgradeTypeTo(TypeTo *tower, float percent, char* image);

#endif
