#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석

- 변수
N: 크레인의 수
M: 박스의 수

- 변수 제한 사항
N: 1~50
M: 1~10,000

qkrtmx		

 - 문제 상황
 추의 무개들이 주어졌을 때, 이 추들을 사용하여 측정할 수 없는 양의 정수 무게 중 최소값을 구하여라

2. 풀이 계획
이걸 어떻게 정렬해야 할까?

중복해서 뽑을 수 없고 순서가 상관 없으므로 조합 문제이긴 한데, 그렇다고 모든 조합을 다 구하기에는 2^N으로 지수적 시간복잡도를 보이므로 그렇게 구할 수는 없다.

그렇다면 어떻게?

DP, 조합에서 헤매고 있었는데, 정렬한 후 그리디로 간단히 표현이 가능한 것이었다!

정렬한 상태에서 누적합보다 크다면,

참고하여 정리하기!
https://plplim.tistory.com/59
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=hongjg3229&logNo=221627349685

Sn:

3. 계획 검증


*/

int N, M;
vector<int> weights;
vector<int> cranes;

int solution() {

	int minutes = 0;

	if (weights[N - 1] > cranes[M - 1]) {
		return -1;
	}

	while (!weights.empty()&&!cranes.empty()) {
		minutes++;

		int weightsIndex = weights.size() - 1;
		int cranesIndex = cranes.size() - 1;

		int cnt = 1;
		while (cranesIndex != -1) {
			if (weights[weightsIndex] <= cranes[cranesIndex]) {
				weights.erase(weights.begin() + weightsIndex);
				weightsIndex--;
				cranesIndex--;
			}
			else {
				weightsIndex--;
			}

			if (weightsIndex == -1) {
				break;
			}
			cnt ++;

		}
	}

	return minutes;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int crane;
		cin >> crane;

		cranes.push_back(crane);
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		int weight;
		cin >> weight;

		weights.push_back(weight);

	}

	sort(weights.begin(), weights.end());
	sort(cranes.begin(), cranes.end());

	cout << solution();

	return 0;
}