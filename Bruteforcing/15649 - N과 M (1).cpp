#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N, M: N개의 자연수 중에서 M개를 고른 수열에서의 입력이 되는 수

- 변수 제한 사항
N, M: 1~8

- 문제 상황
N개의 자연수 중에서 M개를 고른 수열을 모두 출력한다.
중복되는 수열이 여러번 출력되서는 안된다.
수열은 사전순으로 증가하는 순서로 출력되어야 한다.

2. 풀이 계획
 전형적인 순열문제이다. 재귀로 구현하면 될듯 하다.

 조합문제일 때는 이미 선택한 것 이후로만 선택하므로 선택했는지 여부를 따질 필요가 없었는데, 순열은 어떻게 할까?


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int M, N;
int sequence[8];
bool isPicked[8];
vector<int>subSequence;

void solution() {
	int curSize = subSequence.size();
	if (curSize == M) {
		for (int i = 0; i < curSize; i++) {
			cout << subSequence[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (isPicked[i] == false) {
			subSequence.push_back(sequence[i]);
			isPicked[i] = true;
			solution();
			subSequence.pop_back();
			isPicked[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		sequence[i] = i + 1;
	}

	solution();
}