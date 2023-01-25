#include<iostream>
using namespace std;

int N, K;
char wheel[25];
bool is_used[26];

void solution() {
	int cur_index = 0;
	for (int i = 0; i < K; i++) {
		int num_rotated;
		char cur_char;
		cin >> num_rotated >> cur_char;
		
		cur_index = (cur_index + num_rotated) % N;

		if (wheel[cur_index] != cur_char) {
			if (isalpha(wheel[cur_index])) {
				cout << "!";
				return;
			}

			if (is_used[cur_char - 'A'] == true) {
				cout << "!";
				return;
			}
		}

		wheel[cur_index] = cur_char;
		is_used[cur_char - 'A'] = true;
	}

	for (int i = cur_index; i >= 0; i--) {
		cout << (isalpha(wheel[i]) ? wheel[i] : '?');
	}
	for (int i = N - 1; i > cur_index; i--) {
		cout << (isalpha(wheel[i]) ? wheel[i] : '?');
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	solution();
}