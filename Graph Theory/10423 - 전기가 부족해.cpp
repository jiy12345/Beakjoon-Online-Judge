#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ����
M: ���̺��� ��
K: �������� ����

- ���� ���� ����
N: 1 ~ 1,000
M: 1 ~ 100,000


- ���� ��Ȳ
 �����Ұ� �����ϴ� ���ð� ������,
 ���̺��� ����Ǿ� �ִ� ���ÿ��� �ݵ�� �����Ұ� �ϳ��� �����ؾ� �Ѵ�.

2. Ǯ�� ��ȹ
�� ���ô� �ݵ�� �����Ұ� �ִ� ���ÿ� ����Ǿ�� �Ѵ�.

�׷��ٸ� ��� �ؾ� �ұ�?

���� ũ�罺Į �˰��򿡼���� ���� ���� �ּ� ����� ���� ������ �����ϸ� ������, 

������ �׷��� �ʴ�.

���ú��� �ϳ��� �����Ҹ� ����� �� �ֵ��� �ϴ� ������ �����Ͽ��� �Ѵ�.

������ ���¿��� �ϳ��� ���� �� ������ �شٸ� ó���� �� ������?

�����̸��� �����ҿ� ����ǵ��� �ϴ� ��������?

�׷��� �̷������� üũ�ϸ� ������ �����ҿ� ������ ���� �ʴ��� ���߿� �ٸ� ������ ���� ����ǵ��� �ϴ� ������ ������ �� ����.

�׷��ٸ� �̷��� ������ �ٸ� ���� �����ص״ٰ� �ٽ� üũ�ϴ� ����?
 => �־��� ��� N^2�� ���ð��̱� ������ �ȵ� �� �ϴ�.

���� �θ�� ����, 

3. ��ȹ ����
*/

#define MAX 1001

int N, M, K;

// ����ġ, ��� �༺, ���� �༺ ������ ����
vector<vector<int>> cables;
int Parent[MAX];

bool isPowerStation[MAX];


int findParent(int x) {
	if (Parent[x] == x) return x;
	else return Parent[x] = findParent(Parent[x]);
}

void Union(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x != y) {
		// ������ �θ� 0�� ��� �������� �θ� 0���� �������ֱ�!
		if (x == 0) Parent[y] = 0;
		else if (y == 0) Parent[x] = 0;
		else Parent[y] = x;
	}
}

bool isSameParent(int x, int y) {
	return findParent(x) == findParent(y);
}


int kruskal() {
	int answer = 0;

	for (int i = 0; i <= N; i++) {
		Parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		vector<int> cur_link(cables[i]);
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

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int powerStation;
		cin >> powerStation;
		isPowerStation[powerStation] = true;;
	}

	
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		// �����Ұ� �Ǽ��� ���ô� ��� 0���� ǥ��
		if(isPowerStation[u]) u = 0;
		if(isPowerStation[v]) v = 0;

		cables.push_back({ w, u, v });
	}

	sort(cables.begin(), cables.end());

	cout << kruskal();
}