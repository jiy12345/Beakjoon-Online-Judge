#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
N, M: 직사각형의 세로, 가로 길이

- 변수 제한 사항
N, M: 1 ~ 50

- 문제 상황
 주어진 직사각형에서 꼭짓점에 쓰여있는 수가 모두 같은 가장 큰 정사각형의 크기를 구하여라

2. 풀이 계획
 각 위치별로 한번씩 계산하면 될 듯 하다!


3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

#define MAX 50

int N, M;
string rectangle[MAX];

int solution() {
	int answer = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 1; k < min(N - i, M - j); k++) {
				if (rectangle[i][j] == rectangle[i + k][j]
					&& rectangle[i + k][j] == rectangle[i][j + k]
					&& rectangle[i][j + k] == rectangle[i + k][j + k]
					) answer = max(answer, (k + 1) * (k + 1));
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> rectangle[i];
	}

	cout << solution();
}