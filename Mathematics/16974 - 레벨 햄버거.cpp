#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
N: 버거의 레벨
X: 아래에 있는 X장을 먹기

- 변수 제한 사항
N: 1 ~ 50

- 문제 상황
 먹은 패티의 수 구하기
 
2. 풀이 계획
 


3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

#define MAX 50

int N;
long long X;
long long burger[51];
long long patty[51];
long long answer;

void getNum(int level, long long lower) {
	if (lower == 0 ) {
		return;
	}
	else if (level == 0) {
		answer++;
		return;
	}

	lower--;
	if (lower == burger[level - 1]) {
		answer += patty[level - 1];
		lower -= (burger[level - 1]);
		getNum(level - 1, lower);
	}
	else if (lower < burger[level - 1]) {
		getNum(level - 1, lower);
	}
	else if (lower > burger[level - 1]) {
		answer += patty[level - 1] + 1;
		lower -= (burger[level - 1] + 1);
		getNum(level - 1, lower);
	}
}

long long solution() {
	burger[0] = 1; patty[0] = 1;
	for (int i = 1; i <= 50; i++) {
		burger[i] = 2 * burger[i - 1] + 3;
		patty[i] = 2 * patty[i - 1] + 1;
	}

	getNum(N, X);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> X;

	cout << solution();
}