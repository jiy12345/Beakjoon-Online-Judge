#include<iostream>
#include<algorithm>
using namespace std;

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

	if (isOne) {
		copy(&A1[0][0], &A1[0][0] + 300 * 300, &A2[0][0]);
	}
	else {
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
