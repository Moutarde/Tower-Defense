/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/

#include "action.h"


/**
 * \fn char* viewportMoveUP(Viewport *viewport, Events *flags, void* unused)
 * \brief Move viewport to the up
 *
 * \param viewport the viewport to move
 */

void viewportMoveUP(Viewport *viewport, Events *flags, void* unused){
	moveViewport(viewport, UP);
}

/**
 * \fn char* viewportMoveDOWN(Viewport *viewport, Events *flags, void* unused)
 * \brief Move viewport to the down
 *
 * \param viewport the viewport to move
 */

void viewportMoveDOWN(Viewport *viewport, Events *flags, void* unused){
	moveViewport(viewport, DOWN);
}

/**
 * \fn char* viewportMoveLEFT(Viewport *viewport, Events *flags, void* unused)
 * \brief Move viewport to the left
 *
 * \param viewport the viewport to move
 */

void viewportMoveLEFT(Viewport *viewport, Events *flags, void* unused){
	moveViewport(viewport, LEFT);
}

/**
 * \fn char* viewportMoveRIGHT(Viewport *viewport, Events *flags, void* unused)
 * \brief Move viewport to the right
 *
 * \param viewport the viewport to move
 */
 
void viewportMoveRIGHT(Viewport *viewport, Events *flags, void* unused){
	moveViewport(viewport, RIGHT);
}

/**
 * \fn void addTower(Viewport *viewport, Events *flags, void* _caseClicked)
 * \brief Add a tower under the mouse
 *
 * \param viewport the viewport to move
 * \param _caseClicked the position of the mouse
 */

void addTower(Viewport *viewport, Events *flags, void* caseClicked_){
	Case *caseClicked = caseClicked_;
	TypeTo* simpleTowerType = flags->selectedTower;
	Case *viewportOffset = whichCase(viewport->surface.x,viewport->surface.y);
	int mapPositionX = caseClicked->xx + viewportOffset->xx;
	int mapPositionY = caseClicked->yy + viewportOffset->yy;
	Tower *tower = createTower(mapPositionX, mapPositionY, simpleTowerType);
	if(tower){
	   flags->enemy_Path_Calculation = true;
	   pushList((void*)flags->towerList,tower);
	   drawTower(tower);
	}
}

/**
 * \fn Action** initAction()
 * \brief init List of possible action
 */
 
Action* initAction(void){
	Action *actionList = malloc(ACTION_LENGTH * sizeof(Action));

	actionList[QUIT].boolean = NULL;
	actionList[QUIT].action = NULL;
	
	actionList[ARROW_UP].boolean = NULL;
	actionList[ARROW_UP].action = &viewportMoveUP;

	actionList[ARROW_RIGHT].boolean = NULL;
	actionList[ARROW_RIGHT].action = &viewportMoveRIGHT;

	actionList[ARROW_DOWN].boolean = NULL;
	actionList[ARROW_DOWN].action = &viewportMoveDOWN;

	actionList[ARROW_LEFT].boolean = NULL;
	actionList[ARROW_LEFT].action = &viewportMoveLEFT;

	actionList[CASE_CLICKED].boolean = NULL;
	actionList[CASE_CLICKED].action = &addTower;
  return actionList;
}
