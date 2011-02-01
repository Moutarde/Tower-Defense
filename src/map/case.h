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

#include <stdio.h>

#define CSIZE 5;

typedef struct {
	int x;
	int y;
	int size;
	int hasTower;
	int hasEnemy;
} Case;

#endif
