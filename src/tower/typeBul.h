/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#ifndef TYPEBUL
#define TYPEBUL
	#include <stdio.h>
	#include <SDL/SDL.h>

typedef struct {
	SDL_Surface* image;
	int speed;
} TypeBul;

TypeBul* createTypeBul(SDL_Surface* image, int speed);

#endif
