#include<iostream>
#include<vector>
using namespace std;

/*
1. 문제 분석
- 변수
N: 사람의 수
M: 친구 관계의 수

- 변수 제한 사항
N: 5~2,000
M: 5~2,000

- 문제 상황
 N명의 사람간의 친구 관계 M개가 주어질 때, 모든 사람이 친구관계로 연결되어있는지를 판단하여라.

2. 풀이 계획

모든 노드를 한번씩 탐색하는 경로가 있는지 탐색하는 문제이다.

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

vector<int> friends[2000];
bool isVisited[2000];

bool solution(int numSelected, int curPickedNode) {
	if (numSelected == 5) {
		return true;
	}

	for (int i = 0; i < friends[curPickedNode].size(); i++) {
		int curFriend = friends[curPickedNode][i];
		if (isVisited[curFriend] == false) {
			isVisited[curFriend] = true;

			if (solution(numSelected + 1, curFriend))
				return true;

			isVisited[curFriend] = false;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		isVisited[i] = true;
		if (solution(1, i)) {
			cout << 1; 
			return 0;
		}
		isVisited[i] = false;
	}

	cout << 0;

	return 0;
}