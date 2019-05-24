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

class nothing : public element { // 아무것도 출력 안되는 구간
public :
	nothing() {
		type = 'n';
	}
};

class wall : public element { // 벽
	
public :
	wall() {
		setType('w');
		setColor('B'); // 검은색
		setShape('ㅁ');
		setMove(false);
	}
};

class box : public element { // 상자
public :
	box() {
		setType('b');
		setColor('b'); // 갈색
		setShape('ㅁ');
		setMove(true);
	}
};

class emptySpace : public element { // 빈 공간
public :
	emptySpace() {
		setType('e');
	}
};

/* 여기까지 element */

class character { // 캐릭터
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
	items itemList; // 데이터
	character user; // 캐릭터
	element board[11][11]; // 보드판
	int step, push, currlevel;
	int ** target; // 박스를 놓아야 할 위치
	char preMove;
	/* 이전 상태 저장할 변수*/

public :
	map() {
		target = new int * [5];
		start(0);
	}

	void start(int level = 0) {   // 하나의 맵을 만듬.
		currlevel = level;
		char (*temp)[11] = itemList.returnBoard(level); // 맵 초기화 과정
		target[level - 1] = new int[12]; /* 박스를 놓을 자리 생성 */
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
		int* rc = itemList.returnCharacter(0); // 캐릭터 위치
		user.setLocation(rc[0], rc[1]);
	}

	bool move(char order) {
		pair<int, int> l;
		l = user.getLocation(); // 위치
		if (order == 'u') { // 위로
			if (l.first == 0) return false; // 벗어남
			if (board[l.first-1][l.second].getType() == 'e') {
				user.setLocation(l.first - 1, l.second);
				preMove = 'u';
			}
			else if (board[l.first - 1][l.second].getType() == 'b') {
				if (l.first == 1) return false; // 벗어남
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
		else if (order == 'd') { // 아래
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
		else if (order == 'l') { // 왼쪽
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
		else if (order == 'r') { // 왼쪽
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

	bool revert() { // 한번 되돌리기
		pair<int, int> p = user.getLocation();
		if (preMove == 'u') {
			if (p.first == 0) {} // 예외
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
			if (p.first == 9) {} // 예외
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

	bool check(int level) { // 끝났는지 확인
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
		Map = map(); /* 해줘야 하나? */
		Map.start();
	}
	
	/* 나머지 메서드 */
};