#include<iostream>
using namespace std;

int M, N;
string apartment[1000];
int status[5];

void solution() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int curStatus = 0;
			for (int k = 0; k < 4; k++) {
				if (apartment[1 + i * 5 + k][1 + j * 5] == '*') curStatus++;
			}
			status[curStatus]++;
		}
	}

	for (int i = 0; i < 5; i++)
		cout << status[i] << ' ';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> M >> N;

	for (int i = 0; i < 1 + M * 5; i++)
		cin >> apartment[i];

	solution();
}