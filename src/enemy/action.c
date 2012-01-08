/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/

#include "action.h"

void viewportMoveUP(Viewport *viewport, Events *flags, void* unused){
	moveViewport(viewport, UP);
}

void viewportMoveDOWN(Viewport *viewport, Events *flags, void* unused){
	moveViewport(viewport, DOWN);
}

void viewportMoveLEFT(Viewport *viewport, Events *flags, void* unused){
	moveViewport(viewport, LEFT);
}

void viewportMoveRIGHT(Viewport *viewport, Events *flags, void* unused){
	moveViewport(viewport, RIGHT);
}

void addTower(Viewport *viewport, Events *flags, void* _caseClicked){
	Case *caseClicked = (Case*) _caseClicked;
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

Action** initAction(){
	Action **actionList = (Action**)malloc(sizeof(**actionList * ActionType.LENGTH));
	*actionList[ActionType.QUIT] = NULL;
	*actionList[ActionType.ARROW_RIGHT] = &viewportMoveRIGHT;
	*actionList[ActionType.ARROW_DOWN] = &viewportMoveDOWN;
	*actionList[ActionType.ARROW_LEFT] = &viewportMoveLEFT;
	*actionList[ActionType.ARROW_UP] = &viewportMoveUP;
	*actionList[ActionType.CASE_CLICKED] = &addTower;
}
