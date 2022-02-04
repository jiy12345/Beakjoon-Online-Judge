#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

#define STARTTEAM true
#define LINKTEAM false

int N;
int ability[20][20];
bool startOrLink[20]; // false: link / true: start

int calculateTeamAbility(vector<int>team) {
	int teamAbility = 0;

	for (int i = 0; i < team.size(); i++) {
		for (int j = i + 1; j < team.size(); j++) {
			teamAbility += ability[team[i]][team[j]] + ability[team[j]][team[i]];
		}
	}

	return teamAbility;
}

// 스타트 팀을 i명으로 하였을 때의 두 팀의 능력치 차의 최소값을 반환할 함수
int pickStartTeam(int k, int index, int startTeamNum) {
	int minDiff = 100 * 400;
	
	if (startTeamNum == k) {
		vector<int>startTeam;
		vector<int>linkTeam;

		for (int i = 0; i < N; i++) {
			if (startOrLink[i] == STARTTEAM) {
				startTeam.push_back(i);
			}
			else {
				linkTeam.push_back(i);
			}
		}

		int diff = abs(calculateTeamAbility(startTeam) - calculateTeamAbility(linkTeam));

		return diff;
	}

	for (int i = index; i < N; i++) {
		startOrLink[i] = STARTTEAM;
		minDiff = min(minDiff, pickStartTeam(k, i + 1, startTeamNum + 1));
		startOrLink[i] = LINKTEAM;
	}
	
	return minDiff;
}

int solution() {
	int minDiff = 100 * 400;

	// 스타트 팀의 모든 인원수일 때의 상황 고려
	// 스타트 팀의 구성원이든 링크팀이 구성원이든 각 두 팀의 이름이 바뀌더라도 구성원이 같다면
	// 두 팀간의 능력치 차는 같으므로 스타트팀의 구성원을 전체 인원의 반만큼만 뽑는 것만 고려하면 된다!
	for (int i = 1; i <= N/2; i++) {
		minDiff = min(minDiff, pickStartTeam(i, 0, 0));
	}

	return minDiff;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ability[i][j];
		}
	}

	cout << solution();	
}
