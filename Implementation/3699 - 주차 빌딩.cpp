#include<iostream>
using namespace std;

// 엘리베이터: 한 층에 10초
// 컨베이어 벨트: 한 대 거리에 5초
int T;
int h, l;

int parkingBuilding[50][50];
int tempFloor[50];

int solution() {
	int curNum = 1;
	int answer = 0;

	while (true) {
		bool isFound = false;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < l; j++) {
				if (curNum == parkingBuilding[i][j]) {
					answer += i * 2 * 10;
					isFound = true;
					if (j <= l / 2) {
						answer += j * 5;
						for (int k = 0; k < l; k++)
							tempFloor[(k - j >= 0) ? k - j : k - j + l] = parkingBuilding[i][k];
					}
					else {
						answer += (l - j) * 5;
						for (int k = 0; k < l; k++)
							tempFloor[(k + (l - j)) % l] = parkingBuilding[i][k];
					}
					
					for (int k = 1; k < l; k++) {
						parkingBuilding[i][k] = tempFloor[k];
					}
					break;
				}
		
			}
			if (isFound == true) break;
		}

		if (isFound == false) break;
		curNum++;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> h >> l;

		for (int j = 0; j < h; j++)
			for (int k = 0; k < l; k++)
				cin >> parkingBuilding[j][k];
		
		cout << solution() << '\n';
	}

}