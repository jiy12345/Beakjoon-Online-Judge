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

#define QUEUE_CAPACITY 5

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

			return queueArray[front_index - 1];
		}
	}

	int size() {
		if (back_index < front_index) {
			return (QUEUE_CAPACITY - back_index) + back_index - 1;
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
			return queueArray[back_index - 1];
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

	queue Queue = queue();

	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;

		switch (queueCommandMap[command]) {
		case PUSH:
			int X;
			cin >> X;
			Queue.push(X);
			break;
		case POP:
			cout << Queue.pop() << '\n';
			break;
		case SIZE:
			cout << Queue.size() << '\n';
			break;
		case EMPTY:
			cout << Queue.empty() << '\n';
			break;
		case FRONT:
			cout << Queue.front() << '\n';
			break;
		case BACK:
			cout << Queue.back() << '\n';
			break;
		}
		Queue.print();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solution();

	return 0;
}