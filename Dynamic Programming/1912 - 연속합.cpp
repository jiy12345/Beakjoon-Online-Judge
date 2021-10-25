#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
 n: 정수의 개수

- 변수 제한 사항
 N: 1~100,000
 수열이 가진 수의 범위:-1,000~1,000

- 문제 상황
 반드시 한개 이상의 수를 선택한다고 할 때, 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하여라.

2. 풀이 계획
 연속합이라는 것은 이어져 있다는 뜻이고, 따라서 각 위치의 최대값은 현위치의 값 그대로거나, 이전의 연속값과 현재의 값을 합한 것 중 하나이다.
그렇다면 어떤 조건에 따라 두가지 경우가 달라지는 걸까?
이전의 연속값이 음수라면 현 위치의 값만 사용하는 것이 더 크게 되고, 양수라면 합하는 것이 더 크게 된다. 따라서 식으로 나타내면 다음과 같다.
이러한 과정을 거치게 되면 각 위치에서는 연속합의 최대값만 유지하므로, 다음항의 최대값을 계산하는데 문제없이 사용할 수 있다!


 따라서 자세한 계획을 짜보면 다음과 같다.

1. 1차원 배열에 전체 삼각형을 입력받는다.
2. 삼각형의 크기만큼 반복문을 돌리며, 각 층의 최대값들을 구한다.
3. 삼각형의 마지막 층에 해당하는 부분에서 가장 큰 값을 찾는다.

3. 계획 검증
500 * 501 / 2 = 122,250

501000
0.501
*/


int n;

int sequence[100000];
int dp[100000];

int solution() {
	
	dp[0] = sequence[0]; // 가장 첫 위치는 자기 자신밖에 없으므로

	int answer = dp[0];

	for (int i = 1; i < n; i++) {
		if (dp[i - 1] < 0) {
			dp[i] = sequence[i];
		}
		else {
			dp[i] = sequence[i] + dp[i - 1];
		}
		answer = max(dp[i], answer);
	}
	return answer;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	cout << solution();
}