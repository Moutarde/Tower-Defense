/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#ifndef TYPEEN_H
#define TYPEEN_H

#include <stdio.h>

#include <SDL/SDL.h>

typedef struct {
	int maxLife;
	SDL_Surface* image;
	int normalSpeed;
	int canFly;
	int canBeSlowed;
	int canBePoisoned;
	int invisible;
	int armor;
} TypeEn;

TypeEn* createTypeEn(int maxLife, SDL_Surface* image, int normalSpeed, int canFly, int canBeSlowed, int canBePoisoned, int invisible, int armor);

#endif

