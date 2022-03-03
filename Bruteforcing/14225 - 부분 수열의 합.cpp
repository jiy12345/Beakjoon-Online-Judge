#include<iostream>
#include<string>

using namespace std;

/*
1. 문제 분석
- 변수
N: 수열의 크기


- 변수 제한 사항
N: 1~20
수열을 이루고 있는 값: 1 ~ 100,000

- 문제 상황
 수열의 합으로 만들 수 없는 최소값을 구하여라!


2. 풀이 계획
 조합 문제라고 볼 수 있을 듯?

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int S[21];
bool canMake[2000001];
int sum, N;

void combination(int x, int sum) {
	canMake[sum] = true;
	if (x == N) return;
	else {
		combination(x + 1, sum);
		combination(x + 1, sum + S[x]);
	}
}

int solution() {
	combination(0, 0);

	int cnt = 1;
	while(canMake[cnt] == true) cnt++;

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	cout << solution();
}