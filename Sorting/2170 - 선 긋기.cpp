#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석

- 변수
N: 줄의 수
x, y: 선을 그을 때 선택한 두 점의 위치

- 변수 제한 사항
N: 1~1,000,000
x, y: -1,000,000,000~1,000,000,000

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

int N;
vector<pair<int, int>> locations;

int solution() {
	int answer = 0;

	sort(locations.begin(), locations.end());

	int cur_start = locations[0].first;
	int cur_end = locations[0].second;

	for (int i = 1; i < N; i++) {
		if (cur_end < locations[i].first) {
			answer += (cur_end - cur_start);
			cur_start = locations[i].first;
			cur_end = locations[i].second;
		}
		else {
			cur_end = max(cur_end, locations[i].second);
		}
	}

	answer += (cur_end - cur_start);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		locations.push_back(make_pair(x, y));

	}

	cout << solution();

	return 0;
}