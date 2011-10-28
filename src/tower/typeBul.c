/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "typeBul.h"


TypeBul* createTypeBul(SDL_Surface* image, int speed) {

	TypeBul* typeBul = (TypeBul*)malloc( sizeof(TypeBul) );

	typeBul->image = image;
	typeBul->speed = speed;

	return typeBul;
}
