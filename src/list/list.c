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
 * \brief create a new generic list and add it's first enemy
 *
 * \param item The first item of the list
 * \return The first pointer of the list
 */

List* newList(void* item){
   List* newList = malloc(sizeof *newList);
   newList->item = item;
   newList->nextList = NULL;
  return newList; 
}
 
/**
 * \fn void pushList(List *list, void* item)
 * \brief Function which add an enemy in a List.
 *
 * \param list A generic list.
 * \param item The item to add in the list.
 */

void pushList(List *list, void* item){
   while(list->nextList != NULL){
      list = list->nextList;
   }
   list->nextList = (List*)malloc(sizeof *list);
   list->nextList->item = item;
   list->nextList->nextList = NULL;
}


/**
 * \fn void moveEnemyList(EnemyList *list);
 * \brief move an List of enemy
 * the function move each enemy of a list
 * \see moveEnemy
 * \param list a list of Enemy to move
 */

void moveEnemyList(List *list){
   moveEnemy(list->item);
   while(list->nextList){
      list = list->nextList;
      moveEnemy(list->item);
   }
}


/**
 * \fn void drawEnemyList(EnemyList *list)
 * \brief draw an List of enemy
 * the function draw each enemy of a list
 * \see drawEnemy
 * \param list a list of Enemy to move
 */

void drawEnemyList(EnemyList *list){
   drawEnemy(list->enemy);
   while(list->nextEnemy){
      list = list->nextEnemy;
      drawEnemy(list->enemy);
   }
}

/**
 * \fn void removeEnemyFromEnemy(Enemy *enemy, EnemyList *list)
 * \brief Function which remove an enemy in a List.
 *
 * \param enemy The enemy to remove from the list.
 * \param list A list of enemy.
 */

void removeEnemyFromList(Enemy *enemy, EnemyList *list){
   EnemyList* previousList = list;
   while(list->enemy != enemy){     //search of item which contain the enemy 
      if(list){ 
         removeEnemy(enemy);         //if the enemy is not in the list, we delete it
         return;
      }
      previousList = list;
      list = list->nextEnemy;
   }
   previousList->nextEnemy = list->nextEnemy;
   removeEnemy(enemy);
   if(previousList != list){
      free(list);
   }
  return; 
}

/**
 * \fn MovementList* newMovementList(Movement* firstMovement)
 * \brief create a new list and add it's first enemy
 *
 * \param firstMovement The first Movement of the list
 * \return The first pointer of the list
 */

MovementList* newMovementList(Movement firstMovement){
   MovementList *newList = (MovementList*)malloc(sizeof *newList);
   newList->movement = firstMovement;
   newList->nextMovement = NULL;
  return newList; 
}


/**
 * \fn void headMovement(Movement movement, MovementList *list)
 * \brief add a movement in a list
 * \param movement the movement to add
 * \param list the list to add tower
 */
 
MovementList* headMovement(Movement movement, MovementList *list){
   MovementList *firstMovementList = newMovementList(movement);
   firstMovementList->nextMovement = list;
  return firstMovementList;
}

/**
 * \fn Movement getNextMovement(MovementList *list)
 * \brief get a Movement from a MovementList
 * \param list the List of movement
 * \return the next movement
 */
 
Movement getNextMovement(MovementList **list){
   MovementList *toFree = *list;
   Movement nextMovement = (*list)->movement;
   *list = (*list)->nextMovement;
   free(toFree);
  return nextMovement;
}

