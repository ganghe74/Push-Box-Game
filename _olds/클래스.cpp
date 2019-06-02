#include <iostream>
#include "itemList.cpp"
using namespace std;

class element {
public :
	char color;
	char shape;
	bool move;
	char type;

	char getColor() {
		return color;
	}
	char getShape() {
		return shape;
	}
	bool getMove() {
		return move;
	}
	char getType() {
		return type;
	}
	void setColor(char c) {
		color = c;
	}
	void setShape(char s) {
		shape = s;
	}
	void setMove(bool m) {
		move = m;
	}
	void setType(char t) {
		type = t;
	}
};

class nothing : public element { // �ƹ��͵� ��� �ȵǴ� ����
public :
	nothing() {
		type = 'n';
	}
};

class wall : public element { // ��
	
public :
	wall() {
		setType('w');
		setColor('B'); // ������
		setShape('��');
		setMove(false);
	}
};

class box : public element { // ����
public :
	box() {
		setType('b');
		setColor('b'); // ����
		setShape('��');
		setMove(true);
	}
};

class emptySpace : public element { // �� ����
public :
	emptySpace() {
		setType('e');
	}
};

/* ������� element */

class character { // ĳ����
	int r, c;
	
public :
	pair<int,int> getLocation() {
		auto pair = make_pair(r, c);
		return pair;
	}
	void setLocation(int row, int col) {
		r = row;
		c = col;
	}
};

class map {
	items itemList; // ������
	character user; // ĳ����
	element board[11][11]; // ������
	int step, push, currlevel;
	int ** target; // �ڽ��� ���ƾ� �� ��ġ
	char preMove;
	/* ���� ���� ������ ����*/

public :
	map() {
		target = new int * [5];
		start(0);
	}

	void start(int level = 0) {   // �ϳ��� ���� ����.
		currlevel = level;
		char (*temp)[11] = itemList.returnBoard(level); // �� �ʱ�ȭ ����
		target[level - 1] = new int[12]; /* �ڽ��� ���� �ڸ� ���� */
		target[level - 1][0] = 0; int n = 1;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (temp[i][j] == 0) board[i][j] = emptySpace();
				else if (temp[i][j] == 1) board[i][j] = wall();
				else if (temp[i][j] == 2) board[i][j] = box();
				else if (temp[i][j] == 3) {
					board[i][j] = emptySpace();
					target[level - 1][0]++;
					target[level - 1][n] = i;
					target[level - 1][n + 1] = j;
				}
				else board[i][j] = nothing();
			}
		}
		int* rc = itemList.returnCharacter(0); // ĳ���� ��ġ
		user.setLocation(rc[0], rc[1]);
	}

	bool move(char order) {
		pair<int, int> l;
		l = user.getLocation(); // ��ġ
		if (order == 'u') { // ����
			if (l.first == 0) return false; // ���
			if (board[l.first-1][l.second].getType() == 'e') {
				user.setLocation(l.first - 1, l.second);
				preMove = 'u';
			}
			else if (board[l.first - 1][l.second].getType() == 'b') {
				if (l.first == 1) return false; // ���
				if (board[l.first - 2][l.second].getType() == 'e') {
					user.setLocation(l.first - 1, l.second);
					board[l.first - 2][l.second] = box();
					board[l.first - 1][l.second] = emptySpace();
					preMove = 'u';
				}
			}
			else return false;
			return true;
		}
		else if (order == 'd') { // �Ʒ�
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
					board[l.first + 2][l.second] = box();
					preMove = 'd';
				}
			}
			else return false;
			return true;
		}
		else if (order == 'l') { // ����
			if (l.second == 0) return false;
			if (board[l.first][l.second - 1].getType() == 'e') {
				user.setLocation(l.first, l.second - 1);
				preMove = 'l';
			}
			else if (board[l.first][l.second - 1].getType() == 'b') {
				if (l.second == 1) return false;
				if (board[l.first][l.second - 2].getType() == 'e') {
					user.setLocation(l.first, l.second - 1);
					board[l.first][l.second - 2] = box();
					board[l.first][l.second - 1] = emptySpace();
					preMove = 'l';
				}
			}
			else return false;
			return true;
		}
		else if (order == 'r') { // ����
			if (l.second == 9) return false;
			if (board[l.first][l.second + 1].getType() == 'e') {
				user.setLocation(l.first, l.second + 1);
				preMove = 'r';
			}
			else if (board[l.first][l.second + 1].getType() == 'b') {
				if (l.second == 8) return false;
				if (board[l.first][l.second + 2].getType() == 'e') {
					user.setLocation(l.first, l.second + 1);
					board[l.first][l.second + 2] = box();
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

	bool revert() { // �ѹ� �ǵ�����
		pair<int, int> p = user.getLocation();
		if (preMove == 'u') {
			if (p.first == 0) {} // ����
			else if (board[p.first - 1][p.second].getType() == 'b') {
				board[p.first][p.second] = box();
				board[p.first - 1][p.second] = emptySpace();
				push--;
			}
			user.setLocation(p.first + 1, p.second);
			step--;
			return true;
		}
		else if (preMove == 'd') {
			if (p.first == 9) {} // ����
			else if (board[p.first + 1][p.second].getType() == 'b') {
				board[p.first][p.second] = box();
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
				board[p.first][p.second] = box();
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
				board[p.first][p.second] = box();
				board[p.first][p.second + 1] = emptySpace();
				push--;
			}
			user.setLocation(p.first, p.second - 1);
			step--;
			return true;
		}
		return false;
	}

	bool check(int level) { // �������� Ȯ��
		int * temp = target[level];
		int n = temp[0];
		for (int i = 1; i < n*2+1; i += 2) {
			if (board[temp[i]][temp[i + 1]].getType() != 'b') return false;
		}
		return true;
	}

};


class pushBox {
private :
	map Map;

public :
	pushBox() {
		Map = map(); /* ����� �ϳ�? */
		Map.start();
	}
	
	/* ������ �޼��� */
};