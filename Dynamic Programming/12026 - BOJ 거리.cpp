#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
 N: 보도 블록의 개수

- 변수 제한 사항
 N: 1 ~ 1,000

 BOJ거리의 각 보도블록에는 B, O, J 중에 하나가 쓰여 있다
 1번은 반드시 B이다

- 문제 상황
스타트가 현재 있는 곳이 i번이라면, i+1번부터 N번까지로 점프를 할 수 있고, 
한 번 k칸 만큼 점프를 하는데 필요한 에너지의 양은 k*k이라고 할 때,
스타트가 링크를 만나는데 필요한 에너지 양의 최솟값을 구하여라.


2. 풀이 계획


1. 방문이 가능한 위치에 대해(저장된 에너지 양이 0이 아닌 위치에 대해) 다음을 반복한다.
 1) 현 위치의 다음위치부터 끝 위치까지갈 수 있는 위치까지 총 필요한 에너지양을 다음과 같은 식에 따라 구한다.
  다음 위치의 에너지 양 = 현재 위치까지의 에너지 양 + k * k
 2) 1)에서 구한 값이 현재 저장되어 있는 값보다 작을 때만 갱신하고,그렇지 않으면 갱신하지 않는다.

3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

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