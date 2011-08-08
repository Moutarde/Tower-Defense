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
                     int normalSpeed,
                     bool canFly,
                     bool canBeSlowed,
                     bool canBePoisoned,
                     bool invisible,
                     int armor) {

	TypeEn* typeEn = (TypeEn*)malloc( sizeof(TypeEn) );

	typeEn->maxLife = maxLife;
	typeEn->normalSpeed = normalSpeed;
	typeEn->canFly = canFly;
	typeEn->canBeSlowed = canBeSlowed;
	typeEn->canBePoisoned = canBePoisoned;
	typeEn->invisible = invisible;
	typeEn->armor = armor;

	return typeEn;
}

/**
 * \fn Animation* createAnimation(char *sprite_sheet_name)
 * \brief create a way to use a sprite sheet for animation
 * The sprite sheet MUST be the same format as white_transparent_cat.png
 * 3x4 icon in "up, right, down, left" order and a transparent background
 * \param sprite_sheet_name path to the monster sprite sheet
 * \return pointer to animation tools 
 */
Animation createAnimation(char *sprite_sheet_name){
   Animation animation;
   animation.currentFrame = IMG_Load(sprite_sheet_name);
   animation.direction = STAY;
   int heigth = animation.currentFrame->h/4;
   int weigth = animation.currentFrame->w/4;
   for(int i=0;i<5;i++){
      animation.animation_state[i].h = heigth;
      animation.animation_state[i].w = weigth;
      animation.animation_state[i].x = 0;
      animation.animation_state[i].y = i*heigth;
   }
 
   animation.animation_state[STAY].x = 1 * weigth/3;
   animation.animation_state[STAY].y = 2 * heigth;

  return animation;
}
