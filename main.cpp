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
		{4, 4, 1, 3, 0, 0, 1, 4, 4, 4},
		{4, 4, 1, 3, 0, 2, 1, 4, 4, 4},
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

	int target[5][5][2] = {
	{{5, 3}, {5, 4}, {5, 5}},
	{{2, 3}, {3, 3}, {4, 3}},
	{{5, 2}, {6, 3}, {7, 2}},
	{{4, 4}, {4, 6}, {5, 5}, {6, 4}, {6, 6}},
	{{6, 1}, {6, 3}, {8, 3}}
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
public:
	char color;
	char shape;
	bool move;
	char type;

	char getColor() { return color; }
	char getShape() { return shape; }
	bool getMove() { return move; }
	char getType() { return type; }
	void setColor(char c) { color = c; }
	void setShape(char s) { shape = s; }
	void setMove(bool m) { move = m; }
	void setType(char t) { type = t; }
};

class nothing : public element { // ?ƹ??͵? ???? ?ȵǴ? ????
public:
	nothing() {
		setType('n');
	}
};

class wall : public element { // ??

public:
	wall() {
		setType('w');
		setColor('B'); // ??��??
		setMove(false);
	}
};

class Box : public element { // ????
public:
	Box() {
		setType('b');
		setColor('b'); // ????
		setMove(true);
		setType('b');
	}
};

class emptySpace : public element { // ?? ????
public:
	emptySpace() {
		setType('e');
	}
};

class character { // ĳ????
	int r, c;

public:
	pair<int, int> getLocation() {
		pair<int,int> p = make_pair(r, c);
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
	int **target;
	char preMove;

public:
	map() {
		target = new int *[5];
		start(0);
	}

	int getCurrLevel() { return currlevel; }
	int getStep() { return step; }
	int getPush() { return push; }
	character getUser() { return user; }
	element(*getBoard())[11]{ return board; }

	void start(int level = 0) {
		currlevel = level;
		target[level] = new int[12];
		target[level][0] = 0; int n = 1;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				int temp = itemList.returnObj(level, i, j);
				if (temp == 0) board[i][j] = emptySpace();
				else if (temp == 1) board[i][j] = wall();
				else if (temp == 2) board[i][j] = Box();
				else if (temp == 3) {
					board[i][j] = emptySpace();
					target[level][0]++;
					target[level][n] = i;
					target[level][n + 1] = j;
					n += 2;
				}
				else board[i][j] = nothing();
			}
		}
		int* rc = itemList.returnCharacter(0);
		user.setLocation(rc[0], rc[1]);
	}

	bool move(char order) {
		pair<int, int> l;
		l = user.getLocation();
		if (order == 'u') {
			if (l.first == 0) return false;
			if (board[l.first - 1][l.second].getType() == 'e') {
				user.setLocation(l.first - 1, l.second);
				preMove = 'u';
			}
			else if (board[l.first - 1][l.second].getType() == 'b') {
				if (l.first == 1) return false;
				if (board[l.first - 2][l.second].getType() == 'e') {
					user.setLocation(l.first - 1, l.second);
					board[l.first - 2][l.second] = Box();
					board[l.first - 1][l.second] = emptySpace();
					preMove = 'u';
				}
			}
			else return false;
			return true;
		}
		else if (order == 'd') {
			if (l.first == 9) return false;
			if (board[l.first + 1][l.second].getType() == 'e') {
				user.setLocation(l.first + 1, l.second);
				preMove = 'd';
			}
			else if (board[l.first + 1][l.second].getType() == 'b') {
				if (l.first + 1 == 9) return false;
				if (board[l.first + 2][l.second].getType() == 'e') {
					user.setLocation(l.first + 1, l.second);
					board[l.first + 1][l.second] = emptySpace();
					board[l.first + 2][l.second] = Box();
					preMove = 'd';
				}
			}
			else return false;
			return true;
		}
		else if (order == 'l') {
			if (l.second == 0) return false;
			if (board[l.first][l.second - 1].getType() == 'e') {
				user.setLocation(l.first, l.second - 1);
				preMove = 'l';
			}
			else if (board[l.first][l.second - 1].getType() == 'b') {
				if (l.second == 1) return false;
				if (board[l.first][l.second - 2].getType() == 'e') {
					user.setLocation(l.first, l.second - 1);
					board[l.first][l.second - 2] = Box();
					board[l.first][l.second - 1] = emptySpace();
					preMove = 'l';
				}
			}
			else return false;
			return true;
		}
		else if (order == 'r') {
			if (l.second == 9) return false;
			if (board[l.first][l.second + 1].getType() == 'e') {
				user.setLocation(l.first, l.second + 1);
				preMove = 'r';
			}
			else if (board[l.first][l.second + 1].getType() == 'b') {
				if (l.second == 8) return false;
				if (board[l.first][l.second + 2].getType() == 'e') {
					user.setLocation(l.first, l.second + 1);
					board[l.first][l.second + 2] = Box();
					board[l.first][l.second + 1] = emptySpace();
					preMove = 'r';
				}
			}
			else return false;
			return true;
		}
		return false;
	}

	void reset() {
		for (int i = 0; i < 5; i++) {
			delete[] target[i];
		}
		start(currlevel);
	}

	bool revert() {
		pair<int, int> p = user.getLocation();
		if (preMove == 'u') {
			if (p.first == 0) {}
			else if (board[p.first - 1][p.second].getType() == 'b') {
				board[p.first][p.second] = Box();
				board[p.first - 1][p.second] = emptySpace();
				push--;
			}
			user.setLocation(p.first + 1, p.second);
			step--;
			return true;
		}
		else if (preMove == 'd') {
			if (p.first == 9) {} // ????
			else if (board[p.first + 1][p.second].getType() == 'b') {
				board[p.first][p.second] = Box();
				board[p.first - 1][p.second] = emptySpace();
				push--;
			}
			user.setLocation(p.first - 1, p.second);
			step--;
			return true;
		}
		else if (preMove == 'l') {
			if (p.second == 0) {}
			else if (board[p.first][p.second - 1].getType() == 'b') {
				board[p.first][p.second] = Box();
				board[p.first][p.second - 1] = emptySpace();
				push--;
			}
			user.setLocation(p.first, p.second + 1);
			step--;
			return true;
		}
		else if (preMove == 'r') {
			if (p.second == 9) {}
			else if (board[p.first][p.second + 1].getType() == 'b') {
				board[p.first][p.second] = Box();
				board[p.first][p.second + 1] = emptySpace();
				push--;
			}
			user.setLocation(p.first, p.second - 1);
			step--;
			return true;
		}
		return false;
	}

	bool check() { // ???????? Ȯ??
		int * temp = target[currlevel];
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

	void order(char order) { // move, revert
		if (order == 'R') Map.revert();
		else {
			if (Map.move(order)) { // ?̵?�� ?????ϰ? ?̵??ߴٸ?
				if (Map.check()) { // ???????? Ȯ??
					Map.start(Map.getCurrLevel() + 1); // ??�� ?ܰ??? ?̵?.
				}
				else {
					// ?ƴ϶??? ?? ??????Ʈ ?Ͽ? ????
				}
			}
		}
	}

	map getMap() {
		return Map;
	}

	pair<int, int> getL() { // ?׽?Ʈ??
		return Map.getUser().getLocation();
	}

	void print(char ord) { // ?׽?Ʈ??
		order(ord); // ????
		pair<int, int> l = getL();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (i == l.first && j == l.second) {
					cout << 'M'; continue;
				}
				cout << (getMap().getBoard()[i][j]).type;
			}
			cout << endl;
		}
	}
};

