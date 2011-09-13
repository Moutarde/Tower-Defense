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
 * \fn EnemyList* newEnemyList(Enemy* firstEnemy)
 * \brief create a new list and add it's first enemy
 *
 * \param firstEnemy The first Enemy of the list
 * \return The first pointer of the list
 */

EnemyList* newEnemyList(Enemy* firstEnemy){
   EnemyList* newList = malloc(sizeof *newList);
   newList->enemy = firstEnemy;
   newList->nextEnemy = NULL;
  return newList; 
}
 

/**
 * \fn void popEnemy(EnemyList *list, Enemy *enemy)
 * \brief Function which add an enemy in a List.
 *
 * \param list A list of enemy.
 * \param enemy The enemy to add in the list.
 */

void popEnemy(EnemyList *list, Enemy *enemy){
   while(list->nextEnemy != NULL){
      list = list->nextEnemy;
   }
   list->nextEnemy = (EnemyList*)malloc(sizeof *list);
   list->nextEnemy->enemy = enemy;
   list->nextEnemy->nextEnemy = NULL;
}

/**
 * \fn void removeFromEnemy(Enemy *enemy, EnemyList *list)
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
 * \fn void moveEnemyList(EnemyList *list);
 * \brief move an List of enemy
 * the function move each enemy of a list
 * \see moveEnemy
 * \param list a list of Enemy to move
 */

void moveEnemyList(EnemyList *list){
   moveEnemy(list->enemy);
   while(list->nextEnemy){
      list = list->nextEnemy;
      moveEnemy(list->enemy);
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

