#include<iostream>
using namespace std;

int people[50][3];
int N;

void solution() {
	for (int i = 0;i < N;i++) {
		int cur_rank = 1;
		for (int j = 0;j < N;j++) {
			if (people[i][0] < people[j][0] && people[i][1] < people[j][1]) {
				cur_rank++;
			}
		}
		people[i][2] = cur_rank;
	}

	for (int i = 0;i < N;i++) {
		cout << people[i][2] << " ";
	}
}

int main() {
	
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> people[i][0] >> people[i][1];
	}

	solution();
}
