#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int R, C; // 

bool cmp(pair<int, int> a, pair<int, int> b){
	if (a.first < b.first)
		return true;
	return false;
}

// 정렬하여 등수를 매긴 뒤
// 번호 순으로 다시 정렬하여 출력한다.
void solution() {
	string curRow;
	vector<pair<int, int>> rank;
	for (int i = 0; i < R; i++) {
		cin >> curRow;
		for (int j = 1; j < C - 1; j++) {
			if (curRow[j] != '.') {
				rank.push_back({ C - j, curRow[j] - '0' });
				break;
			}
		}
	}

	sort(rank.begin(), rank.end(), cmp);

	int curRank = 1;
	int answer[10];
	answer[rank[0].second] = curRank;
	int prevDist = rank[0].first;
	for (int i = 1; i < 9; i++) {
		if (prevDist != rank[i].first)
			curRank++;
		answer[rank[i].second] = curRank;
		prevDist = rank[i].first;
	}

	for (int i = 1; i <= 9; i++) 
		cout << answer[i] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	solution();
}