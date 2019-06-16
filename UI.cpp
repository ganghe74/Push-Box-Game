#include "UI.h"

UI::UI() {
	init();
}

UI::~UI() {
	delwin(win_game);
	delwin(win_sub);
	endwin();
	cout << "Game Finished\n";
}
void UI::init() {
	// Initialize ncurses
	initscr();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();

	// Initialize colors  // init_pair(num, text color, bkgd color);
	start_color();
	init_pair(DEFAULT, COLOR_WHITE, COLOR_BLACK);
	init_pair(CHARACTER, COLOR_RED, COLOR_RED);
	init_pair(BOX, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(WALL, COLOR_WHITE, COLOR_WHITE);
	init_pair(EMPTY, COLOR_BLACK, COLOR_BLACK);
	init_pair(NOTHING, COLOR_BLACK, COLOR_BLACK);
	init_pair(TARGET, COLOR_GREEN, COLOR_GREEN);

	// Initialize windows
	resize_term(20, 35);
	border('|', '|', '-', '-', '+', '+', '+', '+');
	win_game = newwin(12, 12, 3, 3);
	wborder(win_game, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	win_sub = newwin(4, 12, 3, 19);

	wborder(win_sub, '|', '|', '-', '-', '+', '+', '+', '+');
		// Text
	mvprintw(1, 3, "Push Box Game!");
	mvprintw(16, 1, "Q - Quit   B - Back");
	mvprintw(17, 1, "R - Reset");
	mvprintw(18, 1, "Arrows - move");
	mvwprintw(win_game, 1, 1, "win_game");
	refresh();
	wrefresh(win_game);
	wrefresh(win_sub);
}

void UI::update_scr() {
	element(*board)[11] = game->getMap().getBoard();
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			char type = board[i][j].getType();
			wattron(win_game, COLOR_PAIR(type));
			mvwprintw(win_game, i + 1, j + 1, "%c", type);
		}
	}
	int target[13];
	game->getMap().getTarget(target);
	wattron(win_game, COLOR_PAIR(TARGET));
	for (int i = 0; i < target[0]; ++i) {
		int r = target[i * 2 + 1];
		int c = target[i * 2 + 2];
		if (board[r][c].getType() == 'b') continue;
		mvwprintw(win_game, r + 1, c + 1, "T");
	}
	int player[2];
	game->getL(player);
	wattron(win_game, COLOR_PAIR(CHARACTER));
	mvwprintw(win_game, player[0] + 1, player[1] + 1, "C");
	wrefresh(win_game);

	mvwprintw(win_sub, 1, 1, "Step : %-3d", game->getMap().getStep());
	mvwprintw(win_sub, 2, 1, "Push : %-3d", game->getMap().getPush());
	wrefresh(win_sub);
}

// Game Start!
void UI::start(pushBox *game) {
	this->game = game;
	while (true) {
		update_scr();
		int key = getch();
		if (isupper(key)) key = tolower(key);
		if (258 <= key && key <= 261) { key = "swad"[key - 258]; }
		if (key == 'q') break;
		game->order(key);
	}
	this->game = NULL;
}
