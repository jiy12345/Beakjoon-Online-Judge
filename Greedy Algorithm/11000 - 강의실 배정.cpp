#include<iostream>
#include<queue>
using namespace std;

int N;
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> schedule;
priority_queue <int, vector<int>, greater<int>> endTimes;

int solution() {
	int curEndTime = 0;

	while(!schedule.empty()) {

		if (endTimes.empty()) {
			endTimes.push(schedule.top().second);
		}
		else {
			if (schedule.top().first >= endTimes.top()) {
				endTimes.pop();
				endTimes.push(schedule.top().second);
			}
			else {
				endTimes.push(schedule.top().second);
			}
		}
		schedule.pop();
	}

	return endTimes.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int S;
		int T;
		cin >> S >> T;

		schedule.push(make_pair(S, T));
	}

	cout << solution();

	return 0;
}
