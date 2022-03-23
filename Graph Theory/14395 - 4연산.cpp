#include<iostream>
#include<queue>
#include<set>
using namespace std;

#define MAX 1000000001

long long s, t;
set<long long> isVisited;

string solution() {
	if (s == t) return "0";
	
	int answerDepth = MAX;

	queue<pair<int, pair<long long, string>>> bfs_queue;
	bfs_queue.push({ 0, {s, ""} });
	isVisited.insert(s);

	string answer = "-1";

	while (!bfs_queue.empty()) {
		int cur_depth = bfs_queue.front().first;
		long long cur_s = bfs_queue.front().second.first;
		string usedOperators = bfs_queue.front().second.second;
		bfs_queue.pop();

		if (cur_s == t) {
			answer = usedOperators;
			break;
		}

		long long next_s = cur_s * cur_s;
		if (next_s <= t && isVisited.find(next_s) == isVisited.end()) {
			bfs_queue.push({ cur_depth + 1, { next_s, (usedOperators + '*')} });
			isVisited.insert(next_s);
		}

		next_s = cur_s + cur_s;
		if (next_s <= t && isVisited.find(next_s) == isVisited.end()) {
			bfs_queue.push({cur_depth + 1, {next_s, (usedOperators + '+')}});		
			isVisited.insert(next_s);
		}
		
		next_s = cur_s - cur_s;
		if (next_s <= t && isVisited.find(next_s) == isVisited.end()) {
			bfs_queue.push({ cur_depth + 1, { next_s, (usedOperators + '-')} });
			isVisited.insert(next_s);
		}
		
		if (cur_s != 0) {
			next_s = cur_s / cur_s;
			if (next_s <= t && isVisited.find(next_s) == isVisited.end()) {
				bfs_queue.push({ cur_depth + 1, { next_s, usedOperators + '/'} });
				isVisited.insert(next_s);
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> t;

	cout << solution();

	return 0;
}
