#pragma once
#ifndef PUSHBOX_H
#define PUSHBOX_H
#include "map.h"

class pushBox {
private:
	map Map;

public:
	pushBox();

	void order(char order);
	map getMap();
	void getL(int l[]);
};

#endif