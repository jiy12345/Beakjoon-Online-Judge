#include<iostream>
#include<vector>
using namespace std;


/*
1. 문제 분석
- 변수
N: 수열에 포함된 수의 개수

- 변수 제한 사항
N: 2 ~ 11
중간 연산 결과를 포함한 모든 식의 결과는 -10억 ~ 10억 사이이다
각 사칙연산자의 개수: N-1 ~ 4N

- 문제 상황
 각 사칙연산자의 개수가 주어졌을 때, 식의 최대값과 최소값을 구하여라.


2. 풀이 계획

일단 10,000이 입력의 최대 크기이므로, 무작정 처음부터 돌리는 것은 불가능하다.

따라서 다음 순열을 실제 구해야 하는데, 다음 순열이라는 것은 어떻게 표현할까?

=> 정렬되는 과정이라고 볼 수도 있겠다.

3. 계획 검증


*/

enum{PLUS, MINUS, MULTIYPLY, DIVIDE, OPER_NUM};

int N;
int operands[11];
int numOfOperator[4];

int minNum, maxNum;

void solution(int numToDraw, int curResult) {
	if (numToDraw == 0) {
		minNum = min(minNum, curResult);
		maxNum = max(maxNum, curResult);
		return;
	}

	for (int i = 0; i < OPER_NUM; i++) {
		if (numOfOperator[i] == 0) {
			continue;
		}

		numOfOperator[i]--;
		switch (i) {
		case PLUS:
			solution(numToDraw - 1, curResult + operands[N - numToDraw]);
			break;		
		case MINUS:
			solution(numToDraw - 1, curResult - operands[N - numToDraw]);
			break;		
		case MULTIYPLY:
			solution(numToDraw - 1, curResult * operands[N - numToDraw]);
			break;		
		case DIVIDE:
			solution(numToDraw - 1, curResult / operands[N - numToDraw]);
			break;
		}
		numOfOperator[i]++;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> curPermutation;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> operands[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> numOfOperator[i];
	}

	maxNum = -1000000000;
	minNum = 1000000000;

	solution(N - 1, operands[0]);

	cout << maxNum << '\n';
	cout << minNum << '\n';

	return 0;
}