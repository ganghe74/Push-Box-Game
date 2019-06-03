#pragma once
#ifndef UI_H
#define UI_H
#include "pushBox.h"
#include <ncurses.h>

enum palette { DEFAULT, CHARACTER, BOX, WALL, EMPTY, NOTHING, TARGET };

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