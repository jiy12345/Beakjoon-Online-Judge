#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// vector의 정렬에 사용될 비교함수
// 끝나는 시간이 빠른 것이 먼저 오며, 끝나는 시간이 같을 경우 시작 시간이 빠른 것이 먼저 옴!
bool compare(vector<int> a, vector<int> b) {
	if (a[1] == b[1]) {
		return a[0] < b[0];
	}
	else {
		return a[1] < b[1];
	}
}

int conference_scheduling(int N, vector<vector<int>>conferences) {

	sort(conferences.begin(), conferences.end(), compare);
	
	int max_num = 0;
	int current_end_time = 0; // 가장 최근에 선택된 회의의 종료시간

	for (int i = 0; i < conferences.size(); i++) {
		int begin_time = conferences[i][0];
		int end_time = conferences[i][1];
		
		// 넣을 수 있는 회의를 발견하였을 경우
		if (current_end_time <= begin_time) {
			current_end_time = end_time;
			max_num++;
		}
	}

	return max_num;
}

int main() {
	int N; // 열리는 총 회의의 개수

	cin >> N;

	// 원하는 크기대로 벡터 만들기
	vector<vector<int>> conferences(N, vector<int>(2, 0));

	for (int i = 0; i < N; ++i) {
		cin >> conferences[i][0] >> conferences[i][1];
	}

	int max_num = conference_scheduling(N, conferences);

	cout << max_num;

	return 0;
}
