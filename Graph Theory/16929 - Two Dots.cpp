#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
N: �������� ���� ����
M: �������� ���� ����

- ���� ���� ����
N, M: 2 ~ 50


- ���� ��Ȳ
�� k�� d1, d2, ..., dk�� �̷���� ����Ŭ�� ���Ǵ� �Ʒ��� ����.

 - ��� k���� ���� ���� �ٸ���.
 - k�� 4���� ũ�ų� ����.
 - ��� ���� ���� ����.
 - ��� 1 �� i �� k-1�� ���ؼ�, di�� di+1�� �����ϴ�. ��, dk�� d1�� �����ؾ� �Ѵ�. �� ���� �����ϴٴ� ���� ������ ���� ����ִ� ĭ�� ���� �����Ѵٴ� �ǹ��̴�.

�������� ���°� �־����� ��, ����Ŭ�� �����ϴ��� �ƴ��� ���θ� �Ǵ��϶�.

 2. Ǯ�� ��ȹ
 ���� �ּ� � �μ���� �ϴ����� ���� �����̹Ƿ�, ���� �μ��� ���� ����� �߻��Ѵٰ� ���� �ȴ�.

 ���� 0 - 1 BFS��� �� �� �ִ�.

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int di[4] = { +1, -1, 0, 0 };
int dj[4] = { 0, 0, +1, -1 };

int N, M;
string gameBoard[50];
bool isVisited[50][50];
int dist[50][50];

inline bool isInRange(int i, int j) {
	return (0 <= i && i < N && 0 <= j && j < M);
}

bool isCycle(char Color, int cur_i, int cur_j, int cur_depth) {
	if (isVisited[cur_i][cur_j]) {
		if (cur_depth - dist[cur_i][cur_j] >= 4) // �̵� Ƚ������ ���� ��ġ�� ����� ���������� �Ÿ� ���� 4 �̻� = ����Ŭ
			return true;
		else
			return false;
	}

	isVisited[cur_i][cur_j] = true;
	dist[cur_i][cur_j] = cur_depth;

	for (int k = 0; k < 4; k++) {
		int next_i = cur_i + di[k];
		int next_j = cur_j + dj[k];

		if (isInRange(next_i, next_j) && gameBoard[next_i][next_j] == Color)
			if (isCycle(Color, next_i, next_j, cur_depth + 1))
				return true;
	}

	return false;
}

string solution() {
	// ��� ������ ����
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			if (isVisited[i][j] == false) // ���� Ž������ ���� ���� ���
				if (isCycle(gameBoard[i][j], i, j, 0))
					return "Yes";

	return "No";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) 
		cin >> gameBoard[i];

	cout << solution();
	
	return 0;
}