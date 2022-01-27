#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
N: 종이의 세로 길이
M: 종이의 가로 길이

- 변수 제한 사항
N, M: 4~500
종이에 적힌 수: 1~1,000

- 문제 상황
 종이의 크기가 주어지고, 그 종이에 쓰여있는 수가 주어질 때, 
 테트로미노를 배치하여 덮은 칸의 수들의 합의 최대값을 구하여라 

 총 다섯가지의 테트로미노는 대칭, 회전이 가능하다.

2. 풀이 계획

1. 긴 모양: 세로 가로 2개
2. ㄴ자 모양: 회전한 것 4개 + 대칭하여 회전한 것 4개
3. 번개모양: 회전한 것 2개 + 대칭하여 회전한 것 2개
4. ㅗ 모양: 4개
5. 정사각모양: 1개


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int N, M;

int paper[500][500];

bool isInRange(int i, int j) {
	if (0 <= i && i <= N - 1 && 0 <= j && j <= M - 1) return true;
	else return false;
}

int checkIMino(int i, int j) {
	int maxNum = 0;
	// ㅁ
	// ㅁ
	// ㅁ
	// ㅁ
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 2, j) && isInRange(i + 3, j)) 
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j]);
	// ㅁㅁㅁㅁ
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i, j + 2) && isInRange(i, j + 3)) 
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3]);
	
	return maxNum;
}


int checkOMino(int i, int j) {
	int maxNum = 0;

	// ㅁㅁ
	// ㅁㅁ
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i, j + 1) && isInRange(i + 1, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1]);

	return maxNum;
}

int checkZMino(int i, int j) {
	int maxNum = 0;

	// ㅁㅁ
	//   ㅁㅁ
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 1, j + 2)) 
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j + 2]);
	//   ㅁ
	// ㅁㅁ
	// ㅁ
	if (isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 1, j) && isInRange(i + 2, j))
		maxNum = max(maxNum, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j] + paper[i + 2][j]);

	return maxNum;
}

int checkSMino(int i, int j) {
	int maxNum = 0;

	//   ㅁㅁ
	// ㅁㅁ
	if (isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i, j + 1) && isInRange(i, j + 2))
		maxNum = max(maxNum, paper[i + 1][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i][j + 2]);
	// ㅁ
	// ㅁㅁ
	//   ㅁ
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i + 2, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1]);

	return maxNum;
}
int checkJMino(int i, int j) {
	int maxNum = 0;

	//   ㅁ
	//   ㅁ
	// ㅁㅁ
	if (isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 2, j + 1) && isInRange(i + 2, j)) 
		maxNum = max(maxNum, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1] + paper[i + 2][j]);
	// ㅁ
	// ㅁㅁㅁ
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i + 1, j + 2))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2]);
	// ㅁㅁ
	// ㅁ
	// ㅁ
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i + 1, j) && isInRange(i + 2, j))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 2][j]);
	// ㅁㅁㅁ
	//     ㅁ
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i, j + 2) && isInRange(i + 1, j + 2))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 2]);

	return maxNum;
}

int checkLMino(int i, int j) {
	int maxNum = 0;

	// ㅁ
	// ㅁ
	// ㅁㅁ
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 2, j) && isInRange(i + 2, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j + 1]);
	// ㅁㅁㅁ
	// ㅁ
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i, j + 2) && isInRange(i + 1, j))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j]);
	// ㅁㅁ
	//   ㅁ
	//   ㅁ
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 2, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1]);
	//     ㅁ
	// ㅁㅁㅁ
	if (isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i + 1, j + 2) && isInRange(i, j + 2))
		maxNum = max(maxNum, paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2] + paper[i][j + 2]);

	return maxNum;
}

int checkTMino(int i, int j) {
	int maxNum = 0;

	// ㅁㅁㅁ
	//   ㅁ
	if (isInRange(i, j) && isInRange(i, j + 1) && isInRange(i, j + 2) && isInRange(i + 1, j + 1))
		maxNum = max(maxNum, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 1]);
	//   ㅁ
	// ㅁㅁ
	//   ㅁ
	if (isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 2, j + 1) && isInRange(i + 1, j))
		maxNum = max(maxNum, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1] + paper[i + 1][j]);
	//   ㅁ
	// ㅁㅁㅁ
	if (isInRange(i, j + 1) && isInRange(i + 1, j + 1) && isInRange(i + 1, j) && isInRange(i + 1, j + 2))
		maxNum = max(maxNum, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j] + paper[i + 1][j + 2]);
	// ㅁ
	// ㅁㅁ
	// ㅁ
	if (isInRange(i, j) && isInRange(i + 1, j) && isInRange(i + 1, j + 1) && isInRange(i + 2, j))
		maxNum = max(maxNum, paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j]);

	return maxNum;
}

int solution() {
	int maxNum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			maxNum = max(maxNum, checkIMino(i, j));
			maxNum = max(maxNum, checkOMino(i, j));
			maxNum = max(maxNum, checkZMino(i, j));
			maxNum = max(maxNum, checkSMino(i, j));
			maxNum = max(maxNum, checkJMino(i, j));
			maxNum = max(maxNum, checkLMino(i, j));
			maxNum = max(maxNum, checkTMino(i, j));
		}
	}
	
	return maxNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
		}
	}

	cout << solution();
}