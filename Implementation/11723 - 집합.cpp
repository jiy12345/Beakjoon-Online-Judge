#include<iostream>
#include<string>
#include<map>
using namespace std;

#define ALL_NUM 1048575

int S;

map<string, int> commandMap = {
	{"add", 0},
	{"remove", 1},
	{"check", 2},
	{"toggle", 3},
	{"all", 4},
	{"empty", 5},
};

enum commandEnum { ADD, REMOVE, CHECK, TOGGLE, ALL, EMPTY };

void solution(string command) {
	int commandNum = commandMap[command];
	int inputNum;

	switch (commandNum) {
	case ADD:
		cin >> inputNum;
		// 1일 경우 그대로, 0일 경우 1로
		S |= (1 << (inputNum - 1));
		break;	
	case REMOVE:
		cin >> inputNum;
		// 0일 경우 그대로, 1일 경우 0으로
		S &= ~(1 << (inputNum - 1));
		break;	
	case CHECK:
		cin >> inputNum;
		cout << ((S & (1 << (inputNum - 1))) >> (inputNum - 1)) << '\n';
		break;	
	case TOGGLE:
		cin >> inputNum;
		// 0일 경우 1로, 1일 경우 0으로
		S ^= (1 << (inputNum - 1));
		break;	
	case ALL:
		S = ALL_NUM;
		break;	
	case EMPTY:
		S = 0;
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		string command;

		cin >> command;

		solution(command);

		//// for debug
		//for (int i = 19; i >= 0; --i) {
		//	int result = S >> i & 1;
		//	cout << result;
		//}
		//cout << endl;
	}

	return 0;
}
