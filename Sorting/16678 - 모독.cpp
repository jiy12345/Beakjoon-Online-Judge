#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> honorPoints;

long long solution() {
	long long answer = 0;

	int maxHonor = 1;

	for (int i = 0; i < N; i++) {
		if (honorPoints[i] >= maxHonor) {
			answer += (honorPoints[i] - maxHonor);
			maxHonor++;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;

		honorPoints.push_back(value);
	}

	sort(honorPoints.begin(), honorPoints.end());

	cout << solution();

	return 0;
}
