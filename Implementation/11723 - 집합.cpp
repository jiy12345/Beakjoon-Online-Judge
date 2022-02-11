#include<iostream>
#include<string>
#include<map>
using namespace std;

/*
1. 문제 분석
- 변수
M: 연산의 수
x: 입력되는 수

- 변수 제한 사항
M: 1~3,000,000
x: 1~20

- 문제 상황
 비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다. 

 check 연산이 주어질 때마다 결과를 출력한다!

2. 풀이 계획

전형적인 조합 문제이다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

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

		// for debug
		//for (int i = 19; i >= 0; --i) {
		//	int result = S >> i & 1;
		//	printf("%d", result);
		//}
		//cout << endl;
	}

	return 0;
}