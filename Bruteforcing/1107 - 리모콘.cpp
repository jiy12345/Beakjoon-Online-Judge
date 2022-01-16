#include<iostream>
#include<string>

using namespace std;

/*
1. 문제 분석
- 변수
N: 이동하려고 하는 채널
M: 고장난 버튼의 개수

- 변수 제한 사항
N: 1~500,000
M: 0~10

- 문제 상황
현재 채널이 100번이고, 어떤 숫자 버튼이 고장났는지 주어졌다고 할 때,
 
채널 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지 출력하라

2. 풀이 계획
 최소값이 될 수 있는 값들의 후보를 생각해보면, 다음과 같다.

 1. 현재 위치에서 +나 -만을 이용해서 가기
 2. +나 -로 이동해서 N까지 갈 수 있는 최대한 가까운 수로 이동한 후, +나 -로 이동하기

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

bool isAbnormal[10];
int N, M;

int solution() {
	int end = abs(N - 100);
	int answer = end;

	for (int i = 0; i < end; i++) {
		string numPlus = to_string(N + i);
		string numMinus = to_string(N - i);

		int j = 0;

		if (stoi(numMinus) >= 0) {
			int numMinusLength = numMinus.size();

			for (j = 0; j < numMinusLength; j++) {
				if (isAbnormal[numMinus[j] - 48]) {
					break;
				}
			}

			if (j == numMinusLength) {
				answer = min(answer, (numMinusLength + i));
				break;
			}
		}

		if (stoi(numPlus) <= 1000000) {

			int numPlusLength = numPlus.size();

			for (j = 0; j < numPlusLength; j++) {
				if (isAbnormal[numPlus[j] - 48]) {
					break;
				}
			}

			// 모든 수가 누를 수 있는 수일 때
			if (j == numPlusLength) {
				answer = min(answer, (numPlusLength + i));
				break;
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;

		cin >> num;

		isAbnormal[num] = true;
	}

	cout << solution();
}