#include "elements.h"


int items::returnObj(int level, int i, int j) const {
	return boardList[level][i][j];
};

int* items::returnCharacter(int level) {
	if (level >= 5) return NULL;
	return characterList[level];
};

char element::getType() const { return type; }
void element::setType(char t) { type = t; }

nothing::nothing() {
	setType('n');
}

wall::wall() {
	setType('w');
}

Box::Box() {
	setType('b');
}

emptySpace::emptySpace() {
	setType('e');
}

void character::getLocation(int l[]) {
	l[0] = r;
	l[1] = c;
}
void character::setLocation(int row, int col) {
	r = row;
	c = col;
}
