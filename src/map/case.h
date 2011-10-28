/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#ifndef CASE_H
#define CASE_H

#define CSIZE 32;

#include <stdio.h>
#include <stdbool.h>


/**
 * \struct Case case.h
 * \brief A case structure.
 */
typedef struct {
	int x; int y;     //*!< pixel position of up-left corner
	int xx; int yy;   //*!< position of the case in the grid
	int size;         //*!< size of... something?... maybe...
	bool hasTower;    //*!< if there are a Tower on the Case
	bool hasEnemy;    //*!< if there are an Enemy on the Case
} Case;

#endif
