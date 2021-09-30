#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;

int N; // 총 인원 수
int answer = INT_MAX; // 답으로 출력할 최소값을 저장할 변수
int status[20][20]; // 사람 조합에 따른 팀의 능력치에 더해질 값을 저장할 배열
// 각 인원이 어떤 팀에 속할지 나타낼 배열
bool team[20] = { false, }; // true: 스타트 팀 / false: 링크 팀

// start_team_cnt: 현재까지 스타트 팀에 뽑힌 인원 수
// cur_index: 현재 인덱스
void solution(int start_team_cnt, int cur_index) {

	// 기저사례: 스타트 팀에 N/2 사람이 뽑혔을 경우
	if (start_team_cnt == N/2) {
		int start_team_status_sum = 0; // 스타트 팀 능력치 합
		int link_team_status_sum = 0; // 링크 팀 능력치 합
		
		bool is_start_team; // true: 스타트 팀 / false: 링크 팀

		// 각 팀의 능력치 계산
		for (int i = 0; i < N; i++) {
			is_start_team = team[i]; // 한 사람 뽑기
			for (int j = i + 1; j < N; j++) { // 뽑아 놓은 사람과 조합될 사람 뽑기 
				if (is_start_team == team[j]) { // 두 사람의 팀이 같았을 경우에만 동작
					if (is_start_team) { // 두 사람이 같이 스타트 팀일 경우
						start_team_status_sum += (status[i][j] + status[j][i]);
					}
					else { // 두 사람이 같이 링크 팀일 경우
						link_team_status_sum += (status[i][j] + status[j][i]);
					}
				}
			}
		}

		// 두 팀의 능력치 차 계산
		int diff = abs(start_team_status_sum - link_team_status_sum);

		answer = min(answer, diff); // 두 수중 더 작은 수로 갱신

		return;
	}

	for (int i = cur_index; i < N - (N/2 - start_team_cnt); i++){
		team[i] = true; // 스타트 팀에 한명 뽑은 것을 표현
		solution(start_team_cnt + 1, i + 1);
		team[i] = false; // 함수 마치고 왔으면 현재 단계에서는 안뽑은 상태 유지
	}

}

int main() {

	string temp;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> status[i][j];
		}
	}

	solution(0, 0);

	cout << answer;
}
