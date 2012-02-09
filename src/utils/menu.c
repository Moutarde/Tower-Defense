/*
dev: Mickeymouse, Moutarde and Nepta
manager: Word
Copyright © 2011
You should have received a copy of the
GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.
*/


#include "menu.h"


/**
 * \fn Menu* menu_createMenu(SDL_Rect surface)
 * \brief Create the menu
 *
 * \param screen The screen the menu will be drawn on
 * \param suface The surface which the menu will be.
 * \return The Menu pointer
 */
Menu* menu_create(SDL_Surface* screen, SDL_Rect surface){
	// Allocate the menu information
	Menu* menu = (Menu*)malloc(sizeof *menu);
	menu->screen = screen;
	menu->surface = surface;

	// Allocate the menu's button list 
	// (we allocate a single button and will reallocate when needed)
	menu->button = (Button**)malloc(sizeof(Button*));
	menu->buttonAmount = 0;

	menu->background = NULL;
	menu->minimap = NULL;

	// We can add buttons later anyway,
	// so there's pretty much nothing else to do.
  return menu;
}


/**
 * \fn void menu_addButton(Menu* menu, Button* newButton)
 * \brief Adds the button to the menu.. simple as that
 *
 * \param menu Menu to which append the button
 * \param button Button to add to the menu
 * \return
 */
void menu_addButton(Menu* menu, Button* newButton){
	// Because the size of the array is different, we'll have to reallocate it
	menu->button = (Button**)realloc(menu->button, (sizeof(Button*)) * (menu->buttonAmount + 1));
	// Now we can simply append the button to the end of the list
	(menu->button)[menu->buttonAmount++] = newButton;	
}


/**
 * \fn void menu_render(Menu* menu)
 * \brief Renders the menu
 *
 * \param menu Menu to render
 * \return
 */
void menu_render(Menu* menu){
	//FIXME All those screen positions and offset should really be constants somewhere. Same in main.c
	// As of now the viewport spans: 0-720 (x) 0-600 (y)
	// This leaves for the menu the 720-800, 0-600 area
	// The buttons are 32x32 images. So we'll space them with, say, 20 pixels each vertically.
	// These settings could be either header defines, or attributes of Menu

	SDL_Rect target;

	// Start by blitting the background image
	if(menu->background) SDL_BlitSurface(menu->background, NULL, menu->screen, &menu->surface);

	// Loop for every button and blit it
	for(int i=0; i < menu->buttonAmount; i++){
		target.x = 720 + (80-MENU_BUTTON_STANDARD_SIZE)/2;
		target.w = MENU_BUTTON_STANDARD_SIZE;
		target.y = 100 + (MENU_BUTTON_DISPLAY_OFFSET + MENU_BUTTON_STANDARD_SIZE)*i;
		target.h = MENU_BUTTON_STANDARD_SIZE;
		SDL_BlitSurface(((menu->button)[i])->image, NULL, menu->screen, &target);
	}
}


/**
 * \fn void menu_loadBackground(Menu* menu, char* resource)
 * \brief Loads and sets the menu background
 *
 * \param menu Menu to render
 * \param resource The background file location
 * \return
 */
void menu_loadBackground(Menu* menu, char* resource){
	//FIXME This really shouldnt use something from the Map functions... 
	menu->background = loadMap(getPath(resource));
	SDL_BlitSurface(menu->background, NULL, menu->screen, &menu->surface);
}

/**
 * \fn void menu_free(Menu* menu)
 * \brief Frees the memory used by the menu
 *
 * \param menu Pointer to the menu to free
 * \return
 */
void menu_free(Menu* menu){
	// We have to free each individual button
	for(int i=0; i<menu->buttonAmount; i++) free(menu->button[i]);
	// Then we can free the button list
	free(menu->button);
	// And lastly we free the menu
	free(menu);	
}



