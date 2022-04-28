#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 행성의 수
x, y, z: 행성이 위치한 3차원 좌표

- 변수 제한 사항
N: 1 ~ 100,000
x, y, z: -1,000,000,000 ~ 1,000,000,000

한 위치에 행성이 두 개 이상 있는 경우는 없다.

- 문제 상황
 N개의 행성의 위치가 주어졌을 때, 터널을 총 N - 1개 건설하여 모든 행성이 서로 연결되게 하는데 필요한 최소 비용을 구하는 프로그램을 작성하라

두 행성 A(xA, yA, zA)와 B(xB, yB, zB)를
터널로 연결할 때 드는 비용은 min(|xA-xB|, |yA-yB|, |zA-zB|)이다.

2. 풀이 계획
 모든 행성간의 거리를 구하면 편하기는 하겠지만, 그렇게 할 경우

 4 x 100,000 x 100,000 = 40,000,000,000바이트 = 40기가 바이트가 나오므로 메모리가 초과될 것이다.

 또한 시간 복잡도도 높아 시간 내에 끝내지 못 할 것이다.

 그렇다면 어떻게 해야할까?



 거리 계산 식을 살펴보자

 min(|xA-xB|, |yA-yB|, |zA-zB|)


 크루스칼 알고리즘을 적용하기 위해서는 각 상황에서의 최소값을 가진 간선을 구해야 한다.

 각 상황에서 최소비용을 가진 간선을 선택하기 위해서는 어떤 간선들을 계산해놔야 할까?

 일단 각 위치에서 연결될 수 있는 정점과의 연결 중 가장 적은 비용이 드는 간선을 선택해야 하는 것은 맞다.

 그런데 그 간선을 선택하려 할 때 이미 연결되어 있는 정점과의 연결이면 선택하면 안되므로, 넘어가야 한다.

 아직 전체 그룹과 연결되지 않은 노드는 어떤 노드와도 사이클을 이루지 않기 때문에 가장 최소 간선을 선택하면 된다.

 따라서 각 노드에서 가장 비용이 적은 간선을 저장하는 것이

3. 계획 검증
*/

#define MAX 100000

int N;
// 각 좌표별로 정렬하여 저장
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;

// 가중치, 출발 행성, 도착 행성 순으로 저장
vector<vector<int>> possibleLinks;
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
		possibleLinks.push_back({ abs(X[i].first - X[i + 1].first), X[i].second, X[i + 1].second });
		possibleLinks.push_back({ abs(Y[i].first - Y[i + 1].first), Y[i].second, Y[i + 1].second });
		possibleLinks.push_back({ abs(Z[i].first - Z[i + 1].first), Z[i].second, Z[i + 1].second });
	}

	sort(possibleLinks.begin(), possibleLinks.end());
}

int kruskal() {
	int answer = 0;

	for (int i = 0; i < N; i++) {
		Parent[i] = i;
	}

	for (vector<int> cur_link : possibleLinks) {
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