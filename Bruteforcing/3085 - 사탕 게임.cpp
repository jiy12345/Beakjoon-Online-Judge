#include<iostream>
#include<string>
using namespace std;

/*
1. 문제 분석
- 변수
N: 보드의 가로/세로 길이

 - 사탕의 색상
  C: 빨간색
  P: 파란색
  Z: 초록색
  Y: 노란색
- 변수 제한 사항
N: 3~50


- 문제 상황

다음과 같은 규칙에 따라 사탕을 먹는다고 할 때,

 사탕의 색이 서로다른 인접한 두 칸을 고른 뒤, 고른 칸에 들어있는 사탕을 서로 교환한 후
 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분을 고른 다음 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어지면 먹을 수 잇는 사탕의 최대 개수를 출력한다.

2. 풀이 계획
 바꾸지 않은 상태에서 최대값이 나올 수 있으므로, 일단 바꾸지 않은 상태에서의 최대값을 먼저 계산한다.

 그 후에는 모든 위치에 대해서 검사를 진행하며, 오른쪽과 아래쪽으로의 비교를 진행하여 다를경우에만 다음을 반복한다.

 1. 두 위치의 사탕을 서로 교환한다.
 2. 변경이 생길 수 있는 열 혹은 행을 모두 검사한다.
 
 바꾸고 난 뒤의 두 행과 하나의 열, 혹은 하나의 행과 두개의 열에 대해서면 검사를 진행한다.



3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int N;
string Candy[50];
char Colors[4] = { 'C', 'P', 'Z', 'Y'};

void swap(char&a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}

int crossCheck(int rowAndColumnNum, char Color) {
	int maxNum = 0;
	int cntRow = 0;
	int cntColumn = 0;
	for (int k = 0; k < N; k++) {
		if (Candy[rowAndColumnNum][k] == Color) {
			cntRow++;
		}
		else {
			maxNum = max(maxNum, cntRow);
			cntRow = 0;
		}
		if (Candy[k][rowAndColumnNum] == Color) {
			cntColumn++;
		}
		else {
			maxNum = max(maxNum, cntColumn);
			cntColumn = 0;
		}
	}
	maxNum = max(maxNum, cntRow);
	maxNum = max(maxNum, cntColumn);

	return maxNum;
}

int solution() {
	int maxNum = 0;

	// 아무것도 바꾸지 않았을 때 체크
	// 모든 색상에 대해 반복
	for (int i = 0; i < 4; i++) {
		// 행과 열 동시에 체크
		for (int j = 0; j < N; j++) {
			maxNum = max(maxNum, crossCheck(j, Colors[i]));
		}
	}
	
	// 더 커질 수는 없으므로
	if (maxNum == N) {
		return N;
	}

	// 바꿀 수 있는 모든 위치에서 체크
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 오른쪽 끝 좌표가 아니라면 오른쪽과의 교환 진행
			if (j != N - 1) {
				// 오른쪽과 교환
				if (Candy[i][j] != Candy[i][j + 1]) {
					// 교환
					swap(Candy[i][j], Candy[i][j + 1]);

					// 모든 색상에 대해 반복
					for (int k = 0; k < 4; k++) {
						// 최대값의 변동이 있을 수 있는 위치에 대해서만 체크
						maxNum = max(maxNum, crossCheck(i, Colors[k]));
						maxNum = max(maxNum, crossCheck(j, Colors[k]));
						maxNum = max(maxNum, crossCheck(j + 1, Colors[k]));
					}

					// 원상복귀
					swap(Candy[i][j], Candy[i][j + 1]);
				}
			}

			// 아래쪽 끝 좌표가 아니라면 아래쪽과의 교환 진행
			if (i != N - 1) {
				// 아래쪽과 교환
				if (Candy[i + 1][j] != Candy[i][j]) {
					// 교환
					swap(Candy[i + 1][j], Candy[i][j]);

					// 모든 색상에 대해 반복
					for (int k = 0; k < 4; k++) {
						// 최대값의 변동이 있을 수 있는 위치에 대해서만 체크
						maxNum = max(maxNum, crossCheck(i, Colors[k]));
						maxNum = max(maxNum, crossCheck(i + 1, Colors[k]));
						maxNum = max(maxNum, crossCheck(j, Colors[k]));
					}

					// 원상복귀
					swap(Candy[i + 1][j], Candy[i][j]);
				}
			}

			// 더 커질 수는 없으므로
			if (maxNum == N) {
				return N;
			}
		}
	}

	return maxNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> Candy[i];
	}

	cout << solution();

}