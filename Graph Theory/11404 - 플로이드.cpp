#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
1. ���� �м�
- ����
n: ����(����)�� ����
m: ����(����)�� ����

- ���� ���� ����
n: 2~100
m: 1~100,000
����� 100,000���� �۰ų� ���� �ڿ����̴�.
���� ���ÿ� ���� ���ð� ���� ���� ����.
���� ���ÿ� ���� ���ø� �����ϴ� �뼱�� �ϳ��� �ƴ� �� �ִ�.

- ���� ��Ȳ
n���� �ٿ� ���� ���� i���� j�� ���µ� �ʿ��� �ּ� ����� ����϶�.
����, i���� j�� �� �� ���� ��쿡�� �� �ڸ��� 0�� ����Ѵ�.



2. Ǯ�� ��ȹ
 ������ ��� �Ǵ��� �˱� ���ؼ��� �� �κд� �ѹ��� Ž���� ������ �ǰ�, ������ �̵��� ����ġ�� �����Ƿ�,

�湮 ǥ�ø� �̸��ϰ� Ž���� �����ϴ� BFS�� ���� Ǯ �� �ִ� ����ó�� ���δ�!

���� ���� ������ ���� �ƴҶ��� ���� ���� ��� ���� �湮���� ���� ��ġ������ bfs�� �����ϸ� �� �� �ϴ�!

3. ��ȹ ����

*/

int INF = 100001 * 100;

int n, m;

int min_distance[101][101];

void solution() {

	// i: ���İ��� ����
	for (int i = 1; i <= n; i++) {
		// j: ��� ����
		for (int j = 1; j <= n; j++) {
			// k: ���� ����
			for (int k = 1; k <= n; k++) {
				// ��� ���ÿ� ���� ���ð� �ٸ� ���� ��� ����
				if (j != k) {
					// i��° ���ø� ���İ��� ���� j���� k�� �ٷ� ���°ͺ��� �����ٸ� ����
					min_distance[j][k] = min(min_distance[j][k], min_distance[j][i] + min_distance[i][k]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		// j: ��� ����
		for (int j = 1; j <= n; j++) {
			if (min_distance[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << min_distance[i][j] << " ";
			}
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int startNode;

	cin >> n;
	cin >> m;

	fill(&min_distance[0][0], &min_distance [100][101], INF);

	for (int i = 0; i < m; i++) {
		int startCity;
		int endCity;
		int cost;

		cin >> startCity >> endCity >> cost;

		// ���� ������ �������� ����
		min_distance[startCity][endCity] = min(min_distance[startCity][endCity], cost);
	}

	solution();
}