#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int N, K;

vector<int> location;
vector<int> Distance;

int solution() {
	int answer = 0;

	
	for (int i = 1; i < N; i++) {
		Distance.push_back(location[i] - location[i - 1]);
	}

	sort(Distance.begin(), Distance.end());

	if (N >= K) {
		answer = accumulate(Distance.begin(), Distance.begin() + (N - K), 0);
	}
	else {
		answer = 0;
	}

	return answer;
}

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		location.push_back(temp);
	}

	sort(location.begin(), location.end());

	cout << solution();

	return 0;
}