#include<iostream>
#include<unordered_set>
using namespace std;

unordered_set<string> string_set;
int N, M;

int solution() {
	int cnt = 0;
	for (int i = 0;i < M;i++) {
		string cur_string;
		cin >> cur_string;
		
		if (string_set.find(cur_string) != string_set.end()) {
			cnt++;
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		string cur_string;
		cin >> cur_string;
		string_set.insert(cur_string);
	}

	cout << solution();
}