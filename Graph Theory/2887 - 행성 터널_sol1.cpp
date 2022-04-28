#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
풀이 2와 다르게 priority_queue를 사용하였다.
사용한 메모리: 32156KB	
걸린 시간: 268ms
	
접근 자체는 정렬과 시간 복잡도가 같을테지만, 삭제하는 과정이 추가되어서 그런지 정렬보다는 오래 걸렸다.
*/

#define MAX 100000

int N;
// 각 좌표별로 정렬하여 저장
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
// 가중치, 출발 행성, 도착 행성 순으로 저장
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> possibleLinks;
int Parent[MAX];


int findParent(int x) {
	if (Parent[x] == x) return x;
	else return Parent[x] = findParent(Parent[x]);
}

void Union(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x != y) Parent[y] = x;
}

bool isSameParent(int x, int y) {
	return findParent(x) == findParent(y);
}

void getPossibleLinks() {
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N - 1; i++) {
		//                      발생하는 비용                      출발 행성    도착 행성
		possibleLinks.push({ abs(X[i].first - X[i + 1].first), X[i].second, X[i + 1].second });
		possibleLinks.push({ abs(Y[i].first - Y[i + 1].first), Y[i].second, Y[i + 1].second });
		possibleLinks.push({ abs(Z[i].first - Z[i + 1].first), Z[i].second, Z[i + 1].second });
	}
}

int kruskal() {
	int answer = 0;

	for (int i = 0; i < N; i++) {
		Parent[i] = i;
	}

	while (!possibleLinks.empty()) {
		vector<int> cur_link(possibleLinks.top());
		possibleLinks.pop();
		if (isSameParent(cur_link[1], cur_link[2]) == false) {
			Union(cur_link[1], cur_link[2]);
			answer += cur_link[0];
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		// 각 좌표별로 저장
		X.push_back({ x, i });
		Y.push_back({ y, i });
		Z.push_back({ z, i });
	}

	getPossibleLinks();

	cout << kruskal();
}
