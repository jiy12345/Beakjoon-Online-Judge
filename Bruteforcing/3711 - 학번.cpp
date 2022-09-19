#include<iostream>
#include<set>
using namespace std;

int N, G;
int curStNum[300];

int solution() {
	int answer = 1;

	while (true) {
		set<int> remainders;
		bool isOK = true;
		for (int i = 0; i < G; i++) {
			int curRemainder = curStNum[i] % answer;
			if (remainders.find(curRemainder) == remainders.end()) {
				remainders.insert(curRemainder);
			}
			else {
				isOK = false;
				break;
			}
		}

		if (isOK == true)
			break;
		answer++;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> G;
		for (int i = 0; i < G; i++)
			cin >> curStNum[i];

		cout << solution() << '\n';
	}
}