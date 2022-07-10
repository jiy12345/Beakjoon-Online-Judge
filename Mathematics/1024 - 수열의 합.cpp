#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
N: 수의 상한
L: 수열 길이의 하한

- 변수 제한 사항
 N: 1 ~ 1,000,000,000
 L: 2 ~ 100

- 문제 상황
N, L이 주어졌을 때, 길이가 적어도 L인 가장 짧은 연속된 음이 아닌 정수 리스트를 출력하라.
만약 길이가 100보다 크거나 그러한 수열이 없을 때는 -1을 출력한다.

2. 풀이 계획​

 1. 이 성에 있는 방의 개수
각각의 방마다 bfs를 진행하며 방문 표시를 하고, 번호를 매기며 방의 개수를 세면 될 듯 하다.

 2. 가장 넓은 방의 넓이
bfs를 진행하며 각각의 방의 넓이를 기록해두고, 그 중 가장 큰 값을 찾으면 될 듯 하다.

 3. 하나의
각 방에 대한 bfs를 진행하며 해당 방이 어떤 방과 벽을 두고 접하고 있는지를 기록한 뒤,

모든 bfs를 마친 후 두 인접한 방을 합한 넓이의 최대값을 구한다.


3. 계획 검증
 1. 알고리즘 측면​

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

long long N;
int L;

void solution() {
	int res = -1, index = 0;
	// 가능한 모든 길이에 대해 고려
	for (int i = L; i <= 100; i++) {
		int k = i * (i - 1) / 2;
		// 시작 숫자 구하기
		int start_num = (N - k) / i;
		if ((N - k) % i == 0 && start_num >= 0) {
			res = start_num;
			index = i;
			break;
		}
	}

	if (res == -1) cout << -1;
	else for (int i = 0; i < index; i++) cout << res + i << " ";
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N >> L;

	solution();
}