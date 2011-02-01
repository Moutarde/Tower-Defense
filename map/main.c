#include "map.h"

int main() {
	SDL_Surface* screen = NULL;

	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Tower Defense", NULL);



	SDL_Quit();

	return EXIT_SUCCESS;
}
