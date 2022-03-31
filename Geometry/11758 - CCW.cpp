#include<iostream>
#include<cstring>
using namespace std;

int x1, y_1, x2, y2, x3, y3;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int result = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;
	if (result > 0) {
		return 1;
	}
	else if (result < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

int main() {
	cin >> x1 >> y_1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	cout << ccw(x1, y_1, x2, y2, x3, y3);
}
