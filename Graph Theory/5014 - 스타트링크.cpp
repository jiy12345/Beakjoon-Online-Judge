#include<iostream>
#include<string>
#include<queue>
#include<set>
using namespace std;

/*
1. 문제 분석
- 변수
S: 지금 있는 층
G: 가려는 층
F: 가장 높은 층
U: U버튼을 올라갔을 때 한번에 U층씩 올라가게 됨
D: D버튼을 올라갔을 때 한번에 D층씩 올라가게 됨

- 변수 제한 사항
1 ≤ S, G ≤ F ≤ 1000000
0 ≤ U, D ≤ 1000000

건물은 1층부터 시작

- 문제 상황
S 층에서 G층으로 가기 위해 눌러야 하는 버튼 수의 최솟값을 출력한다.

만약 엘리베이터로 이동할 수 없을 때는 "use the stairs"를 출력한다.

만약, U층 위, D층 아래에 층이 없을 떄는 움직이지 않는다.

2. 풀이 계획
걍 bfs

3. 계획 검증

bfs는 그런데 거리상 가까운 노드가 먼저 나온다.

거리가 가까운 것이 회전수가 적다는 것을 보장하는가?
그렇지 않다. 따라서 priority_queue를 사용하여 회전 수에 따라서 정렬되도록 해야할 듯 하다.


*/

#define MAX 1000001

int F, S, G, U, D;
bool isVisited[MAX];
int movement[2];

bool isInRange(int cur_floor) {
	return 1 <= cur_floor && cur_floor <= F;
}

int solution() {
	int answer = -1;

	// 현재 좌표 / 깊이(버튼 누른 횟수)
	queue<pair<int, int>> bfs_queue;
	bfs_queue.push({ S, 0 });
	isVisited[S] = true;

	while (!bfs_queue.empty()) {
		int cur_floor = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second;
		bfs_queue.pop();
		
		if (cur_floor == G) {
			answer = cur_depth;
			break;
		}
		
		for (int i = 0; i < 2; i++) {
			int next_floor = cur_floor + movement[i];
			if (isInRange(next_floor) && isVisited[next_floor] == false) {
				bfs_queue.push({ next_floor, cur_depth + 1 });
				isVisited[next_floor] = true;
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;

	movement[0] = U;
	movement[1] = -D;


	int answer = solution();

	cout << ((answer == -1) ? "use the stairs" : to_string(answer)); 

	return 0;
}
