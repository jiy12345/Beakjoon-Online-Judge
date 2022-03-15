#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
A, B, C: �� �׷쿡 ���� ���� ����

 - ���� ���� ����
A, B, C: 1 ~ 500

- ���� ��Ȳ

 ���� ������ ���� �ܰ迡 ���� ������

 ũ�Ⱑ ���� ���� �� �׷��� ����. �� ����, ���� ������ ���� ���� X, ū ���� Y��� ���Ѵ�. �� ����, X�� �ִ� ���� ������ X+X����, Y�� �ִ� ���� ������ Y-X���� �����.

2. Ǯ�� ��ȹ
 ������ ���� ����, ���� ���� ������ ���� �� �ִ��� ���θ� ������ ���̹Ƿ�,

 ��� ������ ���θ� �Ǵ��ϴ� ���� ���� �߿��ϴ�.

 �ϴ� �Ʒ��� �� ���� �� �׷��� ������ 0�� �ȴٸ� �� �̻� ������ �� �����Ƿ� �ű⼭ ������ �Ѵ�.

 ���� ���� �� ���� ���� ū ���� �� �� ���� ���� 500, 499�� �� �̹Ƿ�, 1000�̻����δ� ���� �� �� ����.

 ���� 1000 ũ���� 3���� �迭�� �湮 ǥ�ø� �����ϰ�, ã���� 1, ��ã�� �����ϸ� 0�� ����ϸ� �� �� �ϴ�.

 �׷��� �ణ �����Ǵ� ���� �ð����⵵�� ���� ���⵵ ����?

 ������ �ڼ��� ����, �ѹ� ������ ���� �� X�� ���ϰ� X�� �� ���̹Ƿ� ��ü�� ��(A + B + C)�� �ٲ��� �ʴ� ���� �� �� �ִ�.

 �� ���� ������ 3���� �� �׷��� ��Ÿ�� �� �ִ�!


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/


int A, B, C;
bool isVisited[1500][1500];

inline void visit(int A, int B, int C) {
	isVisited[A][B] = true;
	isVisited[A][C] = true;
	isVisited[B][A] = true;
	isVisited[B][C] = true;
	isVisited[C][A] = true;
	isVisited[C][B] = true;
}

int solution() {
	int sum = A + B + C;

	if (sum % 3 != 0) {
		return 0;
	}

	int answer = 0;

	queue<vector<int>> bfs_queue;

	int first_A = max({ A, B, C });
	int first_B = min({ A, B, C });

	bfs_queue.push({ first_A, first_B });
	isVisited[first_A][first_B] = true;;

	while (!bfs_queue.empty()) {
		cout << "queue size: " << bfs_queue.size() << endl;
		int cur_A = bfs_queue.front()[0];
		int cur_B = bfs_queue.front()[1];
		bfs_queue.pop();

		int cur_C = sum - (cur_A + cur_B);

		if (cur_A == cur_B && cur_B == cur_C) {
			return 1;
		}

		vector<pair<int, int>> combinations = { {cur_A, cur_B}, {cur_B, cur_C}, {cur_A, cur_C} };
		
		for (pair<int, int> combination : combinations) {
			if (combination.first > combination.second) {
				combination.first -= combination.second;
				combination.second += combination.second;
			}
			else if (combination.first < combination.second) {
				combination.second -= combination.first;
				combination.first += combination.first;
			}
			else continue;

			int next_A = combination.first;
			int next_B = combination.second;
			int next_C = sum - (next_A + next_B);

			if (isVisited[next_A][next_B] == false) {
				visit(next_A, next_B, next_C);
				bfs_queue.push({ next_A, next_B });
			}
		}

	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> C;

	cout << solution();

	return 0;
}
