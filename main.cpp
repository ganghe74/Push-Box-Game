#include <iostream>
#include "pushBox.h"
#include "UI.h"
using namespace std;

int main() {
	pushBox p = pushBox();

	UI ui;
	ui.start(&p);

	return 0;
}
