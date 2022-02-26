#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 배열의 세로 길이
M: 배열의 가로 길이
R: 회전시킬 횟수
Aij: 주어지는 배열의 i행 j열 원소

- 변수 제한 사항
N, M: 2 ~ 300
N, M은 짝수
R: 1 ~ 1,000
Aij: 1 ~ 10,000,000

- 문제 상황
 수빈이와 동생의 위치가 주어지고, 수빈이는 다음과 같이 이동한다고 하자.

 수빈이의 현 위치가 X일 때,

 - 걷기: 1초후에 X - 1 or X + 1
 - 순간이동: 0초 후에 2 * X

 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

2. 풀이 계획

0 - 1 로 간선이 서로 다른 가중치를 가지고 있기는 하지만,

우선순위 큐를 이동한다면?
 => 어떤 노드를 먼저 방문 했다고 했을 때, 그 방문까지 걸린 시간이 최단시간이라고 보장할 수 없기 때문에 안된다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int GCD(int a, int b) {
	while (b != 0) {
		int r = a % b;	// 나머지를 구해준다.

		a = b;
		b = r;
	}
	return a;
}

long long LCM(long long a, long long b) {
	return a * b / GCD(a, b);
}

int N, M, R;
int A1[300][300];
int A2[300][300];
bool isOne = true; // 1번 배열에 현재 연산된 전체 배열이 저장

void rotate(int cur_row, int cur_R) {

	for (int i = 0; i < cur_R; i++) {
		if (isOne) {
			// 좌 -> 우, 우 -> 좌
			for (int j = cur_row; j < M - cur_row - 1; j++) {
				A2[cur_row][j] = A1[cur_row][j + 1];
				A2[N - cur_row - 1][j + 1] = A1[N - cur_row - 1][j];
			}

			// 상 -> 하, 하 -> 상
			for (int j = cur_row; j < N - cur_row - 1; j++) {
				A2[j + 1][cur_row] = A1[j][cur_row];
				A2[j][M - cur_row - 1] = A1[j + 1][M - cur_row - 1];
			}
			isOne = false;
		}
		else {
			// 좌 -> 우, 우 -> 좌
			for (int j = cur_row; j < M - cur_row - 1; j++) {
				A1[cur_row][j] = A2[cur_row][j + 1];
				A1[N - cur_row - 1][j + 1] = A2[N - cur_row - 1][j];
			}

			// 상 -> 하, 하 -> 상
			for (int j = cur_row; j < N - cur_row - 1; j++) {
				A1[j + 1][cur_row] = A2[j][cur_row];
				A1[j][M - cur_row - 1] = A2[j + 1][M - cur_row - 1];
			}
			isOne = true;
		}
	}

	if (cur_R % 2 != 0) {
		copy(&A2[0][0], &A2[0][0] + 300 * 300, &A1[0][0]);
	}
}


void solution() {
	copy(&A1[0][0], &A1[0][0] + 300 * 300, &A2[0][0]);

	int cnt = 0;
	int n = N;
	int m = M;

	while (true) {
		int cur_R = R % (2 * n + 2 * m - 4);
		rotate(cnt, cur_R);
		if (n == 2 || m == 2) {
			break;
		}
		n -= 2;
		m -= 2;
		cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A1[i][j];
		}
	}

	solution();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A1[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}