#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;

vector<int> solutions; // 용액들

void solution() {
	sort(solutions.begin(), solutions.end());

	int answer[2] = {0, 0};
	int leftPtr = 0; 
	int rightPtr = N - 1;
	int min = 2000000000;
	while (leftPtr < rightPtr) {
		int sum = solutions[leftPtr] + solutions[rightPtr];

		// 갱신이 필요한 경우
		if (min > abs(sum)) {
			min = abs(sum);
			answer[0] = solutions[leftPtr];
			answer[1] = solutions[rightPtr];
			
			if (sum == 0)
				break;
		}

		if (sum < 0)
			leftPtr++;
		else
			rightPtr--;
	}

	cout << answer[0] << " " << answer[1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		solutions.push_back(temp);
	}

	solution();
}
