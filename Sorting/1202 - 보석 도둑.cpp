#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

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
