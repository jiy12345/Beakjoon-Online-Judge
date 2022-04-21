#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


/*
1. ���� �м�
- ����
N: ��ǻ���� ����
M: ������ ����

 - ���� ���� ����
N: 1 ~ 10,000
M: 1 ~ 100,000

- ���� ��Ȳ
 A�� B�� �ŷ��ϴ� ��� B�� ��ŷ�ϸ� A�� ��ŷ�� �� �ִ�.

2. Ǯ�� ��ȹ



3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

#define MAX 10001

int N, M;
vector<int> graph[MAX];
int numHack[MAX];
bool isVisited[MAX];

int dfs(int cur_node) {
	isVisited[cur_node] = true;

	int cur_numHack = 1; // �⺻������ ���� ��ǻ�ʹ� �׻� ��ŷ �ǹǷ�

	for (int next_node : graph[cur_node])
		if (isVisited[next_node] == false) 
			cur_numHack += dfs(next_node);

	return cur_numHack;
}

void solution() {
	int maxNum = 0;

	// ��� ��忡 ���� Ž���ϸ� �� ��ǻ�͸� ��ŷ���� �� ��ŷ�� �� �ִ� ��ǻ���� �� ã��,
	// �� �ִ밪 ���ϱ�
	for (int i = 1; i <= N; i++) {
		memset(isVisited, false, sizeof(isVisited));
		numHack[i] = dfs(i);
		maxNum = max(maxNum, numHack[i]);
	}

	for (int i = 1; i <= N; i++) {
		// cout << numHack[i] << " ";
		if (numHack[i] == maxNum) cout << i << " ";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int root = 0;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[B].push_back(A);
	}

	solution();

	return 0;
}