#include <iostream>
#include <vector>
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

	int returnObj(int level, int i, int j) {
		return boardList[level][i][j];
	}

	int* returnCharacter(int level) {
		if (level >= 5) return NULL;
		return characterList[level];
	};

	int(*returnTarget(int level))[2]{
		return target[level];
	}
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

class nothing : public element { // 아무것도 출력 안되는 구간
public:
	nothing() {
		setType('n');
	}
};

class wall : public element { // 벽

public:
	wall() {
		setType('w');
		setColor('B'); // 검은색
		setMove(false);
	}
};

class box : public element { // 상자
public:
	box() {
		setType('b');
		setColor('b'); // 갈색
		setMove(true);
		setType('b');
	}
};

class emptySpace : public element { // 빈 공간
public:
	emptySpace() {
		setType('e');
	}
};

class character { // 캐릭터
	int r, c;

public:
	pair<int, int> getLocation() {
		auto pair = make_pair(r, c);
		return pair;
	}
	void setLocation(int row, int col) {
		r = row;
		c = col;
	}
};

class map {
	character user; // 캐릭터
	element board[11][11]; // 보드판
	items itemList;
	int step, push, currlevel;
	int ** target; // 박스를 놓아야 할 위치
	char preMove;
	/* 이전 상태 저장할 변수*/

public:
	map() {
		target = new int *[5];
		start(0);
	}

	int getCurrLevel() { return currlevel; }
	int getStep() { return step; }
	int getPush() { return push; }
	character getUser() { return user; }
	element(*getBoard())[11]{ return board; } // 보드판 리턴

		void start(int level = 0) {   // 하나의 맵을 만듬.
		currlevel = level;
		target[level] = new int[12]; /* 박스를 놓을 자리 생성 */
		target[level][0] = 0; int n = 1;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				int temp = itemList.returnObj(level, i, j);
				if (temp == 0) board[i][j] = emptySpace();
				else if (temp == 1) board[i][j] = wall();
				else if (temp == 2) board[i][j] = box();
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
		int* rc = itemList.returnCharacter(0); // 캐릭터 위치
		user.setLocation(rc[0], rc[1]);
	}

	bool move(char order) {
		pair<int, int> l;
		l = user.getLocation(); // 위치
		if (order == 'u') { // 위로
			if (l.first == 0) return false; // 벗어남
			if (board[l.first - 1][l.second].getType() == 'e') {
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

	bool check() { // 끝났는지 확인
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
			if (Map.move(order)) { // 이동을 명령하고 이동했다면
				if (Map.check()) { // 끝났는지 확인
					Map.start(Map.getCurrLevel() + 1); // 다음 단계로 이동.
				}
				else {
					// 아니라면 맵 업데이트 하여 출력
				}
			}
		}
	}

	map getMap() {
		return Map;
	}

	pair<int, int> getL() { // 테스트용
		return Map.getUser().getLocation();
	}

	void print(char ord) { // 테스트용
		order(ord); // 실행
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


int main() {
	pushBox p = pushBox();
	char order;
	while (true) {
		cin >> order;
		if (order == 'f') break;

		p.print(order);

		cout << '\n' << '\n' << '\n' << '\n';
	}
}