#include <iostream>
#include <vector>
#include <ncurses.h>
using namespace std;


class items {
public:
	int boardList[5][10][10] = {
	{
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 1, 1, 1, 1, 1, 4, 4, 4},
		{4, 4, 1, 0, 0, 0, 1, 4, 4, 4},
		{4, 4, 1, 3, 3, 3, 1, 4, 4, 4},
		{4, 4, 1, 2, 2, 2, 1, 1, 4, 4},
		{4, 4, 1, 0, 0, 0, 0, 1, 4, 4},
		{4, 4, 1, 0, 0, 0, 0, 1, 4, 4},
		{4, 4, 1, 1, 1, 1, 1, 1, 4, 4},
	},
	{
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 1, 1, 1, 1, 4, 4, 4, 4},
		{4, 4, 1, 3, 0, 1, 1, 4, 4, 4},
		{4, 4, 1, 3, 2, 0, 1, 4, 4, 4},
		{4, 4, 1, 3, 0, 0, 1, 4, 4, 4},
		{4, 4, 1, 1, 2, 0, 1, 1, 1, 4},
		{4, 4, 4, 1, 0, 2, 0, 0, 1, 4},
		{4, 4, 4, 1, 0, 0, 0, 0, 1, 4},
		{4, 4, 4, 1, 0, 0, 1, 1, 1, 4},
		{4, 4, 4, 1, 1, 1, 1, 4, 4, 4},
	},
	{
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 1, 1, 1, 1, 1, 1, 1, 1, 4},
		{4, 1, 3, 0, 0, 0, 0, 0, 1, 4},
		{4, 1, 0, 3, 2, 2, 2, 0, 1, 4},
		{4, 1, 3, 0, 0, 0, 0, 0, 1, 4},
		{4, 1, 1, 1, 1, 1, 0, 0, 1, 4},
		{4, 4, 4, 4, 4, 1, 0, 0, 1, 4},
	},
	{
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 1, 1, 1, 1, 1, 1, 1, 4},
		{4, 4, 1, 0, 0, 0, 0, 0, 1, 4},
		{4, 4, 1, 0, 3, 2, 3, 0, 1, 4},
		{4, 4, 1, 0, 2, 3, 2, 0, 1, 4},
		{4, 4, 1, 0, 3, 2, 3, 0, 1, 4},
		{4, 4, 1, 0, 2, 3, 2, 0, 1, 4},
		{4, 4, 1, 0, 0, 0, 0, 0, 1, 4},
		{4, 4, 1, 1, 1, 1, 1, 1, 1, 4},
	},
	{
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 1, 1, 1, 1, 4, 4, 4, 4, 4},
		{4, 1, 0, 0, 1, 1, 1, 1, 4, 4},
		{4, 1, 0, 0, 0, 0, 0, 1, 1, 4},
		{1, 1, 0, 1, 1, 0, 0, 0, 1, 4},
		{1, 3, 0, 3, 1, 0, 0, 2, 1, 1},
		{1, 0, 0, 0, 1, 0, 2, 2, 0, 1},
		{1, 0, 0, 3, 1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	}
	};

	int characterList[11][2] = {
		{8, 4}, {3, 4}, {6, 7}, {8, 5}
	};

	int returnObj(int level, int i, int j) const {
		return boardList[level][i][j];
	}

	int* returnCharacter(int level) {
		if (level >= 5) return NULL;
		return characterList[level];
	};
};

class element {
	char type;
public:
	char getType() const { return type; }
	void setType(char t) { type = t; }
};

class nothing : public element {
public:
	nothing() {
		setType('n');
	}
};

class wall : public element { // ??

public:
	wall() {
		setType('w');
	}
};

class Box : public element {
public:
	Box() {
		setType('b');
	}
};

class emptySpace : public element {
public:
	emptySpace() {
		setType('e');
	}
};

class character {
	int r, c;

public:
	pair<int, int> getLocation() const {
		pair<int, int> p = make_pair(r, c);
		return p;
	}
	void setLocation(int row, int col) {
		r = row;
		c = col;
	}
};

class map {
	character user;
	element board[11][11];
	items itemList;
	int step, push, currlevel;
	int target[13];
	char preMove;
	bool preBoxMove;

public:
	map() {
		start(0);
	}

	int getCurrLevel() const { return currlevel; }
	int getStep() const { return step; }
	int getPush() const { return push; }
	character getUser() { return user; }
	element(*getBoard())[11]{ return board; }
	void getTarget(int *ptr) {
		int n = target[0];
		ptr[0] = target[0];
		for (int i=1;i<2*n+1;i+=2) {
			ptr[i] = target[i];
			ptr[i+1] = target[i+1];
		}
	}

