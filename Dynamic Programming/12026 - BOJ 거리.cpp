#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 1000

int dp[MAX];

int N;
string road;

char nextChar(char curChar) {
	switch (curChar)
	{
	case 'B':
		return 'O';
	case 'O':
		return 'J';
	case 'J':
		return 'B';
	}
}

int solution() {
	fill(&dp[1], &dp[N], MAX * MAX);

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			// 다음 문자일 때만
			if (road[j] == nextChar(road[i]))
				dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));

	return (dp[N - 1] == MAX * MAX) ? -1 : dp[N - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> road;

	cout << solution();
}