enum palette {DEFAULT, CHARACTER, BOX, WALL, EMPTY, NOTHING, TARGET};

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
		win_sub = newwin(10,10, 3, 17);
		wborder(win_sub, '@', '@', '@', '@', '@', '@', '@', '@');

		// Text
		mvprintw(1, 3, "Push Box Game!");
		mvprintw(16, 3, "U    Q - quit");
		mvprintw(17, 2, "LDR   R - reset(?)");
		mvprintw(18, 2, "move");
		mvwprintw(win_game, 1, 1, "win_game");
		mvwprintw(win_sub, 1, 1, "win_sub\n Score~~~");
		refresh();
		wrefresh(win_game);
		wrefresh(win_sub);
	}

	void update_scr() {
		element (*board)[11] = game->getMap().getBoard();
		for (int i=0;i<10;++i) {
			for (int j=0;j<10;++j) {
				char type = board[i][j].getType();
				// if문 최적화예정
				if (type == 'b') wattron(win_game, COLOR_PAIR(BOX));
				else if (type == 'w') wattron(win_game, COLOR_PAIR(WALL));
				else if (type == 'e') wattron(win_game, COLOR_PAIR(EMPTY));
				else if (type == 'n') wattron(win_game, COLOR_PAIR(NOTHING));
				else wattron(win_game, COLOR_PAIR(DEFAULT));
				mvwprintw(win_game, i+1, j+1, "%c", type);
			}
		}
		pair<int,int> player = game->getL();
		wattron(win_game, COLOR_PAIR(CHARACTER));
		mvwprintw(win_game, player.first+1, player.second+1, "C");
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