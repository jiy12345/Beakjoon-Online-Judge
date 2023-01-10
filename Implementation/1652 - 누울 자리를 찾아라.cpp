#include<iostream>
using namespace std;

int N;
char room[100][100];

void solution() {
	int num_of_places_horizontal = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (room[i][j] == '.') {
				cnt++;
			}
			else {
				if (cnt >= 2) {
					num_of_places_horizontal++;
				}
				cnt = 0;
			}
		}

		if (cnt >= 2) {
			num_of_places_horizontal++;
		}
	}
	
	int num_of_places_vertical = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (room[j][i] == '.') {
				cnt++;
			}
			else {
				if (cnt >= 2) {
					num_of_places_vertical++;
				}
				cnt = 0;
			}
		}

		if (cnt >= 2) {
			num_of_places_vertical++;
		}
	}

	cout << num_of_places_horizontal << ' ' << num_of_places_vertical;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> room[i][j];
		}
	}

	solution();
}