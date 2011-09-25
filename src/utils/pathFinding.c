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
 * \fn MovementList* searchPath(Case start, Case destination)
 * \brief The A star algorithm implementation.
 *
 * \param start The case where a enemy is.
 * \param destination The case a enemy must go.
 * \return The path.
 */     
MovementList* searchPath(Case start, Case destination) {
	//Initialisation
	Node* endNode = getNode(destination);
	Node* firstNode = getNode(start);
	firstNode->cumulateNodeCost = 0;
	MovementList* nextMoves;
	
	/*
	 There are two lists :
	 - the openList contains a set of to process node;
	 - the closedList contains a set of already processed node
	 */
	List* openList = newList(NULL);
	openList = head(firstNode, openList);
	
	List* closedList = NULL;
	
	// *A Star*
	
	/*
	 if there aren't any node in openList and the path aren't be found,
	 there aren't any path
	 */
	
	while(openList->nextList) {               
		Node* lowestHeuristic = popHead(&openList);    // we test the most closer node (with the lowest heuristic cost)
		if(theseTwoNodeAreEquals(lowestHeuristic,endNode)) {
			nextMoves = pathReConstruction(lowestHeuristic);    // if we have reached the final node, a path have been found
			freeList(openList);
			freeList(closedList);
			return nextMoves;
		}
		
		closedList = push(lowestHeuristic,closedList);    // this node have been computed
		
		/*
		 For each node near the one which is computed,
		 we check if he have already computed or cannot be tested (if it's a wall or a tower)
		 */
		int i, j;
		float k;
		for( i=-1, j=0, k=0.5; k<=2; j =- ((( (int)(-2*k) - 1 )%3)+1), i=(int)(k+=0.5) - 1 ) {    // i={-1,0,0,1} j={0,1,-1,0}
			Case nearCase = *getCase(i+lowestHeuristic->x, j+lowestHeuristic->y);    // get the four Case near the one already computed 
			Node *nearNode = getNode(nearCase);
			
			if(nearCase.hasTower || amIInDaList(nearNode, closedList)) {    // we are not open to node already computed or 
				continue;    // wich can't be walked on
			}
			
			/*
			 * then we calculate their heuristic cost (node with less heuristic are prefered
			 * for the path)
			 */
			
			// complete node's construction
			nearNode->previousNode = lowestHeuristic;
			// and calculate it heuristic
			nearNode->cumulateNodeCost = heuristicCost(nearNode,endNode);
			
			Node *openNode = amIInDaList(nearNode,openList);    //if the node is already in the openList
			
			if(openNode){    //we check if the new one have better heuristic
				if(openNode->cumulateNodeCost > nearNode->cumulateNodeCost) {    //if so, we switch the two node
					openNode->cumulateNodeCost = nearNode->cumulateNodeCost;    //else (if it is not in the openList)
					openNode->previousNode = nearNode->previousNode;    //we simply put it in
				}
			}
			else {
				openList = push(nearNode,openList);
			}
		}
	}         
	freeList(openList);
	freeList(closedList);
	return NULL;
}

/**
 * \fn Node* getNode(Case cell)
 * \brief Transforms a Case into a Node.
 * Only the x,y part of the node is initialised.
 * 
 * \param cell The case to transform.
 * \return A Node based on the Case.
 */
Node* getNode(Case cell) {
	Node* node = (Node*)malloc(sizeof *node);
	node->x = cell.xx;
	node->y = cell.yy;
	node->previousNode = NULL;
	node->cumulateNodeCost = -1;
	return node;
}

/**
 * \fn List* head(Node* node, List* list)
 * \brief Adds a Node in front of a list.
 * 
 * \param node The Node to add.
 * \param list The list which the node is added.
 * \return The pointer of first item.
 */
List* head(Node* node, List* list) {
	List* firstItem = newList(NULL);
	firstItem->item = node;
	firstItem->nextList = list;
	return firstItem;
}

/**
 * \fn Node* popHead(List** list)
 * \brief Gets the first item of a list.
 * 
 * \param list The list which item must be extracted.
 * \return The extracted item.
 */
Node* popHead(List** list){
	List* head = *list;
	Node* headNode = (*list)->item;
	*list = (*list)->nextList;
	free(head);
	return headNode;
}

/**
 * \fn bool theseTwoNodeAreEquals(Node* a, Node* b)
 * \brief Compares two Nodes.
 * Two node are equals if they have the same position (x,y)
 * 
 * \param a 
 * \param b 
 * \return 
 */
