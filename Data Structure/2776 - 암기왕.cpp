#include<iostream>
#include<set>
using namespace std;

int T, M, N;
set<int> note1;

void solution() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		int note2_num;
		cin >> note2_num;
		cout << ((note1.find(note2_num) == note1.end()) ? 0 : 1) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		note1.clear();
		cin >> N;

		for (int i = 0; i < N; i++) {
			int input_num;
			cin >> input_num;
			note1.insert(input_num);
		}
		solution();
	}
}