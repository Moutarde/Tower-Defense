/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/
#ifndef PATHFINDING
#define PATHFINDING

#include "../map/case.h"
#include "../map/map.h"
#include "../enemy/enemy.h"
#include "../list/list.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
   int x,y;
   int cumulateNodeCost;
   struct node* previousNode;
}Node;

//typedef struct nodeList{
//   Node *node;
//   struct nodeList *nextList;
//}NodeList;

MovementList* searchPath(Case start, Case destination);
Node* getNode(Case cell);
List* head(Node *node, List *list);
Node* popHead(List **list);
bool theseTwoNodeAreEquals(Node *a, Node *b);
Node* amIInDaList(Node *node, List *list);
int heuristicCost(Node *node, Node *destination);
List* push(Node *node, List *list);
void tail(Node *node, List *list);
MovementList* pathReConstruction(Node *finalNode);
void freeList(List *list);
Movement nextMove(Case currentCase, Case nearCase);

#endif