bool theseTwoNodeAreEquals(Node* a, Node* b) {
	return (a->x == b->x) && (a->y == b->y);    //NULL != NULL
}

/**
 * \fn Node* amIInDaList(Node* node, List* list)
 * \brief Searches in a List a particular Node.
 * 
 * \param node The node to search.
 * \param list The list to search into.
 * \return The Node if found, NULL otherwise.
 */
Node* amIInDaList(Node* node, List* list) {
	if(!list || !list->item) {
		return NULL;
	}
	if(theseTwoNodeAreEquals(node, list->item)) {
		return list->item;
	}
	while(list->nextList) {
		if(theseTwoNodeAreEquals(node, list->item)) {
			return list->item;
		}
		list = list->nextList;
	}
	
	return NULL;
}

/**
 * \fn int heuristicCost(Node* node, Node* destination)
 * \brief Function which calculates the heuristic cost of a node.
 * The A star algorithm uses node cost to choose the best path.
 * 
 * \param node A node to calculate is heuristic cost.
 * \param destination The destination a path.
 * \return The heuristic cost of the node.
 */
int heuristicCost(Node* node, Node* destination) {
	int fromStart = node->previousNode?node->previousNode->cumulateNodeCost:0;
	
	int abs = node->x - destination->x;
	int toDestination = abs > 0?abs:-abs;
	
	abs = node->y - destination->y;
	toDestination += abs > 0?abs:-abs;
	
	return toDestination + fromStart; 
}

/**
 * \fn List* push(Node* node, List* list)
 * \brief Adds a Node into a list (in the middle).
 * Items are sorted by their heuristicCost.
 * 
 * \param node The node to be added.
 * \param list The list to be added to.
 * \return The new (or old) first item of the list.
 */
List* push(Node* node, List* list) {
	List* firstItem = list;
	int cost = node->cumulateNodeCost;
	List* theOneBefore = list;
	if(!list || !list->item || cost < ((Node*)(list->item))->cumulateNodeCost) {
		return head(node, list);
	}
	// we search the right position to push (before the one wich has a more heuristic cost)
	while(cost > ((Node*)(list->item))->cumulateNodeCost) {
		theOneBefore = list;
		list = list->nextList;
		
		if(!list || !list->item) {
			tail(node, theOneBefore);
			return firstItem;
		}
	}
	
	head(node, list);
	tail(node, theOneBefore);   
	return firstItem;
}

/**
 * \fn void tail(Node* node, List* list)
 * \brief Adds a Node on bottom of a list.
 * 
 * \param node The Node to add.
 * \param list The last item of the list where the node will be added.
 */
void tail(Node* node, List* list) {
	List *lastItem = newList(NULL);
	lastItem->item = node;
	list->nextList = lastItem;
}

/**
 * \fn MovementList* pathReConstruction(Node* finalNode)
 * \brief Searches through the list, the path.
 * 
 * \param finalNode The destination node.
 * \return The direction an enemy must go.
 */
MovementList* pathReConstruction(Node* finalNode) {
	Node* nextNode = finalNode;
	MovementList* list = newMovementList(STAY);
	while(finalNode->previousNode) {
		nextNode = finalNode;
		finalNode = finalNode->previousNode;
		Case* currentCase = getCase(finalNode->x, finalNode->y);
		Case* nearCase = getCase(nextNode->x, nextNode->y);
		
		list = headMovement(nextMove(*currentCase, *nearCase), list);
	}
	return list;
}

/**
 * \fn Movement nextMove(Case currentCase, Case nearCase)
 * \brief Calculates a Movement to go to nearCase from currentCase.
 * 
 * \param currentCase The first cell.
 * \param nearCase The second cell.
 * \return The Movement to go to second cell from first cell.
 */
Movement nextMove(Case currentCase, Case nearCase) {
	switch(currentCase.xx - nearCase.xx) {
		case 1:
			return LEFT;
		case -1:
			return RIGHT;
	}
	switch(currentCase.yy - nearCase.yy) {
		case 1:
			return UP;
		case -1:
			return DOWN;
	}
	return STAY;
}

/**
 * \fn void freeList(List* list)
 * \brief Clears list.
 * 
 * \param list A list to free.
 */
void freeList(List* list) {
	if(list->item) {
		if(list->nextList) {
			if(list->item != list->nextList->item) {
				free(list->item);
			}
			
			freeList(list->nextList);
		}
	}
	free(list);
	return;
}
