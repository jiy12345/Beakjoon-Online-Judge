#include<iostream>
#include<cstdlib>
using namespace std;

/*
1. 문제 분석
- 변수
N, M 종이의 크기


- 변수 제한 사항
N, M: 1 ~ 100
종이 한 칸에 놓인 정육면체의 수: 1 ~ 100


- 문제 상황
종이의 각 칸에 놓인 정육면체의 수가 주어졌을 때, 도형의 겉넓이를 구하여라

2. 풀이 계획
위와 아래는 N x M으로 정해져 있고, 

4방향의 각 면 또한 가장 넓은 면적: 각 줄의 최대값을 구하여 구해지는 값

그런데 중간에 파인 위치들은 어떻게 계산해야 할까?

일단 먼저 생각해보자.
파인 위치는 어떻게 등장하는가?

일단 높은 위치와 낮은 위치의 차 때문에 발생한다. 즉 각 위치별로 반복하면서 두 높이의 차를 계속 더해가면 될 듯 하다.

최대 10자리

가장 긴 길이 10

따라서 가로 최대 길이
13 x 10 = 130

배열에 받아놓고 출력하면 될 듯 하다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int N, M;
int paper[102][102];

int solution() {
	int answer = 0;

	// 위, 아래면
	answer += 2 * (M * N);

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			answer += abs(paper[i][j] - paper[i][j + 1]);
		}
	}

	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			answer += abs(paper[j][i] - paper[j+ 1][i]);
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> paper[i][j];
		}
	}

	cout << solution();

	return 0;
}