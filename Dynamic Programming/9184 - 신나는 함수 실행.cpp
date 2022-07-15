#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
a, b, c: 주어지는 정수

- 변수 제한 사항
 a, b, c: -50 ~ 50;

- 문제 상황
 입력으로 주어진 a, b, c에 대해 w(a, b, c)를 출력한다.

2. 풀이 계획
w(a, b, c) 함수를 그대로 구현 후 dp로 배열에 저장만 하면 될 듯 하다!

3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

int a, b, c;

int dp[20][20][20];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)	return 1;	
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (dp[a][b][c] != 0)			return dp[a][b][c];
	
	if (a < b && b < c) {
		dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		int result = w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
	}
}