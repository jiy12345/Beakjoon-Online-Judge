#include<iostream>
#include<queue>
using namespace std;

#define MAX 1000001

int N;
bool isVisited[MAX];

void solution() {

	queue<pair<int, pair<int,vector<int>>>> bfs_queue;
	bfs_queue.push({ N, {0, { N } } });
	isVisited[N] = true;

	while (!bfs_queue.empty()) {
		int cur_num = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second.first;
		vector<int> cur_route(bfs_queue.front().second.second);
		bfs_queue.pop();

		if (cur_num == 1) {
			cout << cur_depth << '\n';
			for (int i = 0; i < cur_route.size(); i++) {
				cout << cur_route[i] << " ";
			}
			break;
		}
		
		int next_num;
		if (cur_num % 3 == 0) {
			next_num = cur_num / 3;

			if (next_num >= 1 && isVisited[next_num] == false) {
				isVisited[next_num] = true;
				cur_route.push_back(next_num);
				bfs_queue.push({ next_num, {cur_depth + 1, cur_route} });
				cur_route.pop_back();
			}
		}

		if (cur_num % 2 == 0) {
			next_num = cur_num / 2;

			if (next_num >= 1 && isVisited[next_num] == false) {
				isVisited[next_num] = true;
				cur_route.push_back(next_num);
				bfs_queue.push({ next_num, {cur_depth + 1, cur_route} });
				cur_route.pop_back();
			}
		}

		next_num = cur_num - 1;
		if (next_num >= 1 && isVisited[next_num] == false) {
			isVisited[next_num] = true;
			cur_route.push_back(next_num);
			bfs_queue.push({ next_num, {cur_depth + 1, cur_route} });
			cur_route.pop_back();
		}	
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	solution();

	return 0;
}
