#include<iostream>
#include<queue>
using namespace std;

int V, E;
// C, A, B 순으로 저장
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> links;
int Parent[100001];

int findParent(int x) {
	if (Parent[x] == x) return x;
	else return Parent[x] = findParent(Parent[x]);
}

void Union(int x, int y)
{
	x = findParent(x);
	y = findParent(y);

	if (x != y) Parent[y] = x;
}

bool isSameParent(int x, int y)
{
	x = findParent(x);
	y = findParent(y);

	if (x == y) return true;
	else return false;
}

int solution() {
	int answer = 0;
	int lastNum = 0; // 마지막으로 더해진 수

	for (int i = 1; i <= V; i++)
	{
		Parent[i] = i;
	}

	while (!links.empty()) {
		vector<int> cur_link(links.top());
		links.pop();
		if (isSameParent(cur_link[1], cur_link[2]) == false) {
			Union(cur_link[1], cur_link[2]);
			answer += cur_link[0];
			lastNum = cur_link[0];
		}
	}
	
	// 마지막으로 더해진 수가 가중치가 가장 크다
	// 따라서 해당 수만 빼면 
	// 두 부분으로 나눠진 최소 스패닝 트리를 구할 수 있다.
	return answer - lastNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		// 가중치를 가장 앞에 놔 가중치 기준으로 정렬되도록 함
		links.push({ C, A, B });
	}

	cout << solution();
}
