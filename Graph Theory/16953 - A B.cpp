#include<iostream>
#include<queue>
#include<map>
using namespace std;

/*
1. 문제 분석
- 변수
A, B: 주어지는 두 숫자


- 변수 제한 사항
1,000,000,000


- 문제 상황
두 수 A, B가 주어지고, 가능한 연산이 다음과 같다고 할 때,

2를 곱한다.
1을 수의 가장 오른쪽에 추가한다.

A를 B로 바꾸는데 필요한 연산의 최소값을 구하여라.
바꿀 수 없을 경우 -1을 출력한다.

2. 풀이 계획

1. bfs를 진행하되

방문 표시를 bool형으로 진행하면 1기가바이트가 필요하다. 어떻게 처리할 수 있을까?

- 연산 1: 비트 연산 <<로 구현 가능
=> 연산 1의 결과는 항상 짝수이다.
- 연산 2: 수에 10을 곱한 후 1 더하는 것으로 구현 가능
=> 연산 2의 결과는 항상 홀수이다.

=> 가능한 두 연산이 모두 수가 커지는 연산이므로, B이상으로 진행할 필요가 없다.



3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

int A, B;
map<int, int> isVisited;


int bfs() {
	int answer = -1;

	queue<pair<int, int>> bfs_queue;
	bfs_queue.push({ 0, B });

	while (!bfs_queue.empty()) {
		int cur_depth		= bfs_queue.front().first;
		long long cur_i		= bfs_queue.front().second;
		bfs_queue.pop();

		if (cur_i <= A) {
			if(cur_i == A) answer = cur_depth + 1;
			break;
		}

		int next_depth = cur_depth + 1;

		// 연산 1. 2로 나누기
		if (cur_i % 2 == 0) {
			int next_i = cur_i >> 1;

			bfs_queue.push({ next_depth, next_i });
		}

		if ((cur_i - 1) % 10 == 0) {
			// 연산 2. 10을 곱하고 1 더하기
			int next_i = (cur_i -1) / 10;
	
			isVisited[next_i]++;
			bfs_queue.push({ next_depth, next_i });
		
		}

	}
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;

	cout << bfs();
}