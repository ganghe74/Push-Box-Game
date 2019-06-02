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

class nothing : public element { // �ƹ��͵� ��� �ȵǴ� ����
public:
	nothing() {
		setType('n');
	}
};

class wall : public element { // ��

public:
	wall() {
		setType('w');
		setColor('B'); // ������
		setMove(false);
	}
};

class box : public element { // ����
public:
	box() {
		setType('b');
		setColor('b'); // ����
		setMove(true);
		setType('b');
	}
};

class emptySpace : public element { // �� ����
public:
	emptySpace() {
		setType('e');
	}
};

class character { // ĳ����
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