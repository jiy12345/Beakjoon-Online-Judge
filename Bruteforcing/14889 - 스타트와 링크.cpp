#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;

/*
1. 문제 분석

- 변수
N: 축구를 위해 모인 사람의 수
S[i][j], S[j][i]: i번 사람과 j번 사람이 같은 팀에 속했을 때 팀에 더해지는 능력치

- 변수 제한 사항
4 <= N <= 20, N은 짝수

 - 문제 상황
 N명의 사람을 N/2명으로 나눴을 때, 두 팀간의 능력치 차가 최소값을 출력한다!

2. 풀이 계획
 두 팀의 인원수를 합하면 전체 인원이 되므로, 한팀을 모두 뽑으면 다른 팀에 인원도 확정되게 된다.
따라서 N명 중 N/2명을 뽑는 조합 문제라고 볼 수 있다.



1. 2차원 배열에 능력치 정보를 입력받는다.
2. 재귀함수를 구현하여 스타트 팀을 뽑을 수 있는 모든 경우의 수를 구한다.
 - 부분 문제: 팀원 한명 선택
 - 기저 사례: 스타트 팀에 N/2명을 뽑았을 때
 - 같은 단계에서의 반복: 현 위치 ~ 끝에서 뽑아야할 개수 뺀 것

3. 기저사례에 도달했을 경우 이중 반복문을 돌려 각각 팀의 능력치의 합을 구한 후, 그 둘간의 차를 구한다.
4. 현재 저장된 최소값과 비교하여 현재 값이 더 작다면 값을 갱신한다.


3. 계획 검증


*/

int N;
int answer = INT_MAX;
int status[20][20];
bool team[20] = { false, }; // true: 스타트 팀 / false: 링크 팀

void solution(int start_team_cnt, int cur_index) {

	// 기저사례
	if (start_team_cnt == N/2) {
		int start_team_status_sum = 0;
		int link_team_status_sum = 0;
		
		bool is_start_team; // true: 스타트 팀 / false: 링크 팀

		// 각 팀의 능력치 계산
		for (int i = 0; i < N; i++) {
			is_start_team = team[i];
			for (int j = i + 1; j < N; j++) {
				if (is_start_team == team[j]) {
					if (is_start_team) {
						start_team_status_sum += (status[i][j] + status[j][i]);
					}
					else {
						link_team_status_sum += (status[i][j] + status[j][i]);
					}
				}
			}
		}

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