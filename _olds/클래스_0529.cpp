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
		{1, 4, 4, 4, 0, 0, 1, 1, 1, 4},
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
public:
	char type;

	char getType() const { return type; }
	void setType(char t) { type = t; }
};

class nothing : public element {
public:
	nothing() {
		setType('n');
	}
};

class wall : public element {

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

/*
class element {
public:
	virtual char getType() = 0;
};

class nothing : public element {
public:
	char getType() { return 'n'; }
};

class wall : public element {
public:
	char getType() { return 'w'; }
};

class Box : public element {
public:
	char getType() { return 'b'; }
};

class emptySpace : public element {
public:
	char getType() { return 'e'; }
};
*/

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
	int ** target;
	char preMove;

public:
	map() {
		target = new int *[5];
		for (int i = 0; i < 5; i++) target[i] = new int[12];
		start(0);
	}

	int getCurrLevel() const { return currlevel; }
	int getStep() const { return step; }
	int getPush() const { return push; }
	character getUser() { return user; }
	element(*getBoard())[11]{ return board; }

		void start(int level = 0) {
		currlevel = level;
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
		step = 0;
		push = 0;
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
					push++;
				}
			}
			else return false;
			step++;
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
					push++;
				}
			}
			else return false;
			step++;
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
					push++;
				}
			}
			else return false;
			step++;
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
		if (preMove == 'u') {
			if (p.first == 0) {}
			else if (board[p.first - 1][p.second].getType() == 'b') {
				board[p.first][p.second] = Box();
				board[p.first - 1][p.second] = emptySpace();
				push--;
			}
			user.setLocation(p.first + 1, p.second);
			step--;
			preMove = NULL;
			return true;
		}
		else if (preMove == 'd') {
			if (p.first == 9) {}
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

	bool check() {
		int * temp = target[currlevel];
		int n = temp[0];
		for (int i = 1; i < n * 2 + 1; i += 2) {
			if (board[temp[i]][temp[i + 1]].getType() != 'b') return false;
		}
		return true;
	}

	~map() {
		for (int i = 0; i < 5; i++) {
			delete[] target[i];
		}
		delete[] target;
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
		if (order == 'R') Map.revert();
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

int main() {
	pushBox p = pushBox();

	initscr();
	curs_set(0); // 커서 사라짐
	noecho(); // 문자 출력금지

	start_color();
	init_pair(1, COLOR_BLUE, COLOR_YELLOW);
	init_pair(2, COLOR_WHITE, COLOR_WHITE);

	char x;
	while (true) {
		clear();
		attron(COLOR_PAIR(1));
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				addch(p.getMap().getBoard()[i][j].getType());
			}
			addch('\n');
		}
		attroff(COLOR_PAIR(1));
		attron(COLOR_PAIR(2));
		mvprintw(p.getL().first, p.getL().second, "C");
		attroff(COLOR_PAIR(2));
		refresh();
		x = getchar();
		if (x == 'f') break;
		p.order(x);
	}

	endwin();

	cout << "Game Over\n";
}