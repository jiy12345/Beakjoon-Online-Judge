#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N; // 강의의 개수

priority_queue<int, vector<int>, greater<int>> endTimes;
vector<pair<int, int>> lectureInfo;

int solution() {
	int answer = 1; // 최소 한개는 써야한다!

	endTimes.push(lectureInfo[0].second);

	for (int i = 1; i < N; i++) {
		// 새 강의실을 배정해야하는 경우
		if (endTimes.top() > lectureInfo[i].first) {
			answer++;
			endTimes.push(lectureInfo[i].second);
		}
		else {
			endTimes.pop();
			endTimes.push(lectureInfo[i].second);
		}
	}

	return answer;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int classNum, startTime, endTime;
		cin >> classNum >> startTime >> endTime;

		lectureInfo.push_back(make_pair(startTime, endTime));
	}

	sort(lectureInfo.begin(), lectureInfo.end());

	cout << solution();

	return 0;
}