#include <iostream>
#include <vector>
using namespace std;

/*
1. 문제 분석
- 변수
 H, W: 배열 A의 크기
 X, Y: 배열 A를 이동 얼마나 이동시켰는가?

- 변수 제한 사항
H, W: 2~300

1 ≤ X < H
1 ≤ Y < W
0 ≤ Bi,j ≤ 1,000

- 문제 상황

배열 B의 (i, j)에 들어있는 값은 아래 3개 중 하나이다.

(i, j)가 두 배열 모두에 포함되지 않으면, Bi,j = 0이다.
(i, j)가 두 배열 모두에 포함되면, Bi,j = Ai,j + Ai-X,j-Y이다.
(i, j)가 두 배열 중 하나에 포함되면, Bi,j = Ai,j 또는 Ai-X,j-Y이다.

 배열 A를 구하여라

2. 풀이 계획


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int H, W, X, Y;
int B[600][600];
int A[300][300];

void solution() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i - X >= 0 && j - Y >= 0) {
                A[i][j] = B[i][j] - A[i - X][j - Y];
            }
            else {
                A[i][j] = B[i][j];
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W >> X >> Y;

	for (int i = 0; i < H + X; i++) {
		for (int j = 0; j < W + Y; j++) {
			cin >> B[i][j];
		}
	}

	solution();

	return 0;
}