#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

/*
1. ���� �м�
- ����
N: ���� �ο� ��

- ���� ���� ����
N: 4~20
�ɷ�ġ: 1~100

- ���� ��Ȳ
 2���� ���յǾ��� �� ���� �������� �ɷ��� �־����� ��, ��ŸƮ ���� ��ũ ���� �ɷ�ġ ���̸� �ּ�ȭ �ϵ��� ������ ���� ���� ���� ���Ͽ���

2. Ǯ�� ��ȹ
 ������ �ι��� ������ �����Ѵٰ� �� �� �ִ�.

 �ϴ� ���� �̴� ���������� ���� => �� ������ �� ���� ������ ������ ������ �����ǹǷ�, N���� ����� ������ ��� ���� k(1~N-1)���� ����� �̴� ������ �ȴ�.

 ����� ���� �Ŀ��� ���� k���� ��� �� 2���� �̾� �� ������ �ִ� �ɷ�ġ�� ���� ���ذ��� ���� �� �ɷ�ġ�� ���� ���ϸ� �ȴ�!


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

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

// ��ŸƮ ���� i������ �Ͽ��� ���� �� ���� �ɷ�ġ ���� �ּҰ��� ��ȯ�� �Լ�
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

	// ��ŸƮ ���� ��� �ο����� ���� ��Ȳ ���
	// ��ŸƮ ���� �������̵� ��ũ���� �������̵� �� �� ���� �̸��� �ٲ���� �������� ���ٸ�
	// �� ������ �ɷ�ġ ���� �����Ƿ� ��ŸƮ���� �������� ��ü �ο��� �ݸ�ŭ�� �̴� �͸� ����ϸ� �ȴ�!
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