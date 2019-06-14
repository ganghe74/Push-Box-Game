#ifndef UI_H
#define UI_H
#include "pushBox.h"
#include <ncurses.h>
using namespace std;

enum palette { DEFAULT, CHARACTER, BOX = 'b', WALL = 'w', EMPTY = 'e', NOTHING = 'n', TARGET };

class UI {
public:
	UI();
	~UI();

	void init();

	void update_scr();

	// Game Start!
	void start(pushBox *game);

private:
	pushBox *game;
	WINDOW *win_game;
	WINDOW *win_sub;
};

#endif
