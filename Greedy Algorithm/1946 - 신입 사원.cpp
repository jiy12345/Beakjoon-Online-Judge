#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

/*
 1. 문제 분석

- 변수

 T: 테스트 케이스의 개수
 N: 지원자의 숫자
​

- 변수, 값에 대한 제한
 T: 1~20
 N:​ 1~100,000

- 문제 상황
 지원자들의 서류 성적과 면접 성적이 주어질 때, 
 다른 모든 지원자와 비교했을 때 서류 심사 성적과 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 사람을 선발한다고 한다.

 그렇다면 

2. 풀이 계획
일단 서류 심사 성적 기준으로 정렬한 뒤, 앞에서부터 하나씩 보며 현재 합격자 중 최하 면접 순위 값을 저장해놓고, 그 순위보다 낮은 사람은 뽑지 않으면 될 듯 하다!


3. 계획 검증


*/

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