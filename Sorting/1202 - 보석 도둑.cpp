#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 보석의 개수
K: 보석을 최대 1개만 담을 수 있는 가방의 개수

M[i]: i번째 보석의 무게
V[i]: i번째 보석의 가격

C[i]: i번째 가방이 담을 수 있는 최대 무게

- 변수 제한 사항
 N, K: 1~300,000
 
 M[i], V[i]: 0~1,000,000

 C[i]: 0~100,000,000

- 문제 상황
 각각의 보석의 정보와 가방의 정보가 주어질 때, 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다. 

2. 풀이 계획
 처음에는 보석에 대한 정보를 가격에 대해 정렬하여 활용하는 것을 생각하였으나, 그렇게 할 경우 무게 정보와 정렬 기준이 달라지므로 정렬이 큰 의미를 가지지 못하게 된다.

우선순위 큐에 담아 가격이 최대인 보석을 뽑더라도, 이를 적절한 가방에 넣기 위해서는 넣을 수 있는 가방 중 가장 맞는 가방을 찾아야 하는데, 이 때 보석에 대한 정보는 가격으로, 가방에 대한 정보는 무게 기준으로 정렬되어 있으므로 하나의 보석마다 최악의 경우 모든 가방에 대해서 고려해야 한다. 따라서 최악의 경우 시간 복잡도는 O(NK)로, 활용할 수 없는 수준이 된다.

따라서 두 정보들을 모두 무게라는 같은 기준에 대해 오름차순으로 정렬한다. 그 후 각 가방의 무게에 대해 그 가방에 넣을 수 있는 보석의 가격 정보를 top을 최대값으로 유지하는 우선순위 큐에 집어넣는다.
이 우선순위 큐의 top에 있는 값이 현재의 가방에 넣을 수 있는 가격의 최대값이 되므로, 이 값을 누적하여 더해주면 된다!


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int N, K;

vector<pair<int, int>> infoOfGem; // 보석 
vector<int> C; // 가방 최대무게 저장


long long solution() {
	long long answer = 0; // 보석 가격의 합의 최대값을 저장할 변수
	priority_queue<int> canPut; // top을 현재 가방에 담을 수 있는 보석 중 가장 높은 가격으로 유지하는 우선순위 큐 

	int gemIndex = 0;

	// 모든 가방에 대해 반복
	for (int i = 0; i < K; i++) {
		// 현재 가방에 담을 수 있는 보석 추가
		while (gemIndex < N && infoOfGem[gemIndex].first <= C[i]) {
			canPut.push(infoOfGem[gemIndex++].second);
		} 
		// 현재 가방에 담을 수 있는 보석 중 가격이 가장 비싼 보석 고르기
		if (!canPut.empty()) {
			answer += canPut.top();
			canPut.pop();
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) { 
		int M, V;
		cin >> M >> V;

		infoOfGem.push_back(make_pair(M, V));
	}

	for (int i = 0; i < K; i++) {
		int C_i;
		cin >> C_i;

		C.push_back(C_i);
	}

	sort(infoOfGem.begin(), infoOfGem.end()); // 보석 무게 기준 오름차순 정렬
	sort(C.begin(), C.end()); // 가방 무게 기준 오름차순 정렬

	cout << solution();
}