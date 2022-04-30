#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 1001

int N, M, K;

// 가중치, 출발 행성, 도착 행성 순으로 저장
vector<vector<int>> cables;
int Parent[MAX];

bool isPowerStation[MAX];


int findParent(int x) {
	if (Parent[x] == x) return x;
	else return Parent[x] = findParent(Parent[x]);
}

void Union(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x != y) {
		// 각각의 부모가 0일 경우 나머지의 부모도 0으로 통일해주기!
		if (x == 0) Parent[y] = 0;
		else if (y == 0) Parent[x] = 0;
		else Parent[y] = x;
	}
}

bool isSameParent(int x, int y) {
	return findParent(x) == findParent(y);
}


int kruskal() {
	int answer = 0;

	for (int i = 0; i <= N; i++) {
		Parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		vector<int> cur_link(cables[i]);
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

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int powerStation;
		cin >> powerStation;
		isPowerStation[powerStation] = true;;
	}

	
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		// 발전소가 건설된 도시는 모두 0으로 표시
		if(isPowerStation[u]) u = 0;
		if(isPowerStation[v]) v = 0;

		cables.push_back({ w, u, v });
	}

	sort(cables.begin(), cables.end());

	cout << kruskal();
}
