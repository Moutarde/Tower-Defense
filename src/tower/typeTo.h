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

#include <SDL/SDL.h>

#include <stdbool.h>
#include "typeBul.h"

typedef struct {
	int iniDamages;
	int iniRange;
	int iniAttSpeed;
	int price;
	bool isSplash;
	bool isSlower;
	bool canAttackFlying;
	bool canPoison;
	TypeBul *typeBul;
	SDL_Surface* image;
} TypeTo;

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
		     char* image);

#endif
