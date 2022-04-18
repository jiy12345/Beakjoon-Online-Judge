#include<iostream>
#include<cstring>
using namespace std;


/*
1. ���� �м�
- ����
n: �볪�� ���� ����, ���� ����

 - ���� ���� ����
n: 1 ~ 500

�� ������ �볪���� ��: 1 ~ 1,000,000

- ���� ��Ȳ
 �Ǵٰ� ������ ���� �����δٰ� ����.

- �� �������� �볪���� �Դ´�.
- ������ �볪���� �� ������ ��, ��, ��, ���� �Ѱ����� �̵��Ѵ�.
- ���� �������� �볪���� ���� �������θ� �̵��Ѵ�.

 �볪�� ���� ���°� �־����ٰ� �� ��, �Ǵٰ� �̵��� �� �ִ� ĭ�� �ִ밪�� ���Ͽ���

2. Ǯ�� ��ȹ
 ��� ��ġ�� ���� �˻��ϵ�, �� ��ġ�� �ּҰ��̳� �ִ밪�̶�� ������ �����Ƿ�

 �� ��ġ�κ��� �۾����� ���������� �̵���, Ŀ���� ���������� �̵��� ���� ������!
  => �̷��� �ϸ� �ð��ʰ��� �߻��Ѵ�.
 
 ��� ó�� ������ �������� �����ϸ� �ߺ��� ������ �����ؾ� �ϴ� �κ��� �ʹ� ����.

 �׷��ٸ� ��� �ߺ� ����Ǵ� �κ��� ���� �� ������?

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

int n;
int bambooForest[500][500];
int maxDist[500][500];

bool isInRange(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < n;
}

int dfs(int cur_i, int cur_j) {
	if (maxDist[cur_i][cur_j] != 0) return maxDist[cur_i][cur_j];
	// ���� ĭ�� ���ԵǾ�� �ϹǷ�
	maxDist[cur_i][cur_j] = 1;

	for (int i = 0; i < 4; i++) {
		int next_i = cur_i + di[i];
		int next_j = cur_j + dj[i];

		// �� ���� ���� ��� Ž���� �������� ����
		if (!isInRange(next_i, next_j)) continue;


		if (bambooForest[cur_i][cur_j] < bambooForest[next_i][next_j]) {
			maxDist[cur_i][cur_j] = max(maxDist[cur_i][cur_j], dfs(next_i, next_j) + 1);
		}
	}

	return maxDist[cur_i][cur_j];
}

int solution() {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			answer = max(answer, dfs(i, j));
		} 
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> bambooForest[i][j];
		}
	}

	cout << solution();

	return 0;
}