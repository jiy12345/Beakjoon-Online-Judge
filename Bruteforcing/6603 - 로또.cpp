#include<iostream>
#include<vector>

using namespace std;

/*
1. 문제 분석
- 변수
k: 수의 개수

- 변수 제한 사항
k: 6~13

- 문제 상황
오름차순으로 주어진 개수의 수 중 6개의 수를 뽑늑 모든 경우의수를 출력하라

2. 풀이 계획

전형적인 조합 문제이다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int sequence[13];
vector<int>subSequence;

void solution(int index, int k) {
	int curSize = subSequence.size();
	if (curSize == 6) {
		for (int i = 0; i < curSize; i++) {
			cout << subSequence[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = index; i < k; i++) {
		subSequence.push_back(sequence[i]);
		solution(i + 1, k);
		subSequence.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k;
	cin >> k;

	while (k != 0) {
		for (int i = 0; i < k; i++) {
			cin >> sequence[i];
		}
		solution(0, k);
		cout << "\n";

		cin >> k;
	}

	return 0;
}