#include<iostream>
#include<string>
using namespace std;

/*
1. 문제 분석
- 변수
k: 부등호의 개수

- 변수 제한 사항
k: 2~9

- 문제 상황
 제시된 부등호관계를 만족하는 k+1자리의 최대, 최소 정수를 각각 출력한다!

2. 풀이 계획
 전형적인 순열문제이다. 재귀로 구현하면 될듯 하다.

 조합문제일 때는 이미 선택한 것 이후로만 선택하므로 선택했는지 여부를 따질 필요가 없었는데, 순열은 어떻게 할까?


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

#define FORWARD true
#define BACKWARD false

int k;
bool inEqualitySigns[9];
int isPicked[10];

string minNum = "999999999";
string maxNum = "0";

// curOrder: 현재 몇번째 수까지 뽑았는지
// prevNum: 이전에 뽑은 수
void solution(int curOrder, int prevNum, string resultNum) {
	//cout << "curOrder: " << curOrder;
	//cout << ", inEqualitySigns[curOrder]: " << inEqualitySigns[curOrder];
	//cout << ", resultNum: " << resultNum << '\n';
	if (curOrder == k) {
		minNum = min(minNum, resultNum);
		maxNum = max(maxNum, resultNum);
		return;
	}

	if (inEqualitySigns[curOrder] == FORWARD) {
		for (int curNum = prevNum + 1; curNum <= 9; curNum++) {
			if (isPicked[curNum] == false) {
				isPicked[curNum] = true;
				solution(curOrder + 1, curNum, resultNum + to_string(curNum));
				isPicked[curNum] = false;
			}
		}
	}
	else {
		for (int curNum = prevNum - 1; curNum >= 0; curNum--) {
			if (isPicked[curNum] == false) {
				isPicked[curNum] = true;
				solution(curOrder + 1, curNum, resultNum + to_string(curNum));
				isPicked[curNum] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;

	for (int i = 0; i < k; i++) {
		char inEqualitySign;
		cin >> inEqualitySign;

		inEqualitySigns[i] = (inEqualitySign == '<') ? true : false;
	}

	for (int curNum = 0; curNum <= 9; curNum++) {
		isPicked[curNum] = true;
		solution(0, curNum, to_string(curNum));
		isPicked[curNum] = false;
	}

	cout << maxNum << '\n';
	cout << minNum;
}