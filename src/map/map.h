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
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "case.h"


typedef struct {
	int w;
	int h;
	int nbCaseW;
	int nbCaseH;
	Case** matrice;
	SDL_Surface* bg;
} Map;

extern Map* _map;
Map* createMap(char* mapName);
SDL_Surface* loadMap(char* mapName);
Case* getCase(int xx, int yy);
Case* whichCase(int x, int y);

#endif
