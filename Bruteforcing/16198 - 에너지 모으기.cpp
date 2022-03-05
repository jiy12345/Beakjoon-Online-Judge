#include<iostream>
#include<vector>
using namespace std;


/*
1. 문제 분석
- 변수
Wi: i번째 구슬의 무게

- 변수 제한 사항
Wi: 1 ~ 1,000

- 문제 상황

다음과 같은 규칙에 따라 에너지를 모을 수 있다고 할 때,

1. 에너지 구슬 하나를 고른다. 고른 에너지 구슬의 번호를 x라고 한다. 단, 첫 번째와 마지막 에너지 구슬은 고를 수 없다.
2. x번째 에너지 구슬을 제거한다.
3. Wx-1 × Wx+1의 에너지를 모을 수 있다.
4. N을 1 감소시키고, 에너지 구슬을 1번부터 N번까지로 다시 번호를 매긴다. 번호는 첫 구슬이 1번, 다음 구슬이 2번, ... 과 같이 매겨야 한다.

모을 수 있는 에너지 양의 최댓값을 구하여라

2. 풀이 계획

일단 10,000이 입력의 최대 크기이므로, 무작정 처음부터 돌리는 것은 불가능하다.

따라서 다음 순열을 실제 구해야 하는데, 다음 순열이라는 것은 어떻게 표현할까?

=> 정렬되는 과정이라고 볼 수도 있겠다.

3. 계획 검증


*/

int N;
vector<int> W;

int solution(int prevEnergy) {
	int maxNum = 0;
	if (W.size() == 2) {
		return prevEnergy;
	}

	for (int i = 1; i < W.size() - 1; i++) {
		int temp = W[i];
		W.erase(W.begin() + i);
		maxNum = max(maxNum, solution(prevEnergy + W[i - 1] * W[i]));
		W.insert(W.begin() + i, temp);
	}

	return maxNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		W.push_back(temp);
	}

	cout << solution(0);

	return 0;
}