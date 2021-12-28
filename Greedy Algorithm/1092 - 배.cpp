#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> weights;
vector<int> cranes;

int solution() {

	int minutes = 0;

	if (weights[N - 1] > cranes[M - 1]) {
		return -1;
	}

	while (!weights.empty()&&!cranes.empty()) {
		minutes++;

		int weightsIndex = weights.size() - 1;
		int cranesIndex = cranes.size() - 1;

		int cnt = 1;
		while (cranesIndex != -1) {
			if (weights[weightsIndex] <= cranes[cranesIndex]) {
				weights.erase(weights.begin() + weightsIndex);
				weightsIndex--;
				cranesIndex--;
			}
			else {
				weightsIndex--;
			}

			if (weightsIndex == -1) {
				break;
			}
			cnt ++;

		}
	}

	return minutes;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int crane;
		cin >> crane;

		cranes.push_back(crane);
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		int weight;
		cin >> weight;

		weights.push_back(weight);

	}

	sort(weights.begin(), weights.end());
	sort(cranes.begin(), cranes.end());

	cout << solution();

	return 0;
}
