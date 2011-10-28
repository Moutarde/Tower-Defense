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
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef enum {UP, RIGHT, DOWN, LEFT, STAY}Movement;

typedef struct {
	Movement direction;
	SDL_Rect animation_state[5];
	SDL_Surface* currentFrame;
} Animation;

typedef struct {
	int maxLife;
	int normalSpeed;
	bool canFly;
	bool canBeSlowed;
	bool canBePoisoned;
	bool invisible;
	int armor;
	char* picture;
} TypeEn;

TypeEn* createTypeEn(int maxLife,
                     int normalSpeed,
                     bool canFly,
                     bool canBeSlowed,
                     bool canBePoisoned,
                     bool invisible,
                     int armor,
                     char* resources);

Animation createAnimation(char* sprite_sheet_name);
SDL_Rect* getRect(Animation* anim);

#endif
