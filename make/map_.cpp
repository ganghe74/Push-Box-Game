#include "map.h"

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
		for (int i = 1; i < 2 * n + 1; i += 2) {
			ptr[i] = target[i];
			ptr[i + 1] = target[i + 1];
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
		int* rc = itemList.returnCharacter(currlevel);
		user.setLocation(rc[0], rc[1]);
		step = 0;
		push = 0;
	}

	void swap(element &e1, element &e2) {
		element temp = e1;
		e1 = e2;
		e2 = temp;
	}

	bool move(char order) {
		int l[2];
		user.getLocation(l);
		int r = l[0], c = l[1];
		if (order == 'w' && r != 0) {
			if (board[r - 1][c].getType() == 'e') preBoxMove = false;
			else if (board[r - 1][c].getType() == 'b' && r != 1) {
				if (board[r - 2][c].getType() == 'e') {
					swap(board[r - 2][c], board[r - 1][c]);
					preBoxMove = true;
					push++;
				}
				else return false;
			}
			else return false;
			user.setLocation(r - 1, c);
		}
		else if (order == 's' && r != 9) {
			if (board[r + 1][c].getType() == 'e') preBoxMove = false;
			else if (board[r + 1][c].getType() == 'b' && r != 8) {
				if (board[r + 2][c].getType() == 'e') {
					swap(board[r + 1][c], board[r + 2][c]);
					preBoxMove = true;
					push++;
				}
				else return false;
			}
			else return false;
			user.setLocation(r + 1, c);
		}
		else if (order == 'a' && c != 0) {
			if (board[r][c - 1].getType() == 'e') preBoxMove = false;
			else if (board[r][c - 1].getType() == 'b' && c != 1) {
				if (board[r][c - 2].getType() == 'e') {
					swap(board[r][c - 2], board[r][c - 1]);
					preBoxMove = true;
					push++;
				}
				else return false;
			}
			else return false;
			user.setLocation(r, c - 1);
		}
		else if (order == 'd' && c != 9) {
			if (board[r][c + 1].getType() == 'e') preBoxMove = false;
			else if (board[r][c + 1].getType() == 'b' && c != 8) {
				if (board[r][c + 2].getType() == 'e') {
					swap(board[r][c + 2], board[r][c + 1]);
					preBoxMove = true;
					push++;
				}
				else return false;
			}
			else return false;
			user.setLocation(r, c + 1);
		}
		else return false;
		preMove = order;
		step++;
		return true;
	}

	void reset() {
		start(currlevel);
	}

	bool revert() {
		int l[2];
		user.getLocation(l);
		int r = l[0], c = l[1];
		if (preMove == 'w') {
			if (preBoxMove && r != 0) {
				board[r][c] = Box();
				board[r - 1][c] = emptySpace();
				push--;
			}
			user.setLocation(r + 1, c);
		}
		else if (preMove == 's') {
			if (preBoxMove && r != 9) {
				board[r][c] = Box();
				board[r + 1][c] = emptySpace();
				push--;
			}
			user.setLocation(r - 1, c);
		}
		else if (preMove == 'a') {
			if (preBoxMove && c != 0) {
				board[r][c] = Box();
				board[r][c - 1] = emptySpace();
				push--;
			}
			user.setLocation(r, c + 1);
		}
		else if (preMove == 'd') {
			if (preBoxMove && c != 9) {
				board[r][c] = Box();
				board[r][c + 1] = emptySpace();
				push--;
			}
			user.setLocation(r, c - 1);
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
					if (Map.getCurrLevel() == 4) Map.start(0);
					Map.start(Map.getCurrLevel() + 1);
				}
			}
		}
	}

	map getMap() {
		return Map;
	}

	void getL(int l[]) {
		Map.getUser().getLocation(l);
	}
};