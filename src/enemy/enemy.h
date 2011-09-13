/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#ifndef ENNEMY_H
#define ENNEMY_H

#include <stdio.h>
#include <stdbool.h>

#include "typeEn.h"
#include "../map/map.h"

struct MovementList;

/**
 * \struct Enemy enemy.h
 * \brief a enemy structure
 */

typedef struct {
	int x;   //!< x coordinate of the future position
	int y;   //!< y coordinate of the future position
   SDL_Rect animPosition; //!< coordinates of the actual animation position
	Animation animation;
	int life;//!< monster's life
	int speed;//!< monster's speed 
	bool isPoisoned;//!< true if the monster is poisoned /*!< when an enemy is poisoned, is life decrease whith time and is slowed down*/
	TypeEn* type;//!< monster's type
   struct MovementList *list; //!< a list of movement to reach the destination
} Enemy;



Enemy* createEnemy(int x, int y, TypeEn* type);
void drawEnemy(Enemy* enemy);
void moveEnemy(Enemy* enemy);
Movement nextMovement(Enemy* enemy);
void removeEnemy(Enemy *enemy);

#endif

