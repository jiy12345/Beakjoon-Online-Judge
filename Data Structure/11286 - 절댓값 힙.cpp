#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

int N;

class comp {
public: 
	bool operator()(const int& lhs, const int& rhs) const {
		// 두 값의 절대값이 같다면
		if (abs(lhs) == abs(rhs)) {
			// 값이 더 작은것이 먼저
			return lhs > rhs;
		}
		else { // 절대값이 다르다면, 절대값이 작은것이 먼저
			return abs(lhs) > abs(rhs);
		}

	}
};

void solution() {
	// 생성한 비교 클래스인 comp에 지정된 우선순위에 따라 heap에 저장하는 우선순위 큐
	priority_queue<int, vector<int>, comp> abs_min_heap;
	int input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == 0) { // 0이 입력될 경우
			if (abs_min_heap.empty()) { // 우선순위 큐가 비어있을 경우
				cout << 0 << '\n'; // 0 출력
			}
			else { // 비어있지 않을경우
				// 가장 top에 있는 값 출력하고 삭제
				cout << abs_min_heap.top() << '\n';
				abs_min_heap.pop();
			}
		}
		else {
			// 0 이 아닌 값이 입력되었을 경우 우선순위 큐에 푸시하기
			abs_min_heap.push(input);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	solution();
}
