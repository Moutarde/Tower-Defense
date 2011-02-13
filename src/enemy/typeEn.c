/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "typeEn.h"

TypeEn* createTypeEn(int maxLife,
		     SDL_Surface* image,
		     int normalSpeed,
		     bool canFly,
		     bool canBeSlowed,
	             bool canBePoisoned,
	             bool invisible,
		     int armor) {

	TypeEn* typeEn = (TypeEn*)malloc( sizeof(TypeEn) );

	typeEn->maxLife = maxLife;
	typeEn->image = image;
	typeEn->normalSpeed = normalSpeed;
	typeEn->canFly = canFly;
	typeEn->canBeSlowed = canBeSlowed;
	typeEn->canBePoisoned = canBePoisoned;
	typeEn->invisible = invisible;
	typeEn->armor = armor;

	return typeEn;
}

