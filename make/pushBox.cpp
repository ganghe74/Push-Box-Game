#include "pushBox.h"

class pushBox {
private:
	map Map;

public:
	pushBox() {
		Map = map();
		Map.start();
	}

	void order(char order) {
		if (order == 'b') Map.revert();
		else if (order == 'r') Map.reset();
		else {
			if (Map.move(order)) {
				if (Map.check()) {
					if (Map.getCurrLevel() == 4) Map.start(0);
					Map.start(Map.getCurrLevel() + 1);
				}
			}
		}
	}

	map getMap() {
		return Map;
	}

	void getL(int l[]) {
		Map.getUser().getLocation(l);
	}
};