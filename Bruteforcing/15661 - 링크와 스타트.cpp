#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

/*
1. 문제 분석
- 변수
N: 모인 인원 수

- 변수 제한 사항
N: 4~20
능력치: 1~100

- 문제 상황
 2명이 조합되었을 때 팀에 더해지는 능력이 주어졌을 때, 스타트 팀과 링크 팀의 능력치 차이를 최소화 하도록 팀원을 뽑을 때의 값을 구하여라

2. 풀이 계획
 문제를 두번의 조합이 등장한다고 볼 수 있다.

 일단 팀을 뽑는 과정에서의 조합 => 이 문제는 한 팀을 뽑으면 한팀이 저절로 결정되므로, N명의 사람중 순서에 상관 없이 k(1~N-1)명의 사람을 뽑는 문제가 된다.

 사람을 뽑은 후에는 뽑은 k명의 사람 중 2명씩을 뽑아 그 조합이 주는 능력치의 합을 더해가며 팀의 총 능력치의 합을 구하면 된다!


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

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

		//cout << "startTeam: ";
		//for (int i = 0; i < startTeam.size(); i++) {
		//	cout << startTeam[i] << " ";
		//}
		//cout << endl;
		//cout << "startTeamAbility: " << calculateTeamAbility(startTeam) << endl;

		//cout << "linkTeam: ";
		//for (int i = 0; i < linkTeam.size(); i++) {
		//	cout << linkTeam[i] << " ";
		//}
		//cout << endl;
		//cout << "linkTeamAbility: " << calculateTeamAbility(linkTeam) << endl;

		int diff = abs(calculateTeamAbility(startTeam) - calculateTeamAbility(linkTeam));

		// cout << "diff: " << diff << endl;

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