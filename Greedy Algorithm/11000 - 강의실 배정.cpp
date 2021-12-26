#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석

- 변수
N: 수업의 개수

S[i]: i번째 수업이 시작하는 시간
T[i]: i번째 수업이 끝나는 시간

- 변수 제한 사항
N: 1~200,000
0 ≤ Si < Ti ≤ 10^9

 - 문제 상황
 추의 무개들이 주어졌을 때, 이 추들을 사용하여 측정할 수 없는 양의 정수 무게 중 최소값을 구하여라

2. 풀이 계획
 끝 기준으로 정렬하면 된다,

3. 계획 검증


*/

class comp {
public:
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
		// 차 이름이 같다면,
		if (lhs.second == rhs.second) {
			// 차 번호가 작은 것이 먼저
			return lhs.first > rhs.first;
		}
		else { // 차 이름이 다르다면, 사전순으로 이름이 먼저인 차가 먼저
			return lhs.second > rhs.second;
		}
	}
};


int N;
priority_queue <pair<int, int>, vector<pair<int, int>>, comp> schedule;

int solution() {
	int curEndTime = 0;
	int answer = 0;

	for (int i = 0; i < N; i++) {
		if (schedule.top().first >= curEndTime) {
			curEndTime = schedule.top().second;
		}
		else {
			answer++;
		}
		schedule.pop();
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int S;
		int T;
		cin >> S >> T;

		schedule.push(make_pair(S, T));
	}

	cout << solution();

	return 0;
}