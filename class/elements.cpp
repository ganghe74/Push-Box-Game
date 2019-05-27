#include <iostream>
using namespace std;

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