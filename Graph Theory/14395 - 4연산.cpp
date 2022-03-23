#include<iostream>
#include<queue>
#include<set>
using namespace std;

/*
1. ���� �м�
- ����
s: ���� ����
t: ��ǥ ����

- ���� ���� ����
s, t: 1 ~ 1,000,000,000


- ���� ��Ȳ
������ ����� ���� �������, ���̰� ���� ª�� ���� ����Ѵ�. 
���̰� ���� ª�� ���� ���� �������, ���� ������ �ռ��� ���� ����Ѵ�.

2. Ǯ�� ��ȹ
 �Ϲ������� Ǫ���� �� �湮 ǥ�ø� �ߴ� �ٸ� ������� �ٸ��� 

 �� ���������� pop �� �� �湮 ǥ�ø� �ؾ��� �� �ϴ�.

 �ֳ��ϸ� ���� ��忡 ������ �ռ� ������ ��ΰ� �ٸ��ٸ�(���� ����� ���̴� ���ƾ� �Ѵ�.) ���� �ٸ� ��η� �����Ͽ� ����ؾ� �ϱ� �����̴�.



3. ��ȹ ����

bfs�� �׷��� �Ÿ��� ����� ��尡 ���� ���´�.

�Ÿ��� ����� ���� ȸ������ ���ٴ� ���� �����ϴ°�?
�׷��� �ʴ�. ���� priority_queue�� ����Ͽ� ȸ�� ���� ���� ���ĵǵ��� �ؾ��� �� �ϴ�.


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

	// ��ã�� ���
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
