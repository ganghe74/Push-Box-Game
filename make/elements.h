#pragma once
#ifndef ELEMENTS_H
#define ELEMENTS_H

class items {
public :
	int boardList[5][10][10];
	int characterList[11][2];
	int returnObj(int level, int i, int j) const;
	int* returnCharacter(int level);
};

class element {
public:
	char type;
	char getType() const;
	void setType(char t);
};

class nothing : public element {
public:
	nothing();
};

class wall : public element {
public:
	wall();
};

class Box : public element {
public:
	Box();
};

class emptySpace : public element {
public:
	emptySpace();
};

class character {
	int r, c;

public:
	void getLocation(int l[]);
	void setLocation(int row, int col);
};

#endif