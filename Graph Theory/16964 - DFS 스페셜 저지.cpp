#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ����


- ���� ���� ����
N: 2 ~ 100,000
Ʈ�� ������ �־��� ���� 1���� N������ ������ 1���� �����Ѵ�.
���� ������ �׻� 1�� �����̴�.

- ���� ��Ȳ
 Ʈ���� ������ �־�����, DFS�� �湮 ������ �־��� ��,
 �ش� �湮 ������ DFS�� ������ �湮 �������� üũ�϶�

2. Ǯ�� ��ȹ

�߿��� ���� �� �������� ���� ��ġ�� ���ü� �ִ� �湮 �����ΰ��̴�.

���� Ž���� �����ϸ鼭 �� ��ġ���� �� �� �ִ� ��ġ���� ã��, ������ Ž���� ������ ����ؼ� �� �� �ִٸ� 


1. 1���� Ž���� �����Ѵ�.
2. ���� ������ �湮�ؾ� �ϴ� ��尡 1�� ����Ǿ� �ִ� ������� üũ�Ѵ�.
3. ���� ���� ���������� �湮�ϸ�, ���� ��忡 �湮�Ͽ��� ����

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/


int N;
vector<int> graph[100001];
vector<int> answer;

int visitOrder[100001];
bool isVisited[100001];
int cnt = 0;


bool comp(int a, int b) {
	return visitOrder[a] < visitOrder[b];
}


// dfs�� �湮�� ��������� ������ �����ִ� �Լ�
void dfs(int x) {
	answer.push_back(x);

	for (int node : graph[x]) {
		if (isVisited[node]) continue;
		isVisited[node] = true;
		dfs(node);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	vector<int> input(N);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
		// �׷����� ��� �湮 ���� ������ ���� �� ��尡 �湮�Ǵ� ���� ����
		visitOrder[input[i]] = i + 1;
	}

	// ù ���ڰ� 1�� �ƴ� ��� Ʋ��
	if (input[0] != 1) {
		cout << 0;
		return 0;
	}
	else {
		// �� ��忡 ������ ������ �湮 ������ �Է� ������ ���� ����
		for (int i = 1; i <= N; i++) {
			sort(graph[i].begin(), graph[i].end(), comp);
		}
		isVisited[1] = true;
		dfs(1);
	}

	if (answer == input) cout << 1;
	else cout << 0;

	return 0;
}