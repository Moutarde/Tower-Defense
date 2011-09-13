/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/

#include "pathFinding.h"

/**
 * \fn NodeList searchPath(Case start, Node destination)    
 * \brief the A star algorithm implementation
 *
 * \param start the case where a enemy is
 * \param destination the case a enemy must go
 * \return the path
 */
     
MovementList* searchPath(Case start, Case destination){
//Initialisation
   Node *endNode = getNode(destination);
   Node *firstNode = getNode(start);
   firstNode->cumulateNodeCost=0;
   MovementList *nextMoves;   
/*
   There are two list, the openList contain a set of to process node;
 the closedList contain a set of already processed node
*/   
   NodeList *openList = newList();
   openList = head(firstNode,openList);

   NodeList *closedList = NULL;

//*A Star*
/*
   if there aren't any node in openList and the path aren't be found,
 there aren't any path 
*/

   while(openList->nextList){               
      Node *lowestHeuristic = popHead(&openList); //we test the most closer node (with the lowest heuristic cost)
      if(theseTwoNodeAreEquals(lowestHeuristic,endNode)){
         nextMoves = pathReConstruction(lowestHeuristic);        //if we have reached the final node, a path have been found
         freeList(openList);
         freeList(closedList);
        return nextMoves;
      }

      closedList = push(lowestHeuristic,closedList);            //this node have been computed
      
/*
   For each node near the one which is computed,
   we check if he have already computed or cannot be tested (if it's a wall or a tower)
*/
      int i,j; float k;                                                          
      for(i=-1,j=0,k=0.5;k<=2;j=-(((((int)(-2*k)-1))%3)+1),i=(int)(k+=0.5)-1){   // i={-1,0,0,1} j={0,1,-1,0}
         Case nearCase = *getCase(i+lowestHeuristic->x,j+lowestHeuristic->y);           //get the four Case near the one already computed 
         Node *nearNode = getNode(nearCase);
     
         if(nearCase.hasTower || amIInDaList(nearNode,closedList)){            //we are not open to node already computed or 
            continue;                                                               //wich can't be walked on
         }
/*
   then we calculate their heuristic cost (node with less heuristic are prefered
   for the path)
*/     
         nearNode->previousNode = lowestHeuristic;                                     //complete node's construction
         nearNode->cumulateNodeCost = heuristicCost(nearNode,endNode);                 //and calculate it heuristic

         Node *openNode = amIInDaList(nearNode,openList);                     //if the node is already in the openList
     
         if(openNode){                                                                 //we check if the new one have better heuristic
             if(openNode->cumulateNodeCost > nearNode->cumulateNodeCost){                 //if so, we switch the two node
               openNode->cumulateNodeCost = nearNode->cumulateNodeCost;               //else (if it is not in the openList
               openNode->previousNode = nearNode->previousNode;                      //we simply put it in
             }                                                                            // 
         }else{                                                                           //
            openList = push(nearNode,openList);                                                      //
         }                                                                                //
         
         
      }
   }         
   freeList(openList);
   freeList(closedList);
  return NULL;
}

/**
 * \fn Node getNode(Case caze)
 * \brief Transform a Case into a Node
 * Only the x,y part of the node is initialised
 * \param caze The case to transform
 * \return A Node based on the Case
 */
 
Node* getNode(Case cell){
   Node *node = (Node*)malloc(sizeof *node);
   node->x = cell.xx;
   node->y = cell.yy;
   node->previousNode = NULL;
   node->cumulateNodeCost = -1;
 return node;
}

/**
 * \fn NodeList newList()
 * \brief create a Node List
 * these list are used by the A star algorithm
 * to store path already reached
 * \return The newly created node List
 */
 
NodeList* newList(){
   NodeList *list = (NodeList*)malloc(sizeof *list);
   list->nextList = NULL;
   list->node = NULL;
  return list;    
}

/**
 * \fn NodeList* head(Node node, NodeList list)
 * \brief add a Node in front of a list
 * 
 * \param node the Node to add
 * \param list the list which the node is added
 * \return the pointer of first item 
 */
 
NodeList* head(Node *node, NodeList *list){
   NodeList *firstItem = newList();
   firstItem->node = node;
   firstItem->nextList = list;
  return firstItem;
}

/**
 * \fn Node* popHead(NodeList **list)
 * \brief get the first item of a list
 * 
 * \param list The list which item must be extracted
 * \return The extracted item
 */
 
Node* popHead(NodeList **list){
   NodeList *head = *list;
   Node *headNode = (*list)->node;
   *list = (*list)->nextList;
   free(head);
  return headNode; 
}

