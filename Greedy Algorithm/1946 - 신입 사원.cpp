#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int T, N;

int solution(int N, vector<pair<int,int>>test_result) {
	int answer = 0;

	// 현재 면접 커트라인
	int cur_min_ranking = N;

	sort(test_result.begin(), test_result.end());
	
	for (int i = 0;i < N;i++) {
		// 면접 성적이 높았을 때만
		if (test_result[i].second <= cur_min_ranking) {
			answer++; // 선발
			// 면접 커트라인 갱신
			cur_min_ranking = test_result[i].second;
		}
	}
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0;i < T;i++) {
		
		cin >> N;

		vector<pair<int, int>>test_result;

		for (int i = 0;i < N;i++) {
			int ranking1, ranking2;
			cin >> ranking1 >> ranking2;

			test_result.push_back(make_pair(ranking1, ranking2));
		}

		cout << solution(N, test_result) << '\n';
	}

	return 0;
}
