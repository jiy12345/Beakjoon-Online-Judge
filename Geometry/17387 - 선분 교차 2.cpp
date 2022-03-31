#include<iostream>
using namespace std;

long long x1, y_1, x2, y2, x3, y3, x4, y4;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long result = x1*y2+x2*y3+x3*y1;
	result = result - y1 * x2 - y2 * x3 - y3 * x1;
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

int solution(){

	int result1 = ccw(x1, y_1, x2, y2, x3, y3);
	int result2 = ccw(x1, y_1, x2, y2, x4, y4);
	int result3 = ccw(x3, y3, x4, y4, x1, y_1);
	int result4 = ccw(x3, y3, x4, y4, x2, y2);
	
	if (result1 * result2 == 0 && result3 * result4 == 0) {
		if (min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2) &&
			min(y_1, y2) <= max(y3, y4) && min(y3, y4) <= max(y_1, y2)) return 1;
		else return 0;
	}
	// 한 선분에서 다른 선분의 양 끝점까지의 방향이 서로 달라야!
	else if (result1 * result2 <= 0 && result3 * result4 <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	cin >> x1 >> y_1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	cout << solution();
}
