#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 도시의 개수
M: 케이블의 수
K: 발전소의 개수

- 변수 제한 사항
N: 1 ~ 1,000
M: 1 ~ 100,000


- 문제 상황
 발전소가 존재하는 도시가 있으며,
 케이블이 연결되어 있는 도시에는 반드시 발전소가 하나만 존재해야 한다.

2. 풀이 계획
각 도시는 반드시 발전소가 있는 도시와 연결되어야 한다.

그렇다면 어떻게 해야 할까?

원래 크루스칼 알고리즘에서라면 기준 없이 최소 비용을 가진 간선을 선택하면 되지만, 

지금은 그렇지 않다.

도시별로 하나의 발전소만 연결될 수 있도록 하는 연결을 진행하여야 한다.

정렬한 상태에서 하나씩 뽑을 때 조건을 준다면 처리할 수 있을까?

조건이리면 발전소와 연결되도록 하는 연결인지?

그런데 이런식으로 체크하면 당장은 발전소와 연결이 되지 않더라도 나중에 다른 간선을 통해 연결되도록 하는 연결을 선택할 수 없다.

그렇다면 이러한 간선을 다른 곳에 저장해뒀다가 다시 체크하는 것은?
 => 최악의 경우 N^2이 나올것이기 때문에 안될 듯 하다.

같은 부모로 보고, 

3. 계획 검증
*/

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