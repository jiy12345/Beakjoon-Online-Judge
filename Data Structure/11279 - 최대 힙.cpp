#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석

- 변수
N: 주어질 연산의 개수

- 변수 제한 사항
4 <= N <= 100,000
0 <= 입력되는수 <= 2^31

 - 문제 상황
 입력되는 수가 자연수라면 배열에 자연수를 입력하고, 자연수가 아닌 0이라면 배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거하는 동작을 하도록 프로그램을 작성하라.
 이 때 배열이 비어있는데 출력을 요구한 경우 0을 출력한다.

2. 풀이 계획
 이 문제는 c++에서 제공하는 <queue>라이브러리(우선순위 큐를 구현한 라이브러리)를 사용하면 어렵지 않게 풀 수 있을 듯 하다.

 우선순위 큐는 조건에 따라 모든 원소에 대해 비교우위에 있는 값(예를 들면 최대값, 최소값 등)을 top에 위치시켜, 해당 값은 O(1)의 시간복잡도로 탐색이 가능하게 하는 자료구조이다.

 따라서 자세한 과정은 다음과 같다.

1. top이 항상 최대값인 우선순위 큐를 선언한다.
2. 입력에 따라 다음 행동을 진행한다.
 1) 0이 입력되면 top에 있는 값을 출력하고 top에 있는 값을 삭제한다.
 2) 자연수가 입력되면 자연수를 우선순위 큐에 삽입한다.

3. 계획 검증


*/

int N;

void solution() {
	priority_queue<int> max_heap;
	int input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == 0) {
			if (max_heap.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << max_heap.top() << '\n';
				max_heap.pop();
			}
		}
		else {
			max_heap.push(input);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	solution();
}