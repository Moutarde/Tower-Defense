/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#ifndef ACTION_H
#define ACTION_H

typedef void (*fAction)(Viewport *viewport, Events *flags);
typedef enum {
	QUIT,
	ARROW_UP,
	ARROW_RIGHT,
	ARROW_DOWN,
	ARROW_LEFT,
	CASE_CLICKED,
	LENGTH
}ActionType;

/**
 * \struct Action action.h
 * \brief An List of event to manage.
 */

typedef struct{
   void* boolean;			//!< if an action must be performed
   fAction action;		//!< the associated action to the event
}Action;

void viewportMoveUP(Viewport *viewport, Events *flags, void* unused);
void viewportMoveDOWN(Viewport *viewport, Events *flags, void* unused);
void viewportMoveLEFT(Viewport *viewport, Events *flags, void* unused);
void viewportMoveRIGHT(Viewport *viewport, Events *flags, void* unused);
void addTower(Viewport *viewport, Events *flags, void* _caseClicked);

#endif

