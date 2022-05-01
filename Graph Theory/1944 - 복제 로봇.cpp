#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: �̷��� ����, ���� ����
M: ������ ����

- ���� ���� ����
N: 4 ~ 50
M: 1 ~ 250

- �̷� ����
1: �̷��� ��
0: �ٴ� �� �ִ� ��
S: �κ��� ����ϴ� ��ġ
K: ������ ��ġ

�̷��� ��� �׵θ��� ������ �̷���� �Է¸� �־�����.

- ���� ��Ȳ
 ã������ ������ ����, �̷��� ���°� �־����� ��,
 �κ��� ������ Ƚ���� ������ ���ϴ� ���α׷��� �ۼ��϶�.
 ��� ���踦 ã�� ���� �Ұ����� ��� ȸ

2. Ǯ�� ��ȹ

1. ��� ��ġ���� BFS�� �����ϸ�, ó�� ���踦 ã���� �����Ѵ�.
2. ���踦 ã�� ��ġ�κ��� �ٽ� BFS�� �����ϸ�, ���踦 ã���� �����Ѵ�.
3. ������ ������ ���踦 ��� ã������ �� �̵� �Ÿ��� ����ϸ�, �׷��� �ʰ� ã�� ���ϰ� ����Ǿ��ٸ� -1�� ����Ѵ�.

3. ��ȹ ����
 �˰������ ������ �ִ�.

 �ּ� ���д� Ʈ�� ������ �ƴ��� �˾Ҵµ� �ּ� ���д� Ʈ�� ������ �¾Ҵ�.

 �κ��� ������ �����ϱ� ������ �߰��� ���� ��η� �������� ���� ������ ���� �͵� �����ؾ� �ϱ� ������

 �׳� �� ��ġ������ ���� ����� Ű(Ȥ�� �����)�� ã�Ƴ��� ũ�罺Į �˰����� ������ �� �� �ϴ�.

*/

#define MAX 50
// ������� ������ �ִ� Ű ���� 251�� �̹Ƿ�
#define MAX_KEY 252

int N, M;
int maze[MAX][MAX];
bool isVisited[MAX][MAX];
int Parent[MAX_KEY];
vector<vector<int>> keyLocations;
vector<vector<int>> possibleLinks;

int di[4] = { 0, 0, 1, -1 };
int dj[4] = { 1, -1, 0, 0 };

int findParent(int x) {
	if (Parent[x] == x) return x;
	else return Parent[x] = findParent(Parent[x]);
}

void Union(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x != y) Parent[y] = x;
}

bool isSameParent(int x, int y) {
	return findParent(x) == findParent(y);
}

int kruskal() {
	int answer = 0;
	int cnt = 1; // ������ ����� ���� �� ����

	for (int i = 0; i <= M; i++) {
		Parent[i] = i;
	}

	int size = possibleLinks.size();

	for (int i = 0; i < size; i++) {
		vector<int> cur_link(possibleLinks[i]);
		if (isSameParent(cur_link[1], cur_link[2]) == false) {
			Union(cur_link[1], cur_link[2]);

			answer += cur_link[0];
			cnt++;
			if (cnt == M + 1) return answer;
		}
	}

	return -1;
}

// bfs�� ���� �� Ű Ȥ�� ��������� �ٸ� Ű Ȥ�� ����������� ��� ����ϴ� �Լ�
// ��ΰ� ���� ��� true ��ȯ
// �׷��� ���� ��� false ��ȯ
void findRoute(pair<int, int> curLocation, int startNum) {
	int start_i = curLocation.first;
	int start_j = curLocation.second;

	queue<vector<int>>bfs_queue;

	bfs_queue.push({ 0, start_i, start_j });
	isVisited[start_i][start_j] = true;

	while (!bfs_queue.empty()) {
		int cur_depth = bfs_queue.front()[0];
		int cur_i = bfs_queue.front()[1];
		int cur_j = bfs_queue.front()[2];
		bfs_queue.pop();

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];

			if (isVisited[next_i][next_j] == false && maze[next_i][next_j] != 1) {
				bfs_queue.push({ cur_depth + 1, next_i, next_j });
				isVisited[next_i][next_j] = true;

				if (maze[next_i][next_j] != 0) {
					// �� Ű���� ����� Ȥ�� �Ǵٸ� Ű���� ��� ������ ��ο� �߰�
					possibleLinks.push_back({ cur_depth + 1, startNum, maze[next_i][next_j] });
				}
			}
		}
	}
}

int solution() {
	for (int i = 0; i <= M; i++) {
		// �� ��ġ������ ������ ��ε��� ��� ���ϱ�
		findRoute({ keyLocations[i][0], keyLocations[i][1] }, keyLocations[i][2]);

		memset(isVisited, false, sizeof(isVisited));
	}

	sort(possibleLinks.begin(), possibleLinks.end());

	return kruskal();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int location_num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char curLocation;
			cin >> curLocation;

			// �� Ű�� ������� ��ȣ �ű��
			if (curLocation == 'S'|| curLocation == 'K') {
				maze[i][j] = location_num;
				keyLocations.push_back({ i, j, location_num++ });
			}
			else {
				maze[i][j] = curLocation - '0';
			}
		}
	}

	cout << solution();
}