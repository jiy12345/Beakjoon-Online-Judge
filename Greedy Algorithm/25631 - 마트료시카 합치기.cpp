#include<iostream>
#include<map>
using namespace std;

int N;
map<int, int> numOfMatryo;

int solution() {

	for (int i = 0; i < N; i++) {
		int curSize;
		cin >> curSize;

		numOfMatryo[curSize]++;
	}

	int answer = 0;

	for (auto curMatryo : numOfMatryo) {
		answer = max(answer, curMatryo.second);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	cout << solution();
}