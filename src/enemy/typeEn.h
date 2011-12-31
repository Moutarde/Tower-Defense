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


typedef enum {UP, RIGHT, DOWN, LEFT, STAY} Movement;

/**
 * \struct Animation typeEnemy.h
 * \brief Current status of an animation
 */

typedef struct {
	Movement direction;				//!< Direction of enemy's sight
	SDL_Rect animation_state[5];	//!< list of animation frame
	SDL_Surface* currentFrame;		//!< Current frame in the sprite sheet
} Animation;

/**
 * \struct TypeEn typeEnemy.h
 * \brief Structure of enemy type
 */
 
typedef struct {
	int maxLife;			//!< Maximum life of an enemy
	int normalSpeed;		//!< Basic speed of an enemy /*!< An enemy can be slowed if he's touched with appropriate tower (ice tower...) */
	bool canFly;			//!< true if monster can fly over tower /*!< flying enemy can only be touched by specific tower */
	bool canBeSlowed;		//!< true if normalSpeed can be decreased
	bool canBePoisoned;	//!< true if the enemy can be poisoned
	bool invisible;		//!< true if the enemy can be invisible
	int armor;				//!< Current enemy defence
	char* picture;			//!< Enemy sprite sheet
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
