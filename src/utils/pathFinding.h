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
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
   int x,y;
   int cumulateNodeCost;
   struct node* previousNode;
}Node;

typedef struct nodeList{
   Node *node;
   struct nodeList *nextList;
}NodeList;

Movement searchPath(Case start, Case destination);
Node* getNode(Case cell);
NodeList* newList();
NodeList* head(Node *node, NodeList *list);
Node* popHead(NodeList **list);
bool theseTwoNodeAreEquals(Node *a, Node *b);
Node* amIInDaList(Node *node, NodeList *list);
int heuristicCost(Node *node, Node *destination);
NodeList* push(Node *node, NodeList *list);
void tail(Node *node, NodeList *list);
Movement pathReConstruction(Node *finalNode);

#endif
