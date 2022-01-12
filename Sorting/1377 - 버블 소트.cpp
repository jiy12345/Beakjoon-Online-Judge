#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N;
vector<pair<int, int>> A;

long long solution() {
	sort(A.begin(), A.end());

	int answer = 0;

	for (int i = 0; i < N; i++)
		answer = max(answer, A[i].second - i);

	return answer + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		A.push_back(make_pair(temp, i));
	}

	cout << solution();
}
