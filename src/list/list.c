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
   EnemyList* newList = malloc(sizeof *newEnemyList);
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
 * \fn void removeEnemy(EnemyList *list, Enemy *enemy)
 * \brief Function which remove an enemy in a List.
 *
 * \param list A list of enemy.
 * \param enemy The enemy to remove from the list.
 */

void removeEnemy(EnemyList *list, Enemy *enemy){
   EnemyList* previousList = list;
   while(list->enemy != enemy){
      if(list == NULL){
         free(enemy);
         return;
      }
      previousList = list;
      list = list->nextEnemy;
   }
   previousList->nextEnemy = list->nextEnemy;
   free(list);
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
   while(list->nextEnemy !=NULL){
      list = list->nextEnemy;
      moveEnemy(list->enemy);
   }
}


