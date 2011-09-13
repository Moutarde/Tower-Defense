/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */

#ifndef LIST
#define LIST
#include "../enemy/enemy.h"

struct Enemy;

typedef struct List{
   void* item;
   struct List* nextList;
}List;

typedef struct EnemyList{
   struct Enemy *enemy;
   struct EnemyList *nextEnemy;
}EnemyList;

typedef struct MovementList{
   Movement movement;
   struct MovementList *nextMovement;
}MovementList;

List* newList(void* item);
void pushList(List *list, void* item);
void moveEnemyList(List *list);
void drawEnemyList(EnemyList *list);
void removeEnemyFromList(Enemy *enemy, EnemyList *list);

MovementList* newMovementList(Movement firstMovement);
MovementList* headMovement(Movement movement, MovementList *list);
Movement getNextMovement(MovementList **list);

#endif