	void start(int level = 0) {
		currlevel = level;
		target[0] = 0; int n = 1;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				int temp = itemList.returnObj(level, i, j);
				if (temp == 0) board[i][j] = emptySpace();
				else if (temp == 1) board[i][j] = wall();
				else if (temp == 2) board[i][j] = Box();
				else if (temp == 3) {
					board[i][j] = emptySpace();
					target[0]++;
					target[n] = i;
					target[n + 1] = j;
					n += 2;
				}
				else board[i][j] = nothing();
			}
		}
		int* rc = itemList.returnCharacter(0);
		user.setLocation(rc[0], rc[1]);
		step = 0;
		push = 0;
	}

	bool move(char order) {
		pair<int, int> l;
		l = user.getLocation();
		if (order == 'w') {
			if (l.first == 0) return false;
			if (board[l.first - 1][l.second].getType() == 'e') {
				user.setLocation(l.first - 1, l.second);
				preMove = 'w';
				preBoxMove = false;
			}
			else if (board[l.first - 1][l.second].getType() == 'b') {
				if (l.first == 1) return false;
				if (board[l.first - 2][l.second].getType() == 'e') {
					user.setLocation(l.first - 1, l.second);
					board[l.first - 2][l.second] = Box();
					board[l.first - 1][l.second] = emptySpace();
					preMove = 'w';
					preBoxMove = true;
					push++;
				}
			}
			else return false;
			step++;
			return true;
		}
		else if (order == 's') {
			if (l.first == 9) return false;
			if (board[l.first + 1][l.second].getType() == 'e') {
				user.setLocation(l.first + 1, l.second);
				preMove = 's';
				preBoxMove = false;
			}
			else if (board[l.first + 1][l.second].getType() == 'b') {
				if (l.first + 1 == 9) return false;
				if (board[l.first + 2][l.second].getType() == 'e') {
					user.setLocation(l.first + 1, l.second);
					board[l.first + 1][l.second] = emptySpace();
					board[l.first + 2][l.second] = Box();
					preMove = 's';
					preBoxMove = true;
					push++;
				}
			}
			else return false;
			step++;
			return true;
		}
		else if (order == 'a') {
			if (l.second == 0) return false;
			if (board[l.first][l.second - 1].getType() == 'e') {
				user.setLocation(l.first, l.second - 1);
				preMove = 'a';
				preBoxMove = false;
			}
			else if (board[l.first][l.second - 1].getType() == 'b') {
				if (l.second == 1) return false;
				if (board[l.first][l.second - 2].getType() == 'e') {
					user.setLocation(l.first, l.second - 1);
					board[l.first][l.second - 2] = Box();
					board[l.first][l.second - 1] = emptySpace();
					preMove = 'a';
					preBoxMove = true;
					push++;
				}
			}
			else return false;
			step++;
			return true;
		}
		else if (order == 'd') {
			if (l.second == 9) return false;
			if (board[l.first][l.second + 1].getType() == 'e') {
				user.setLocation(l.first, l.second + 1);
				preMove = 'd';
				preBoxMove = false;
			}
			else if (board[l.first][l.second + 1].getType() == 'b') {
				if (l.second == 8) return false;
				if (board[l.first][l.second + 2].getType() == 'e') {
					user.setLocation(l.first, l.second + 1);
					board[l.first][l.second + 2] = Box();
					board[l.first][l.second + 1] = emptySpace();
					preMove = 'd';
					preBoxMove = true;
					push++;
				}
			}
			else return false;
			step++;
			return true;
		}
		return false;
	}

	void reset() {
		start(currlevel);
	}

	bool revert() {
		pair<int, int> p = user.getLocation();
		if (preMove == 'w') {
			if (preBoxMove && p.first != 0) {
				board[p.first][p.second] = Box();
				board[p.first - 1][p.second] = emptySpace();
				push--;
			}
			user.setLocation(p.first + 1, p.second);
		}
		else if (preMove == 's') {
			if (preBoxMove && p.first != 9) {
				board[p.first][p.second] = Box();
				board[p.first + 1][p.second] = emptySpace();
				push--;
			}
			user.setLocation(p.first - 1, p.second);
		}
		else if (preMove == 'a') {
			if (preBoxMove && p.second != 0) {
				board[p.first][p.second] = Box();
				board[p.first][p.second - 1] = emptySpace();
				push--;
			}
			user.setLocation(p.first, p.second + 1);
		}
		else if (preMove == 'd') {
			if (preBoxMove && p.second != 9) {
				board[p.first][p.second] = Box();
				board[p.first][p.second + 1] = emptySpace();
				push--;
			}
			user.setLocation(p.first, p.second - 1);
		}
		else return false;
		step--;
		preMove = ' ';
		preBoxMove = false;
		return true;
	}

	bool check() {
		int * temp = target;
		int n = temp[0];
		for (int i = 1; i < n * 2 + 1; i += 2) {
			if (board[temp[i]][temp[i + 1]].getType() != 'b') return false;
		}
		return true;
	}
};

