#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int A, B, C;
bool isVisited[1000][1000];

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

			int minNum = min({ next_A, next_B, next_C });
			int maxNum = max({ next_A, next_B, next_C });

			if (isVisited[minNum][maxNum] == false) {
				isVisited[minNum][maxNum] = true;
				bfs_queue.push({ minNum, maxNum });
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
