#include<iostream>
#include<queue>
using namespace std;

#define MAX 1000001

int N;
bool isVisited[MAX];
int fromTo[MAX];
vector<int>Route;

int solution() {
	int answer = -1;

	queue<pair<int, int>> bfs_queue;
	bfs_queue.push({ N, 0 });
	isVisited[N] = true;

	while (!bfs_queue.empty()) {
		int cur_num = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second;
		bfs_queue.pop();

		if (cur_num == 1) {
			answer = cur_depth;
			break;
		}
		
		int next_num;
		if (cur_num % 3 == 0) {
			next_num = cur_num / 3;

			if (next_num >= 1 && isVisited[next_num] == false) {
				isVisited[next_num] = true;
				fromTo[next_num] = cur_num;
				bfs_queue.push({ next_num, cur_depth + 1 });
			}
		}

		if (cur_num % 2 == 0) {
			next_num = cur_num / 2;

			if (next_num >= 1 && isVisited[next_num] == false) {
				isVisited[next_num] = true;
				fromTo[next_num] = cur_num;
				bfs_queue.push({ next_num, cur_depth + 1 });
			}
		}

		next_num = cur_num - 1;
		if (next_num >= 1 && isVisited[next_num] == false) {
			isVisited[next_num] = true;
			fromTo[next_num] = cur_num;
			bfs_queue.push({ next_num, cur_depth + 1 });
		}	
	}

	int cur_num = 1;
	while (cur_num != N) {
		Route.push_back(cur_num);
		cur_num = fromTo[cur_num];
	}
	Route.push_back(N);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	cout << solution() << '\n';

	for (int i = Route.size() - 1; i >= 0; i--) {
		cout << Route[i] << " ";
	}

	return 0;
}