class pushBox {
private:
	map Map;

public:
	pushBox() {
		Map = map();
		Map.start();
	}

	void order(char order) {
		if (order == 'b') Map.revert();
		else if (order == 'r') Map.reset();
		else {
			if (Map.move(order)) {
				if (Map.check()) {
					Map.start(Map.getCurrLevel() + 1);
				}
			}
		}
	}

	map getMap() {
		return Map;
	}

	pair<int, int> getL() {
		return Map.getUser().getLocation();
	}

};


enum palette { DEFAULT, CHARACTER, BOX, WALL, EMPTY, NOTHING, TARGET };

class UI {
public:
	UI() {
		init();
	}
	~UI() {
		delwin(win_game);
		delwin(win_sub);
		endwin();
		cout << "Finished\n";
		cout << "Score : ~~~\n";
	}

	void init() {
		// Initialize ncurses
		initscr();
		curs_set(0);
		noecho();

		// Initialize colors  // init_pair(num, text color, bkgd color);
		start_color();
		init_pair(DEFAULT, COLOR_WHITE, COLOR_BLACK);
		init_pair(CHARACTER, COLOR_WHITE, COLOR_RED);
		init_pair(BOX, COLOR_WHITE, COLOR_YELLOW);
		init_pair(WALL, COLOR_WHITE, COLOR_WHITE);
		init_pair(EMPTY, COLOR_BLACK, COLOR_BLACK);
		init_pair(NOTHING, COLOR_BLACK, COLOR_BLACK);
		init_pair(TARGET, COLOR_WHITE, COLOR_GREEN);

		// Initialize windows
		resize_term(20, 30);
		border('*', '*', '*', '*', '*', '*', '*', '*');
		win_game = newwin(12, 12, 3, 3);
		wborder(win_game, '@', '@', '@', '@', '@', '@', '@', '@');
		win_sub = newwin(10, 10, 3, 17);
		wborder(win_sub, '@', '@', '@', '@', '@', '@', '@', '@');

		// Text
		mvprintw(1, 3, "Push Box Game!");
		mvprintw(16, 1, "  W    Q - quit   B - Back");
		mvprintw(17, 1, " Asd   R - reset(?)");
		mvprintw(18, 2, "move");
		mvwprintw(win_game, 1, 1, "win_game");
		mvwprintw(win_sub, 1, 1, "win_sub\n Score~~~");
		refresh();
		wrefresh(win_game);
		wrefresh(win_sub);
	}

	void update_scr() {
		element(*board)[11] = game->getMap().getBoard();
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				char type = board[i][j].getType();
				// if문 최적화예정
				if (type == 'b') wattron(win_game, COLOR_PAIR(BOX));
				else if (type == 'w') wattron(win_game, COLOR_PAIR(WALL));
				else if (type == 'e') wattron(win_game, COLOR_PAIR(EMPTY));
				else if (type == 'n') wattron(win_game, COLOR_PAIR(NOTHING));
				else wattron(win_game, COLOR_PAIR(DEFAULT));
				mvwprintw(win_game, i + 1, j + 1, "%c", type);
			}
		}
		int target[13];
		game->getMap().getTarget(target);
		wattron(win_game, COLOR_PAIR(TARGET));
		for (int i=0;i<target[0];++i) {
			int r = target[i*2+1];
			int c = target[i*2+2];
			if (board[r][c].getType() == 'b') continue;
			mvwprintw(win_game, r + 1, c + 1, "T");
		}
		pair<int, int> player = game->getL();
		wattron(win_game, COLOR_PAIR(CHARACTER));
		mvwprintw(win_game, player.first + 1, player.second + 1, "C");
		wrefresh(win_game);
	}

	// Game Start!
	void start(pushBox *game) {
		this->game = game;
		while (true) {
			update_scr();
			char key = getch();
			if (key == 'q') break;
			game->order(key);
		}
		this->game = NULL;
	}

private:
	pushBox *game;
	WINDOW *win_game;
	WINDOW *win_sub;
};

int main() {
	pushBox p = pushBox();

	UI ui;
	ui.start(&p);

	return 0;
}
