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

typedef struct EnemyList{
   struct Enemy *enemy;
   struct EnemyList *nextEnemy;
}EnemyList;

typedef struct MovementList{
   Movement movement;
   struct MovementList *nextMovement;
}MovementList;

EnemyList* newEnemyList(Enemy* firstEnemy);
void popEnemy(EnemyList *list, Enemy *enemy);
void moveEnemyList(EnemyList *list);
void drawEnemyList(EnemyList *list);
void removeEnemyList(EnemyList *list, Enemy *enemy);

MovementList* newMovementList(Movement firstMovement);
MovementList* headMovement(Movement movement, MovementList *list);
Movement getNextMovement(MovementList **list);

#endif
