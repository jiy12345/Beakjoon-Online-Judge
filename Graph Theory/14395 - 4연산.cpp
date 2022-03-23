#include<iostream>
#include<queue>
#include<set>
using namespace std;

/*
1. 문제 분석
- 변수
s: 시작 정수
t: 목표 정수

- 변수 제한 사항
s, t: 1 ~ 1,000,000,000


- 문제 상황
가능한 방법이 여러 가지라면, 길이가 가장 짧은 것을 출력한다. 
길이가 가장 짧은 것이 여러 가지라면, 사전 순으로 앞서는 것을 출력한다.

2. 풀이 계획
 일반적으로 푸시할 때 방문 표시를 했던 다른 문제들과 다르게 

 이 문제에서는 pop 할 때 방문 표시를 해야할 듯 하다.

 왜냐하면 같은 노드에 가더라도 앞서 지나온 경로가 다르다면(물론 경로의 길이는 같아야 한다.) 서로 다른 경로로 인정하여 고려해야 하기 때문이다.



3. 계획 검증

bfs는 그런데 거리상 가까운 노드가 먼저 나온다.

거리가 가까운 것이 회전수가 적다는 것을 보장하는가?
그렇지 않다. 따라서 priority_queue를 사용하여 회전 수에 따라서 정렬되도록 해야할 듯 하다.


*/

#define MAX 1000000001

long long s, t;
set<long long> isVisited;


string solution() {
	if (s == t) return "0";
	
	int answerDepth = MAX;

	queue<pair<int, pair<long long, string>>> bfs_queue;
	bfs_queue.push({ 0, {s, ""} });

	priority_queue<string, vector<string>, greater<string>> answers;

	while (!bfs_queue.empty()) {
		int cur_depth = bfs_queue.front().first;
		long long cur_s = bfs_queue.front().second.first;
		string usedOperators = bfs_queue.front().second.second;
		bfs_queue.pop();
		isVisited.insert(cur_s);

		if (cur_depth > answerDepth) break;

		if (cur_s == t) {
			answerDepth = cur_depth;
			answers.push(usedOperators);
		}

		long long next_s = cur_s + cur_s;
		if (isVisited.find(next_s) == isVisited.end()) bfs_queue.push({cur_depth + 1, {next_s, (usedOperators + '+')}});
		
		next_s = cur_s - cur_s;
		if (isVisited.find(next_s) == isVisited.end()) bfs_queue.push({ cur_depth + 1, { next_s, (usedOperators + '-')} });
		
		next_s = cur_s * cur_s;
		if (isVisited.find(next_s) == isVisited.end()) bfs_queue.push({ cur_depth + 1, { next_s, (usedOperators + '*')} });
		
		if (cur_s != 0) {
			next_s = cur_s / cur_s;
			if (isVisited.find(next_s) == isVisited.end()) bfs_queue.push({ cur_depth + 1, { next_s, usedOperators + '/'} });

		}
	}

	// 못찾을 경우
	if (answers.empty()) return "-1";

	return answers.top();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> t;

	cout << solution();

	return 0;
}
