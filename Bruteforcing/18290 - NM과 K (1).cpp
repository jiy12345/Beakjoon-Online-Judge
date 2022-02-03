#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

/*
1. 문제 분석
- 변수
N, M: 격자판의 크기
K: 선택할 수의 개수

- 변수 제한 사항
N, M: 1~10
K: 1~min(4, NxM)
격자판에 들어있는 수: -10,000~10,000

항상 K개의 칸을 선택할 수 있는 입력만 주어진다.

- 문제 상황
 NxM 격자에 쓰여진 수들 중 K개의 수를 선택하여 더한 값의 최대값을 출력한다.


2. 풀이 계획

1. 조합을 통해 K개의 위치를 추출하는 과정을 선택하되, 인접한 칸은 선택하지 않도록 방문 표시를 진행한다.
2. K개의 위치를 모두 추출하였을 경우, 그 합을 구하여 현재까지의 최대값과 비교한 후 더 큰 값을 저장한다.


3. 계획 검증
 덧셈은 교환법칙이 성립하므로, 합을 구하는데는 뽑히는 데 순서가 상관없다. => 따라서 조합알고리즘을 사용하여 K개의 수를 도출하여도 모든 경우의 수를 고려할 수 있다.


 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

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