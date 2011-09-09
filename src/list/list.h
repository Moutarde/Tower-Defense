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


typedef struct EnemyList{
   Enemy *enemy;
   struct EnemyList* nextEnemy;
} EnemyList;


EnemyList* newEnemyList(Enemy* firstEnemy);
void popEnemy(EnemyList *list, Enemy *enemy);
void removeEnemy(EnemyList *list, Enemy *enemy);

EnemyList* newEnemyList(Enemy* firstEnemy);
void moveEnemyList(EnemyList *list);
void drawEnemyList(EnemyList *list);

#endif
