/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#ifndef flag_H
#define flag_H

#include "../tower/tower.h"
#include <stdbool.h>
#include "../list/list.h"

/**
 * \struct Events event.h
 * \brief An List of event to manage.
 */

typedef struct{
	bool enemy_Path_Calculation;	//!< 
	TypeTo *selectedTower;   		//!< 
	List *towerList;					//!< 
}Events;

#endif
