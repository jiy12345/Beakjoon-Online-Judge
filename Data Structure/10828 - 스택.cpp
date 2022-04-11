#include<iostream>
#include<map>
using namespace std;

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

	int push(int X) {
		if (full()) {
			return -1;
		}
		else {
			stackArray[++top_index] = X;
			return 1;
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
