#include<iostream>
#include<map>
using namespace std;

/*
큰 문제점

인덱스를 저장 하여야 할 위치로 할 것인가, 저장된 위치로 할 것인가?

전자는 처리할 예외가 많아지며, 후자는 사이즈나 빈 큐 체크, 초기 삽입에 어려움이 있다!


사이즈 체크 시 push_front로 앞쪽으로 넘어갔을 경우와 
push_back_으로 뒤쪽으로 넘어 갔을 경우를 구분해야 하므로, 차라리 size 변수를 하나 만들기로 했다.

*/

#define DEQUE_CAPACITY 10000

enum DEQUEUE_COMMAND { PUSH_FRONT, PUSH_BACK, POP_FRONT, POP_BACK, SIZE, EMPTY, FRONT, BACK };
map<string, int> dequeCommandMap = { 
		{"push_front", PUSH_FRONT},
		{"push_back", PUSH_BACK},
		{"pop_front", POP_FRONT},
		{"pop_back", POP_BACK},
		{"size", SIZE},
		{"empty", EMPTY},
		{"front", FRONT},
		{"back", BACK},
};

class deque {
private:
	int dequeArray[DEQUE_CAPACITY] = { 0, };
	int front_index; // 현재 저장된 값의 왼쪽 끝 위치
	int back_index; // 저장되어야할 위치

public:
	deque() {
		front_index = 0;
		back_index = 0;
	}

	void push_front(int X) {
		front_index--;
		if (front_index == -1) {
			front_index = DEQUE_CAPACITY - 1;
		}

		dequeArray[front_index] = X;
	}

	void push_back(int X) {
		dequeArray[back_index] = X;

		back_index++;
		if (back_index == DEQUE_CAPACITY) {
			back_index = 0;
		}
	}

	int pop_front() {
		if (empty()) {
			return -1;
		}
		else {
			int temp = dequeArray[front_index];
			front_index++;
			if (front_index == DEQUE_CAPACITY) {
				front_index = 0;
			}

			return temp;
		}
	}

	int pop_back() {
		if (empty()) {
			return -1;
		}
		else {
			back_index--;
			if (back_index == -1) {
				back_index = DEQUE_CAPACITY - 1;
			}

			return dequeArray[back_index];
		}
	}

	int size() {
		if (back_index < front_index) {
			return (DEQUE_CAPACITY - front_index) + back_index;
		}
		else {
			return back_index - front_index;
		}
	}

	bool empty() {
		return (front_index == back_index) ? true : false;
	}

	int front() {
		if (empty()) {
			return -1;
		}
		else {
			return dequeArray[front_index];
		}
	}

	int back() {
		if (empty()) {
			return -1;
		}
		else {
			return(back_index == 0) ? dequeArray[DEQUE_CAPACITY - 1] : dequeArray[back_index - 1];
		}
	}

	void print() {
		cout << "back_index: " << back_index << endl;
		cout << "front_index: " << front_index << endl;
		if (back_index < front_index) {
			cout << "{ ";
			for (int i = front_index; i < DEQUE_CAPACITY; i++) {
				cout << dequeArray[i] << " ";
			}
			for (int i = 0; i < back_index; i++) {
				cout << dequeArray[i] << " ";
			}
			cout << "}" << endl;
		}
		else {
			cout << "{ ";
			for (int i = front_index; i < back_index; i++) {
				cout << dequeArray[i] << " ";
			}
			cout << "}" << endl;
		}
	}
};

void solution() {
	int N;
	cin >> N;

	deque Dequeue = deque();

	for (int i = 0; i < N; i++) {
		string command;
		int X;
		cin >> command;

		switch (dequeCommandMap[command]) {
		case PUSH_FRONT:
			cin >> X;
			Dequeue.push_front(X);
			break;		
		case PUSH_BACK:
			cin >> X;
			Dequeue.push_back(X);
			break;
		case POP_FRONT:
			cout << Dequeue.pop_front() << '\n';
			break;		
		case POP_BACK:
			cout << Dequeue.pop_back() << '\n';
			break;
		case SIZE:
			cout << Dequeue.size() << '\n';
			break;
		case EMPTY:
			cout << Dequeue.empty() << '\n';
			break;
		case FRONT:
			cout << Dequeue.front() << '\n';
			break;
		case BACK:
			cout << Dequeue.back() << '\n';
			break;
		}
		// Dequeue.print();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solution();

	return 0;
}