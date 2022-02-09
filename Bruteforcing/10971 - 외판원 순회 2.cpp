#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
N: 도시의 개수
W[i][j]: 도시 i에서 j로 가는 비용

- 변수 제한 사항
N: 2~8
W[i][j]: 1~1,000,000 / 갈 수 없는 경우 0이 주어진다!

- 문제 상황
각 도시간에 이동하는데 드는 비용은 행렬 W[i][j]형태로 주어질 때,

 N개의 도시를 한번씩 모두 거쳐 원래 도시로 돌아오는 순회 여행 경로 중 가장 적은 비용을 들이는 경로의 비용, 즉 최소값으 구하라.

2. 풀이 계획

 순서가 상관있는 배치이므로, 순열 문제이다.
  => 따라서 이미 지나온 곳인지에 대한 표시가 필요하다.

 순회이므로, 임의의 출발점을 잡아서 가면 될 듯 하다.
  => 어차피 다른 곳에서 출발한 경로 또한 같은 순서로 이루어진 순회 경로에 의해 고려될 것이므로!
 

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int N;
int W[10][10];  // 입력받은 수열 저장
bool isVisited[10]; // 방문한 곳인지 체크

int permutation(int curCity, int curCost, int curSize) {
	int minNum = 10 * 1000000;
	if (curSize == N) { // 출발점을 제외하고 한번씩 방문한 경우
		
		// 원래 도시로 돌아가는 경로가 있을 경우에만 고려되도록 함
		if (W[curCity][0]) {
			minNum = curCost + W[curCity][0];
		}
		return minNum;
	}

	for (int i = 0; i < N; i++) {
		// 방문하지 않았고 경로가 있는 경우에만 탐색 진행
		if (isVisited[i] == false && W[curCity][i] != 0) {
			isVisited[i] = true;
			minNum = min(minNum, permutation(i, curCost+ W[curCity][i], curSize + 1));
			isVisited[i] = false;
		}
	}

	return minNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	// 순회 경로이므로, 출발점은 한 곳으로 고정하여도 모든 경우를 고려할 수 있음!
	isVisited[0] = true;
	cout << permutation(0, 0, 1);
}