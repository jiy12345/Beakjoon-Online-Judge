#include<iostream>
#include<queue>
using namespace std;

/*
1. ���� �м�
- ����
N: ��ǻ���� ��
M: ������ ������ ����


- ���� ���� ����
N: 1 ~ 1,000
M: 1 ~ 100,000

��� ��ǻ�Ͱ� ������� �ʴ� ���� ����.

- ���� ��Ȳ
 �� ��ǻ�Ͱ� �����ϴµ� ��� ����� �־����� ��, 
 ��� ��ǻ�͸� �����ϴµ� �ʿ��� �ּ� ����� ����Ѵ�.

2. Ǯ�� ��ȹ

�ּ� ���д� Ʈ���� ���� ���� ��θ� ���� ������ �ʿ䰡 �����Ƿ�, �켱 ���� ť�� �־� ������ �ϳ��� ����,

union find �˰������� �� �� �� ����Ǿ� ���� ���� �����ϰ� �Ѿ��!

3. ��ȹ ����
*/

#define MAX 1001

int V, E;
// C, A, B ������ ����
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> links;
int Parent[MAX];

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

	for (int i = 1; i <= V; i++) {
		Parent[i] = i;
	}

	while (!links.empty()) {
		vector<int> cur_link(links.top());
		links.pop();
		if (isSameParent(cur_link[1], cur_link[2]) == false) {
			Union(cur_link[1], cur_link[2]);
			answer += cur_link[0];
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// ����ġ�� ���� �տ� �� ����ġ �������� ���ĵǵ��� ��
		links.push({ c, a, b });
	}

	cout << solution();
}