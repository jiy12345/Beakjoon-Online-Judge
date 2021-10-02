#include<iostream>
#include<queue>
using namespace std;

int N;

void solution() {
	// 최소 힙 생성
	priority_queue<int, vector<int>, greater<int>> max_heap;
	int input;

	for (int i = 0; i < N; i++) {
		cin >> input; // 값 입력받기
		if (input == 0) { // 입력이 0일 경우
			if (max_heap.empty()) { // 힙이 비었을 경우 
				// 0 출력
				cout << 0 << '\n';
			}
			else { // 힙에 값이 있을 경우 
				// top에 있는 값 출력하고 top에 있는 값 pop
				cout << max_heap.top() << '\n';
				max_heap.pop();
			}
		}
		else {
			// 0이 아닌 나머지 경우에는 heap에 항상 푸시
			max_heap.push(input);
		}
	}
}

int main() {
	// 빠른 입출력을 위한 입력
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	solution();
}
