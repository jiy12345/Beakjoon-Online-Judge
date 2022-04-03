#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
N: ���� ����
M: ���� �����ϴ� ���� ����

A, B, C: A�� ���� B�� ���� �����ϴ� ������ C�̴�.

- ���� ���� ����
N: 1 ~ 100,000
M: 1 ~ 1,000,000

C: 1 ~ 1,000

��δ� ������̴�.

- ���� ��Ȳ
 �ּ� ���д� Ʈ���� ����ġ�� ���Ͽ���

2. Ǯ�� ��ȹ

�ּ� ���д� Ʈ������ ����ġ�� ���� ���� ������ �� �ϳ��� ���� �� ������ ���� �ּ� ���д� Ʈ���� ���� �� �ִ�.

3. ��ȹ ����
*/

int V, E;
// C, A, B ������ ����
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> links;
int Parent[100001];

int findParent(int x) {
	if (Parent[x] == x) return x;
	else return Parent[x] = findParent(Parent[x]);
}

void Union(int x, int y)
{
	x = findParent(x);
	y = findParent(y);

	if (x != y) Parent[y] = x;
}

bool isSameParent(int x, int y)
{
	x = findParent(x);
	y = findParent(y);

	if (x == y) return true;
	else return false;
}

int solution() {
	int answer = 0;
	int lastNum = 0; // �湮�� ����� ��

	for (int i = 1; i <= V; i++)
	{
		Parent[i] = i;
	}

	while (!links.empty()) {
		vector<int> cur_link(links.top());
		links.pop();
		if (isSameParent(cur_link[1], cur_link[2]) == false) {
			Union(cur_link[1], cur_link[2]);
			answer += cur_link[0];
			lastNum = cur_link[0];
		}
	}

	return answer - lastNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		// ����ġ�� ���� �տ� �� ����ġ �������� ���ĵǵ��� ��
		links.push({ C, A, B });
	}

	cout << solution();
}