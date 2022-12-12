#include<iostream>
using namespace std;

int N, M;
char room_floor[50][50];

int solution() {
	int number_of_tile = 0;
	for (int i = 0; i < N; i++) {
		int cur_tile = 0;
		for (int j = 0; j < M; j++) {
			if (room_floor[i][j] == '-')
				cur_tile++;
			else if (cur_tile != 0) {
				number_of_tile++;
				cur_tile = 0;
			}
		}
		if (cur_tile != 0) number_of_tile++;
	}

	for (int i = 0; i < M; i++) {
		int cur_tile = 0;
		for (int j = 0; j < N; j++) {
			if (room_floor[j][i] == '|')
				cur_tile++;
			else if (cur_tile != 0) {
				number_of_tile++;
				cur_tile = 0;
			}
		}
		if (cur_tile != 0) number_of_tile++;
	}

	return number_of_tile;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room_floor[i][j];
		}
	}

	cout << solution();
}