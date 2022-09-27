#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> students;

void solution() {
	int curNum = 0;
	int numOfRounds = 0;

	vector<int> temp(students);
	while (true) {
		for (int i = 0; i < N - 1; i++) {
			temp[i + 1] = students[i + 1] / 2 + students[i] / 2;;
		}
		temp[0] = students[0] / 2 + students[N - 1] / 2;

		for (int i = 0; i < N; i++) {
			if (temp[i] % 2 != 0)
				students[i] = temp[i] + 1;
			else
				students[i] = temp[i];	
		}

		bool isAllSame = true;
		curNum = students[0];
		for (int i = 0; i < N; i++)
			if (curNum != students[i]) {
				isAllSame = false;
				break;
			}

		numOfRounds++;
		if (isAllSame) break;
	}

	cout << numOfRounds << ' ' << curNum << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	while (true) {
		cin >> N;
		if (N == 0) break;

		students.resize(N);
		for (int i = 0; i < N; i++)
			cin >> students[i];

		solution();
	}

	return 0;
}