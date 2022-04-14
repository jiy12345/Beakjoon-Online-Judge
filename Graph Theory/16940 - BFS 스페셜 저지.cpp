#include<iostream>
#include<queue>
#include<set>
using namespace std;

int N;
vector<int> graph[100001];
int visitOrder[100001];
bool isVisited[100001];

int bfs() {
	if (visitOrder[0] != 1) {
		return 0;
	}

	queue<int> bfs_queue;


	bfs_queue.push(1);
	isVisited[1] = true;


	set<int> visitable;
	int idx = 1; // 경로에서 가능한 후보 노드군의 시작 인덱스
	while (!bfs_queue.empty()) {
		int cur_node = bfs_queue.front();
		bfs_queue.pop();

		int sz = 0;
		// 현재 노드로부터 방문 가능한 모든 노드에 대해
		for (int next : graph[cur_node]) {
			// 아직 방문하지 않았을 경우
			if (isVisited[next] == false) {
				// 방문 가능한 후보군에 추가
				visitable.insert(next);
				isVisited[next] = true;
				sz++;
			}
		}

		for (int i = idx; i < idx + sz; i++) {
			// 후보군에 다음 순서의 노드가 없을 경우 만들 수 없는 것
			if (visitable.count(visitOrder[i]) == 0) {
				return 0;
			} // 다음 순서의 노드가 있을 경우 노드 푸시
			else bfs_queue.push(visitOrder[i]);
		}
		idx += sz;
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (int i = 0; i < N; i++) {
		cin >> visitOrder[i];
	}

	cout << bfs();

	return 0;
}
