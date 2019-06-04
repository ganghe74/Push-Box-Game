#ifndef MAP_H
#define MAP_H
#include "elements.h"
#include <iostream>

class map {
	character user;
	element board[11][11];
	items itemList;
	int step, push, currlevel;
	int target[13];
	char preMove;
	bool preBoxMove;

public:
	map();

	int getCurrLevel() const;
	int getStep() const;
	int getPush() const;
	character getUser();
	element(*getBoard())[11];
	void getTarget(int *ptr);

	void start(int level = 0);
	void swap(element &e1, element &e2);
	bool move(char order);
	void reset();
	bool revert();
	bool check();
};

#endif
