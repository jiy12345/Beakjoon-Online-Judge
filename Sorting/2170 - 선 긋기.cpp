#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<pair<int, int>> locations;

int solution() {
	int answer = 0;

	sort(locations.begin(), locations.end());

	int cur_start = locations[0].first;
	int cur_end = locations[0].second;

	for (int i = 1; i < N; i++) {
		if (cur_end < locations[i].first) {
			answer += (cur_end - cur_start);
			cur_start = locations[i].first;
			cur_end = locations[i].second;
		}
		else {
			cur_end = max(cur_end, locations[i].second);
		}
	}

	answer += (cur_end - cur_start);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		locations.push_back(make_pair(x, y));

	}

	cout << solution();

	return 0;
}
