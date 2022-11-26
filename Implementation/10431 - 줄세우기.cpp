#include<iostream>
using namespace std;

int P;
int students[20];

int solution() {
	int answer = 0;
	for (int i = 0; i < 20; i++) {
		int changeIndex = i;
		for (int j = 0; j < i; j++) {
			if (students[i] < students[j]) {
				changeIndex = j;
				break;
			}
		}
		int temp = students[i];

		for (int j = i - 1; j >= changeIndex; j--) {
			students[j + 1] = students[j];
			answer++;
		}
		students[changeIndex] = temp;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> P;

	for (int i = 0; i < P; i++) {
		int T;
		cin >> T;

		for (int j = 0; j < 20; j++) {
			cin >> students[j];
		}

		cout << T << ' ' << solution() << '\n';
	}

}