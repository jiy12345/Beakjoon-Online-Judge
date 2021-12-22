#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

#define MAX 9999

bool isPrime[MAX + 1];

void getPrimeNum() {
	// 에라토스테네스의 체
	for (int i = 2; i <= MAX; i++)
		isPrime[i] = true;

	for (int i = 2; i * i <= MAX; i++)
	{
		if (isPrime[i])
			for (int j = i * i; j <= MAX; j += i)
				isPrime[j] = false;
	}
}

void solution(string startNum, string endNum) {
	int minRoute = 10000;
	bool isVisited[MAX + 1] = { false, };

	queue<pair<string, int>> bfs_queue;

	// 첫 수와 처음의 깊이인 0 표시
	bfs_queue.push(make_pair(startNum, 0));
	// 첫 수 방문 표시
	isVisited[stoi(startNum)] = true;

	while (!bfs_queue.empty()) {
		string cur_num = bfs_queue.front().first;
		int cur_depth = bfs_queue.front().second;
		bfs_queue.pop();

		if (cur_num == endNum) {
			minRoute = cur_depth;
			break;
		}

		// 4자리 숫자에 대해 반복
		for (int i = 0; i < 4; i++) {

			// 0~9까지 반복
			for (int j = 0; j < 10; j++) {
				string next_num_str = cur_num;

				// i번째 자리 j로 변경
				next_num_str[i] = j + 48;

				int next_num = stoi(next_num_str);

				if (isPrime[next_num] == true && isVisited[next_num] == false && 1000 <= next_num) {
					isVisited[next_num] = true;
					bfs_queue.push(make_pair(next_num_str, cur_depth + 1));
				}
			}
		}
	}

	if (minRoute == 10000) {
		cout << "Impossible" << '\n';
	}
	else {
		cout << minRoute << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 에라토스테네스의 체로 9999까지의 소수 구하기
	getPrimeNum();

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		string startNum, endNum;
		cin >> startNum >> endNum;


		solution(startNum, endNum);
	}

	return 0;
}
