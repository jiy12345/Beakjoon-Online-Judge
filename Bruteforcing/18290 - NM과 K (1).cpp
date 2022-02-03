#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int M, N, K;
int grid[10][10];
bool isPicked[100];

int solution(int index, int curSize, int curSum, bool* isPicked) {
	int maxNum = -10000 * M * N;

	if (curSize == K) {
		return curSum;
	}

	for (int i = index; i < M * N; i++) {
		int adjacentIndexDown = i + M;
		int adjacentIndexRight = i + 1;

		// 인접한 칸이 선택되지 않았을 경우에만 다음 단계 진행
		if (isPicked[i] == false) {
			bool isPickedTemp[100];

			memcpy(isPickedTemp, isPicked, sizeof(bool) * M * N);

			// 인덱스가 범위를 벗어나지 않을 때만 표시
			if (adjacentIndexDown < N * M) {
				isPickedTemp[adjacentIndexDown] = true;
			}

			// 현 위치가 가장 오른쪽 열일 경우를 제외하고 인접한 위치 표시
			if (adjacentIndexRight % M != 0) {
				isPickedTemp[adjacentIndexRight] = true;
			}

			maxNum = max(maxNum, solution(i + 1, curSize + 1, curSum + grid[i / M][i % M], isPickedTemp));
		}
	}

	return maxNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}

	cout << solution(0, 0, 0, isPicked);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}

	cout << solution(0, 0, 0, isPicked);
}
