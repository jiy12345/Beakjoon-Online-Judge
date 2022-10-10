#include<iostream>
using namespace std;

int N;
string curSign;

int solution() {
	int answer = 0;

	string reusedSign;
	for (int i = 0; i < N; i++) {
		bool isFound = false;		
		cin >> reusedSign;

		for (int j = 0; j < reusedSign.size() - curSign.size() + 1; j++) {
			if (reusedSign[j] != curSign[0]) continue;
			
			int k;
			for (k = j + 1; k < reusedSign.size(); k++) {
				if (reusedSign[k] != curSign[1]) continue;
				int interval = k - j;
				int curIdx = 2;
				int reusedIdx = k + interval;

				int cnt = 2;
				while (true) {
					if (reusedIdx >= reusedSign.size() || cnt == curSign.size()) break;
					if (reusedSign[reusedIdx] != curSign[curIdx++]) break;
					cnt++;
					reusedIdx += interval;
				}

				if (cnt == curSign.size()) {
					isFound = true;
					answer++;
					break;
				}
			}

			if (isFound == true) break;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> curSign;
	cout << solution();

	return 0;
}