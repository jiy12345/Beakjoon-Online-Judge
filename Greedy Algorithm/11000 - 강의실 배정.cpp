#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�

- ����
N: ������ ����

S[i]: i��° ������ �����ϴ� �ð�
T[i]: i��° ������ ������ �ð�

- ���� ���� ����
N: 1~200,000
0 �� Si < Ti �� 10^9

 - ���� ��Ȳ
 ���� �������� �־����� ��, �� �ߵ��� ����Ͽ� ������ �� ���� ���� ���� ���� �� �ּҰ��� ���Ͽ���

2. Ǯ�� ��ȹ
 �� �������� �����ϸ� �ȴ�,

3. ��ȹ ����


*/

class comp {
public:
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
		// �� �̸��� ���ٸ�,
		if (lhs.second == rhs.second) {
			// �� ��ȣ�� ���� ���� ����
			return lhs.first > rhs.first;
		}
		else { // �� �̸��� �ٸ��ٸ�, ���������� �̸��� ������ ���� ����
			return lhs.second > rhs.second;
		}
	}
};


int N;
priority_queue <pair<int, int>, vector<pair<int, int>>, comp> schedule;

int solution() {
	int curEndTime = 0;
	int answer = 0;

	for (int i = 0; i < N; i++) {
		if (schedule.top().first >= curEndTime) {
			curEndTime = schedule.top().second;
		}
		else {
			answer++;
		}
		schedule.pop();
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int S;
		int T;
		cin >> S >> T;

		schedule.push(make_pair(S, T));
	}

	cout << solution();

	return 0;
}