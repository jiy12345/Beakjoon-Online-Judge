#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
풀이 1과 다르게 vector에 입력 받은 후 정렬하는 방식을 선택하였다.
사용한 메모리: 32156KB	
걸린 시간: 172ms
	
priority_queue를 사용하였을 때보다 확실히 빠른 속도를 보인 것을 확인할 수 있다.
따라서 이 문제와 같이 전체 자료에 모두 접근해야 하는 경우에는 priority_queue보다는 
vector에 저장 후 정렬하는 것이 조금 더 바람직할 것 같다!
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
