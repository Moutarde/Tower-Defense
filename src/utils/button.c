/*
dev: Mickeymouse, Moutarde and Nepta
manager: Word
Copyright © 2011
You should have received a copy of the
GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.
*/


#include "button.h"

/**
 * \fn Button* button_createBuildButton(TypeTo* towerType)
 * \brief Create a button to build the specified tower type
 *
 * \param towerType the tower type
 * \return The button pointer
 */
Button* button_createBuildButton(TypeTo* towerType) {
	// Allocate the button
	Button* button = (Button*)malloc(sizeof(Button));
	// And sets its values
	button->type = BUILD;
	button->target = towerType;
	button->image = towerType->image;
	// Well thats pretty much it
	return button;
}
