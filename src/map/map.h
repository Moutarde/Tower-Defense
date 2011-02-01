/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#ifndef MAP
#define MAP

#include <stdio.h>

#include <SDL/SDL.h>

#include "case.h"

typedef struct {
	int w;
	int h;
	int nbCaseW;
	int nbCaseH;
	Case** matrice;
	SDL_Surface* bg;
} Map;

Map* createMap(int w, int h, SDL_Surface* bg);

#endif
