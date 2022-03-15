#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
A, B, C: 각 그룹에 속한 돌의 개수

 - 변수 제한 사항
A, B, C: 1 ~ 500

- 문제 상황

 돌을 다음과 같은 단계에 따라 움직여

 크기가 같지 않은 두 그룹을 고른다. 그 다음, 돌의 개수가 작은 쪽을 X, 큰 쪽을 Y라고 정한다. 그 다음, X에 있는 돌의 개수를 X+X개로, Y에 있는 돌의 개수를 Y-X개로 만든다.

2. 풀이 계획
 제한이 딱히 없고, 돌을 같은 개수로 만들 수 있는지 여부만 따지는 것이므로,

 어떻게 끝날지 여부를 판단하는 것이 가장 중요하다.

 일단 아래로 갈 때는 한 그룹의 개수가 0이 된다면 더 이상 움직일 수 없으므로 거기서 끝내야 한다.

 또한 위로 갈 때는 가장 큰 수가 될 수 있을 때가 500, 499일 떄 이므로, 1000이상으로는 절대 갈 수 없다.

 따라서 1000 크기의 3차원 배열에 방문 표시를 진행하고, 찾으면 1, 못찾고 종료하면 0을 출력하면 될 듯 하다.

 그런데 약간 걱정되는 것은 시간복잡도와 공간 복잡도 정도?

 연산을 자세히 보면, 한번 연산을 했을 때 X를 더하고 X를 뺀 것이므로 전체의 합(A + B + C)는 바뀌지 않는 것을 알 수 있다.

 두 수만 가지고도 3개의 돌 그룹을 나타낼 수 있다!


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/


int A, B, C;
bool isVisited[1500][1500];

inline void visit(int A, int B, int C) {
	isVisited[A][B] = true;
	isVisited[A][C] = true;
	isVisited[B][A] = true;
	isVisited[B][C] = true;
	isVisited[C][A] = true;
	isVisited[C][B] = true;
}

int solution() {
	int sum = A + B + C;

	if (sum % 3 != 0) {
		return 0;
	}

	int answer = 0;

	queue<vector<int>> bfs_queue;

	int first_A = max({ A, B, C });
	int first_B = min({ A, B, C });

	bfs_queue.push({ first_A, first_B });
	isVisited[first_A][first_B] = true;;

	while (!bfs_queue.empty()) {
		cout << "queue size: " << bfs_queue.size() << endl;
		int cur_A = bfs_queue.front()[0];
		int cur_B = bfs_queue.front()[1];
		bfs_queue.pop();

		int cur_C = sum - (cur_A + cur_B);

		if (cur_A == cur_B && cur_B == cur_C) {
			return 1;
		}

		vector<pair<int, int>> combinations = { {cur_A, cur_B}, {cur_B, cur_C}, {cur_A, cur_C} };
		
		for (pair<int, int> combination : combinations) {
			if (combination.first > combination.second) {
				combination.first -= combination.second;
				combination.second += combination.second;
			}
			else if (combination.first < combination.second) {
				combination.second -= combination.first;
				combination.first += combination.first;
			}
			else continue;

			int next_A = combination.first;
			int next_B = combination.second;
			int next_C = sum - (next_A + next_B);

			if (isVisited[next_A][next_B] == false) {
				visit(next_A, next_B, next_C);
				bfs_queue.push({ next_A, next_B });
			}
		}

	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> C;

	cout << solution();

	return 0;
}
