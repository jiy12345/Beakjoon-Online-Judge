#include<iostream>
using namespace std;

int N;
int W[10][10];  // 입력받은 각 경로별 비용
bool isVisited[10]; // 방문한 곳인지 체크

int permutation(int curCity, int curCost, int curSize) {
	int minNum = 10 * 1000000;
	if (curSize == N) { // 출발점을 제외하고 한번씩 방문한 경우
		
		// 원래 도시로 돌아가는 경로가 있을 경우에만 고려되도록 함
		if (W[curCity][0]) {
			minNum = curCost + W[curCity][0];
		}
		return minNum;
	}

	for (int i = 0; i < N; i++) {
		// 방문하지 않았고 경로가 있는 경우에만 탐색 진행
		if (isVisited[i] == false && W[curCity][i] != 0) {
			isVisited[i] = true;
			minNum = min(minNum, permutation(i, curCost+ W[curCity][i], curSize + 1));
			isVisited[i] = false;
		}
	}

	return minNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	// 순회 경로이므로, 출발점은 한 곳으로 고정하여도 모든 경우를 고려할 수 있음!
	isVisited[0] = true;
	cout << permutation(0, 0, 1);
}
