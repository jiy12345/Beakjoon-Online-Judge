#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;

/*
1. ���� �м�

- ����
N: �౸�� ���� ���� ����� ��
S[i][j], S[j][i]: i�� ����� j�� ����� ���� ���� ������ �� ���� �������� �ɷ�ġ

- ���� ���� ����
4 <= N <= 20, N�� ¦��

 - ���� ��Ȳ
 N���� ����� N/2������ ������ ��, �� ������ �ɷ�ġ ���� �ּҰ��� ����Ѵ�!

2. Ǯ�� ��ȹ
 �� ���� �ο����� ���ϸ� ��ü �ο��� �ǹǷ�, ������ ��� ������ �ٸ� ���� �ο��� Ȯ���ǰ� �ȴ�.
���� N�� �� N/2���� �̴� ���� ������� �� �� �ִ�.



1. 2���� �迭�� �ɷ�ġ ������ �Է¹޴´�.
2. ����Լ��� �����Ͽ� ��ŸƮ ���� ���� �� �ִ� ��� ����� ���� ���Ѵ�.
 - �κ� ����: ���� �Ѹ� ����
 - ���� ���: ��ŸƮ ���� N/2���� �̾��� ��
 - ���� �ܰ迡���� �ݺ�: �� ��ġ ~ ������ �̾ƾ��� ���� �� ��

3. ������ʿ� �������� ��� ���� �ݺ����� ���� ���� ���� �ɷ�ġ�� ���� ���� ��, �� �Ѱ��� ���� ���Ѵ�.
4. ���� ����� �ּҰ��� ���Ͽ� ���� ���� �� �۴ٸ� ���� �����Ѵ�.


3. ��ȹ ����


*/

int N;
int answer = INT_MAX;
int status[20][20];
bool team[20] = { false, }; // true: ��ŸƮ �� / false: ��ũ ��

void solution(int start_team_cnt, int cur_index) {

	// �������
	if (start_team_cnt == N/2) {
		int start_team_status_sum = 0;
		int link_team_status_sum = 0;
		
		bool is_start_team; // true: ��ŸƮ �� / false: ��ũ ��

		// �� ���� �ɷ�ġ ���
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

		answer = min(answer, diff); // �� ���� �� ���� ���� ����

		return;
	}

	for (int i = cur_index; i < N - (N/2 - start_team_cnt); i++){
		team[i] = true; // ��ŸƮ ���� �Ѹ� ���� ���� ǥ��
		solution(start_team_cnt + 1, i + 1);
		team[i] = false; // �Լ� ��ġ�� ������ ���� �ܰ迡���� �Ȼ��� ���� ����
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