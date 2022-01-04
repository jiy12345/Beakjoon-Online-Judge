#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석

- 변수
N: 국회의원의 명수

- 변수 제한 사항
N: 1~100,000
국회의원들의 명예점수의 범위: 1~100,000


 - 문제 상황
각 수들을 정렬 후, 각 수와 

2. 풀이 계획


3. 계획 검증


*/

int N;
vector<int> honorPoints;

long long solution() {
	long long answer = 0;

	int maxHonor = 1;

	for (int i = 0; i < N; i++) {
		if (honorPoints[i] >= maxHonor) {
			answer += (honorPoints[i] - maxHonor);
			maxHonor++;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;

		honorPoints.push_back(value);
	}

	sort(honorPoints.begin(), honorPoints.end());

	cout << solution();

	return 0;
}