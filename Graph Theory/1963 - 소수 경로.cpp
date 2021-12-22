#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

/*
1. 문제 분석

- 변수
T: 테스트 케이스의 개수
A, B: 시작 소수와 목표 소수

- 변수 제한 사항
A, B: 1000~9999인 소수

 - 문제 상황
 시작 소수와 목표 소수가 주어질 때, 다음의 조건을 만족하며 시작 소수에서 목표 소수로 바꾸는데 드는 변환의 최소 회수를 구하라.

 - 한번에 한자리의 수만 변경이 가능하다.
 - 변경하는 과정에서도 1000~9999인 소수를 유지해야 한다!

2. 풀이 계획
 이것도 간선의 가중치가 없는 그래프의 최소 거리를 구하는 것이므로, PUSH할 때 방문 표시를 진행하는 BFS를 진행하면 될 듯 하다!


3. 계획 검증


*/

#define MAX 9999

bool isPrime[MAX + 1];

void getPrimeNum() {
	// 에라토스테네스의 체로 9999까지의 소수 구하기
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