/**
 * \fn bool theseTwoNodeAreEquals(Node *a, Node *b)
 * \brief compare two Node
 * Two node are equals if they have the same position (x,y)
 */

bool theseTwoNodeAreEquals(Node *a, Node *b){
   return (a->x == b->x) && (a->y == b->y);        //NULL != NULL
}

/**
 * \fn Node* amIInDaList(Node *node, NodeList *list)
 * \brief search in a NodeList a particular Node
 * 
 * \param node The node to search
 * \param list The list to search into
 * \return the Node if found, Null otherwise
 */
 
Node* amIInDaList(Node *node, NodeList *list){
   if(!list || !list->node){
      return NULL;
   }
   if(theseTwoNodeAreEquals(node,list->node)){
      return list->node;
   }
   while(list->nextList){
      if(theseTwoNodeAreEquals(node,list->node)){
         return list->node;
      }
      list = list->nextList;
   }
   
  return NULL; 
}

/**
 * \fn int heuristicCost(Node node, Case destination)
 * \brief Function which calculate the heuristic cost of a node.
 * the A star algorithm use node cost for choosing the best path 
 * \param node A node to calculate is heuristic cost
 * \param destination The destination a path
 * \return The heuristic cost of the node
 */
 
int heuristicCost(Node *node, Node *destination){
   int fromStart = node->previousNode?node->previousNode->cumulateNodeCost:0;

   int abs = node->x - destination->x;
   int toDestination = abs > 0?abs:-abs;

   abs = node->y - destination->y;
   toDestination += abs > 0?abs:-abs;
   
  return toDestination + fromStart; 
}



/**
 * \fn NodeList* push(Node *node, NodeList *list)    
 * \brief add a Node into a list (in the middle)
 * item are sorted by their heuristicCost
 * \param node The node to be added
 * \param list The list to be added to
 * \return the new (or old) first item of the list
 */

NodeList* push(Node *node, NodeList *list){
   NodeList *firstItem = list;
   int cost = node->cumulateNodeCost;
   NodeList *theOneBefore = list;
   if(!list || !list->node || cost < list->node->cumulateNodeCost){
      return head(node,list);
   }
// we search the right position to push (before the one wich have a more heuristic cost)
   while(cost > list->node->cumulateNodeCost){
      theOneBefore = list;
      list = list->nextList;

      if(!list || !list->node){
         tail(node,theOneBefore);
         return firstItem;
      }
   }
   
   head(node,list);
   tail(node,theOneBefore);   
  return firstItem;
}

/**
 * \fn void tail(Node node, NodeList list)
 * \brief add a Node on bottom of a list
 * 
 * \param node the Node to add
 * \param list the last item of the list which the node will be added
 */
 
void tail(Node *node, NodeList *list){
   NodeList *lastItem = newList();
   lastItem->node = node;
   list->nextList = lastItem;
}

/**
 * \fn Movement pathConstruction(Node *finalNode)
 * \brief search through the list, the path
 * 
 * \param finalNode the destination node
 * \return The direction a enemy must go
 */
 
MovementList* pathReConstruction(Node *finalNode){
   Node* nextNode = finalNode;
   MovementList *list = newMovementList(STAY);
   while(finalNode->previousNode){
      nextNode = finalNode;
      finalNode = finalNode->previousNode;
      Case *currentCase = getCase(finalNode->x,finalNode->y);
      Case *nearCase = getCase(nextNode->x,nextNode->y);

      list = headMovement(nextMove(*currentCase,*nearCase),list);
   }
  return list;
}

/**
 * \fn Movement nextMove(Case currentCase, Case nearCase)
 * \brief calculate a th Movement to go to nearCase from currentCase
 * \param currentCase the first cell
 * \param nearCase the second cell
 * \return the Movement to go to second cell from first cell
 */
 
Movement nextMove(Case currentCase, Case nearCase){
   switch(currentCase.xx - nearCase.xx){
      case 1:
         return LEFT;
      case -1:
         return RIGHT;
   }
   switch(currentCase.yy - nearCase.yy){
      case 1:
         return UP;
      case -1:
         return DOWN;
   }
  return STAY;
}

/**
 * \fn void freeList(NodeList *list)
 * \brief clear a list
 * \param list a list to free
 */
 
void freeList(NodeList *list){
   if(list->node){
      if(list->nextList){
         if(list->node != list->nextList->node){
            free(list->node);
         }
         
         freeList(list->nextList);
      }
   }
   free(list);
   return;
}

