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
			if (Map.move(order)) { // �̵��� ����ϰ� �̵��ߴٸ�
				if (Map.check()) { // �������� Ȯ��
					Map.start(Map.getCurrLevel() + 1); // ���� �ܰ�� �̵�.
				}
				else {
					// �ƴ϶�� �� ������Ʈ �Ͽ� ���
				}
			}
		}
	}

	map getMap() {
		return Map;
	}

	pair<int, int> getL() { // �׽�Ʈ��
		return Map.getUser().getLocation();
	}

	void print(char or) {
		order(or); // ����
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