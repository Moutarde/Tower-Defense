/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */


#include "list.h"


/**
 * \fn List* newList(void* item)
 * \brief Creates a new generic list and adds it's first enemy.
 *
 * \param item The first item of the list.
 * \return The first pointer of the list.
 */
List* newList(void* item) {
	List* newList = malloc(sizeof *newList);
	newList->item = item;
	newList->nextList = NULL;
	return newList; 
}
 
/**
 * \fn void pushList(List* list, void* item)
 * \brief Function which adds an enemy in a List.
 *
 * \param list A generic list.
 * \param item The item to add in the list.
 */
void pushList(List* list, void* item) {
	while(list->nextList != NULL) {
		list = list->nextList;
	}
	list->nextList = (List*)malloc(sizeof *list);
	list->nextList->item = item;
	list->nextList->nextList = NULL;
}

/**
 * \fn void moveEnemyList(List* list);
 * \brief Moves an List of enemy.
 * The function moves each enemy of a list.
 * 
 * \see moveEnemy
 * \param list A list of Enemy to move.
 */
void moveEnemyList(List* list) {
	moveEnemy(list->item);
	while(list->nextList) {
		list = list->nextList;
		moveEnemy(list->item);
	}
}

/**
 * \fn void drawEnemyList(List* list)
 * \brief Draws an List of enemy.
 * The function draws each enemy of a list.
 * 
 * \see drawEnemy
 * \param list A list of Enemy to draw.
 */
void drawEnemyList(List* list) {
	drawEnemy(list->item);
	while(list->nextList) {
		list = list->nextList;
		drawEnemy(list->item);
	}
}

/**
 * \fn void removeEnemyFromList(Enemy* enemy, List* list)
 * \brief Function which removes an enemy in a List.
 *
 * \param enemy The enemy to remove from the list.
 * \param list A list of enemy.
 */
void removeEnemyFromList(Enemy* enemy, List* list) {
	List* previousList = list;
	// Search of item which contains the enemy
	while(list->item != enemy) {
		if(list) { 
			// if the enemy is not in the list, we delete it
			removeEnemy(enemy);
			return;
		}
		previousList = list;
		list = list->nextList;
	}
	previousList->nextList = list->nextList;
	removeEnemy(enemy);
	if(previousList != list) {
		free(list);
	}
}

/**
 * \fn MovementList* newMovementList(Movement firstMovement)
 * \brief Creates a new list and adds it's first Movement.
 *
 * \param firstMovement The first Movement of the list.
 * \return The first pointer of the list.
 */
MovementList* newMovementList(Movement firstMovement) {
	MovementList* newList = (MovementList*)malloc(sizeof *newList);
	newList->movement = firstMovement;
	newList->nextMovement = NULL;
	return newList; 
}


/**
 * \fn MovementList* headMovement(Movement movement, MovementList* list)
 * \brief Adds a movement in a list.
 * 
 * \param movement The movement to add.
 * \param list 
 */
MovementList* headMovement(Movement movement, MovementList* list) {
	MovementList* firstMovementList = newMovementList(movement);
	firstMovementList->nextMovement = list;
	return firstMovementList;
}

/**
 * \fn Movement getNextMovement(MovementList** list)
 * \brief Gets a Movement from a MovementList.
 * 
 * \param list The List of movement.
 * \return The next movement.
 */
Movement getNextMovement(MovementList** list) {
	MovementList* toFree = *list;
	Movement nextMovement = (*list)->movement;
	*list = (*list)->nextMovement;
	free(toFree);
	return nextMovement;
}

