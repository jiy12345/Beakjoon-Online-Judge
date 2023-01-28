#include<iostream>
#include<map>
using namespace std;

#define QUEUE_CAPACITY 2000000

enum QUEUE_COMMAND { PUSH, POP, SIZE, EMPTY, FRONT, BACK };
map<string, int> queueCommandMap = { {"push", PUSH},
		{"pop", POP},
		{"size", SIZE},
		{"empty", EMPTY},
		{"front", FRONT},
		{"back", BACK},
};

class queue {
private:
	int queueArray[QUEUE_CAPACITY] = { 0, };
	int front_index;
	int back_index;

public:
	queue() {
		front_index = 0;
		back_index = 0;
	}

	void push(int X) {
		queueArray[back_index] = X;

		back_index++;
		if (back_index == QUEUE_CAPACITY) {
			back_index = 0;
		}
	}

	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			front_index++;

			if (front_index == QUEUE_CAPACITY) {
				front_index = 0;
			}

			// 큐의 인덱스가 앞으로 돌아왔을 경우를 대비하여
			return (front_index == 0) ? queueArray[QUEUE_CAPACITY - 1] : queueArray[front_index - 1];
		}
	}

	int size() {
		if (back_index < front_index) {
			return (QUEUE_CAPACITY - front_index) + back_index;
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
			return queueArray[front_index];
		}
	}

	int back() {
		if (empty()) {
			return -1;
		}
		else {
			return(back_index == 0) ? queueArray[QUEUE_CAPACITY - 1] : queueArray[back_index - 1];
		}
	}

	void print() {
		if (back_index < front_index) {
			cout << "{ ";
			for (int i = front_index; i < QUEUE_CAPACITY; i++) {
				cout << queueArray[i] << " ";
			}
			for (int i = 0; i < back_index; i++) {
				cout << queueArray[i] << " ";
			}
			cout << "}" << endl;
		}
		else {
			cout << "{ ";
			for (int i = front_index; i < back_index; i++) {
				cout << queueArray[i] << " ";
			}
			cout << "}" << endl;
		}

	}
};



void solution() {
	int N;
	cin >> N;

	queue *Queue = new queue;

	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;

		switch (queueCommandMap[command]) {
		case PUSH:
			int X;
			cin >> X;
			Queue->push(X);
			break;
		case POP:
			cout << Queue->pop() << '\n';
			break;
		case SIZE:
			cout << Queue->size() << '\n';
			break;
		case EMPTY:
			cout << Queue->empty() << '\n';
			break;
		case FRONT:
			cout << Queue->front() << '\n';
			break;
		case BACK:
			cout << Queue->back() << '\n';
			break;
		}
		//Queue->print();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solution();

	return 0;
}