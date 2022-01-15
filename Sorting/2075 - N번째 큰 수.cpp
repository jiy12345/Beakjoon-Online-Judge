#include<iostream>
#include<queue>

using namespace std;

/*
1. 문제 분석
- 변수
N: 세로, 가로길이

- 변수 제한 사항
N: 1~1,500

- 문제 상황
A[r][c]에 들어있는 값이 k가 되기 위한 연산의 최소 시간을 출력한다. 100초가 지나도 A[r][c] = k가 되지 않으면 -1을 출력한다.

2. 풀이 계획
R 연산: 배열 A의 모든 행에 대해서 정렬을 수행한다. 행의 개수 ≥ 열의 개수인 경우에 적용된다.
C 연산: 배열 A의 모든 열에 대해서 정렬을 수행한다. 행의 개수 < 열의 개수인 경우에 적용된다.

R 연산과 C연산 모두 다음과 같은 과정을 거쳐 진행한다.

1. 행(혹은 열)을 처음부터 끝까지 탐색하며 map을 통해 각 수의 개수를 센다.
2. 수의 개수에 대해 오름차순으로, 그 후 수 자체에 대해 오름차순으로 정렬한다.
3. 생성한 map을 배열에 입력한다. 이 때, 가장 긴 map보다 짧은 map들에 대해서 남은 부분은 0, 0으로 채운다!


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

priority_queue<int, vector<int>, greater<int>> priorityQueue;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;

			if (priorityQueue.size() < N) {
				priorityQueue.push(num);
			} // 가장 큰 수 N개만 유지하면 되므로, 현재 큐의 최소값보다 큰 수만 받기
			else if (num > priorityQueue.top()) {
				priorityQueue.push(num);
				priorityQueue.pop();
			}
		}
	}

	cout << priorityQueue.top();
}