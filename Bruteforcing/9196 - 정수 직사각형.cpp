#include<iostream>
using namespace std;

#define MAX_NUM 150
int h, w;

struct Rect {
	int h;
	int w;
	int diagonal;

	Rect(int h, int w, int diagonal) {
		this->h = h;
		this->w = w;
		this->diagonal = diagonal;
	}
};

void solution() {
	int numCriteria = h * h + w * w;
	
	Rect curMinRect(100, 100, 100 * 100 + 100 * 100);
	for (int cur_h = 1; cur_h <= MAX_NUM; cur_h++) {
		for (int cur_w = cur_h + 1; cur_w <= MAX_NUM; cur_w++) {
			int curDiagonal = cur_h * cur_h + cur_w * cur_w;
			if (numCriteria > curDiagonal ||
				(numCriteria == curDiagonal &&
					h >= cur_h)) {
				continue;
			}

			if (curDiagonal < curMinRect.diagonal ||
				(curDiagonal == curMinRect.diagonal &&
					cur_h < curMinRect.h)
				) {
				curMinRect.h = cur_h;
				curMinRect.w = cur_w;
				curMinRect.diagonal = curDiagonal;
			}
			break;
		}
		if (cur_h * cur_h >= numCriteria) break;
	}

	cout << curMinRect.h << " " << curMinRect.w << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> h >> w;
		if (h == 0 && w == 0) break;

		solution();
	}

	return 0;
}