#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N, M: ����� ����, ���� ����

 - ���� ���� ����
N, M: 1 ~ 1,000

- ���� ��Ȳ
 ���� �� ĭ�� ���� 0�� ����ϰ�, ���� ���� �̵��� �� �ִ� ĭ�� ������ 10���� ���� �������� ����Ѵ�.

2. Ǯ�� ��ȹ
 ���� ���� �������� ���� �׳� �� ��ġ���� BFS�� �����ϴ� ���̴�.

 �׷��� �׷��� �ϸ�, �־��� ��� �ʹ� ���� Ƚ���� �ݺ��� �־�� �Ѵ�.

 ��쿡 ���� ȸ���� �ſ� �޶����Ƿ� ��Ȯ�� �� ���� ������, 

 �׷��ٸ� ��� �ؾ��ұ�?

 ������ ��ĭ�鿡 ���� ������ ĭ���� ���̸� ����س���, �� ĭ�� 4���⿡ �ִ� ������ ���ϸ� ���?

 �̷��� �ϸ� �ϴ� �ѹ��� Ž������ �̷�����Ƿ�, �ð� ���⵵ ���� ������ ��������.

 �˰������ ������ �����İ� �����ε�,

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int di[4] = { +1, -1, 0, 0 };
int dj[4] = { 0, 0, +1, -1 };

int N, M;
bool isVisited[1000][1000];
string map[1000];
pair<int, int> blankArea[1000][1000]; // �� ����� ��ĭ�� ���� ���
int blankAreaNum;

inline bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}

void areaCalc(int i, int j) {
	queue<pair<int, int>> bfs_queue;
	vector<pair<int, int>> includedArea; // ���� ������ ���Ե� ��ġ���� ������� ����

	bfs_queue.push({i, j});
	isVisited[i][j] = true;

	int curArea = 0; // ���� ����� ��ĭ���� ���� ���

	while (!bfs_queue.empty()) {
		int cur_i = bfs_queue.front().first;
		int cur_j = bfs_queue.front().second;
		bfs_queue.pop();

		curArea++;
		includedArea.push_back({ cur_i, cur_j });

		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + di[i];
			int next_j = cur_j + dj[i];
			if (isInRange(next_i, next_j) && map[next_i][next_j] == '0' && isVisited[next_i][next_j] == false) {
				isVisited[next_i][next_j] = true;
				bfs_queue.push({ next_i, next_j });
			}
		}
	}

	// ���� ������ ���� ������ ���̿� ��ȣ �Է����ֱ�
	for (pair<int, int> location : includedArea) {
		blankArea[location.first][location.second] = { curArea, blankAreaNum };
	}

	blankAreaNum++;
}

void solution() {
	// �� ������ ��ĭ���� ���� ���
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (isVisited[i][j] == false && map[i][j] == '0')
				areaCalc(i, j);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '1') {
				int curArea = 1;
				vector<int> includedArea;
				for (int k = 0; k <4; k++) {

					int next_i = i + di[k];
					int next_j = j + dj[k];

					int area = blankArea[next_i][next_j].first;
					int areaNum = blankArea[next_i][next_j].second;

					// ���� ���� ���̰�,
					// ���� ���Ե��� ���� �����̸�, 
					// ���� �ƴ� ���� ����
					if (isInRange(next_i, next_j) 
						&& find(includedArea.begin(), includedArea.end(), areaNum) == includedArea.end()
						&& area != 0
						) {
						curArea += area;
						// �̹� ����� �����̶�� ��� �����
						includedArea.push_back(areaNum);
					}
				}
				curArea %= 10;

				map[i][j] = curArea + 48;
			}
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> map[i];

	solution();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << blankArea[i][j].first << " ";
		}
		cout << '\n';
	}	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << blankArea[i][j].second << " ";
		}
		cout << '\n';
	}

	for (int i = 0; i < N; i++)
		cout << map[i] << '\n';

	return 0;
}
