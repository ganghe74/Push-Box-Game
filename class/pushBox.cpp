#include <iostream>
#include "map_.cpp"
using namespace std;

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

	void print(char or) {
		order(or); // 실행
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