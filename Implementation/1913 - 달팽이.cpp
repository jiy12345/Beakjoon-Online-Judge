#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
 N: 격자의 가로, 세로 길이

- 변수 제한 사항
 N: 3 ~ 999
 N은 홀수


- 문제 상황
 N이 주어졌을 때 가운데서부터 달팽이 모양으로 수들을 출력하고, 주어진 수의 좌표를 구하여라.


2. 풀이 계획


1. 방문이 가능한 위치에 대해(저장된 에너지 양이 0이 아닌 위치에 대해) 다음을 반복한다.
 1) 현 위치의 다음위치부터 끝 위치까지갈 수 있는 위치까지 총 필요한 에너지양을 다음과 같은 식에 따라 구한다.
  다음 위치의 에너지 양 = 현재 위치까지의 에너지 양 + k * k
 2) 1)에서 구한 값이 현재 저장되어 있는 값보다 작을 때만 갱신하고,그렇지 않으면 갱신하지 않는다.

3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/
#define MAX 999

enum DIRECTION{UP, RIGHT, DOWN, LEFT};
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int snail[MAX][MAX];

int N, target;

void solution() {
	int target_i = 0;
	int target_j = 0;

	// 첫 위치는 가운데
	int cur_i = (N + 1) / 2 - 1;
	int cur_j = (N + 1) / 2 - 1;
	int cur_num = 1;
	int cur_direction = UP;

	if (cur_num == target) {
		target_i = cur_i + 1;
		target_j = cur_j + 1;
	}
	snail[cur_i][cur_j] = cur_num++;

	// 한줄에 쓸 숫자 개수
	for (int i = 0; i < N - 1; i++) {
		// 같은 횟수만큼 두번씩 이동
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < i + 1; j++) {
				cur_i = cur_i + di[cur_direction];
				cur_j = cur_j + dj[cur_direction];
				if (cur_num == target) {
					target_i = cur_i + 1;
					target_j = cur_j + 1;
				}
				snail[cur_i][cur_j] = cur_num++;
			}
			// 방향 전환
			cur_direction++;
			cur_direction %= 4;
		}
	}

	// 마지막 줄 긋기
	for (int j = 0; j < N - 1; j++) {
		cur_i = cur_i + di[cur_direction];
		cur_j = cur_j + dj[cur_direction];
		if (cur_num == target) {
			target_i = cur_i + 1;
			target_j = cur_j + 1;
		}

		snail[cur_i][cur_j] = cur_num++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << snail[i][j] << " ";
		}
		cout << '\n';
	}

	cout << target_i << " " << target_j;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> target;

	solution();
}