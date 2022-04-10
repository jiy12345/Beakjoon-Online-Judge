#include<iostream>
#include<map>
using namespace std;

/*
1. 문제 분석
- 변수
n: 수열에 속한 정수의 개수

- 변수 제한 사항
n:1~100,000
수열에 속한 수: -1,000~1,000

- 문제 상황
 n개의 수를 가진 수열이 주어졌을 때, 연속된 몇개의 수를 선택하여 구할 수 있는 합 중 가장 큰 합을 구하여라.
 이 때, 연속된 수 중 한 수는 제외될 수 있다.

2. 풀이 계획
 제거 안한 상태의 합과 제거 한 상태의 합을 따로 저장하는게 좋을 듯 하다!

 제거 안한 상태의 최대값


 어려웠던 점

 각 위치의 수가 무엇인지 명확히 정하고 진행하지 않아서 어려웠던 점이 있었던 것 같다!

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

#define STACK_CAPACITY 10000

enum STACK_COMMAND { PUSH, POP, SIZE, EMPTY, TOP };
map<string, int> stackCommandMap = { {"push", PUSH},
		{"pop", POP},
		{"size", SIZE},
		{"empty", EMPTY},
		{"top", TOP},
};

class stack {
private:
	int stackArray[STACK_CAPACITY] = { 0, };
	int top_index;

public:
	stack() {
		top_index = -1;
	}

	bool push(int X) {
		if (full()) {
			return -1;
		}
		else {
			stackArray[++top_index] = X;
		}

	}

	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			return stackArray[top_index--];
		}
	}

	int size() {
		return top_index + 1;
	}

	bool empty() {
		return (top_index == -1);
	}

	int top() {
		if (empty()) {
			return -1;
		}
		else {
			return stackArray[top_index];
		}
	}

	bool full() {
		return (top_index == STACK_CAPACITY - 1);
	}
};

void solution() {
	int N;
	cin >> N;

	stack Stack = stack();

	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;

		switch (stackCommandMap[command]) {
		case PUSH:
			int X;
			cin >> X;
			Stack.push(X);
			break;
		case POP:
			cout << Stack.pop() << '\n';
			break;
		case SIZE:
			cout << Stack.size() << '\n';
			break;
		case EMPTY:
			cout << Stack.empty() << '\n';
			break;
		case TOP:
			cout << Stack.top() << '\n';
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solution();

	return 0;
}