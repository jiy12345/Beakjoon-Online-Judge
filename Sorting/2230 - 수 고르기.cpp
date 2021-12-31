#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> A;
int M, N;

int solution() {
	// 수가 하나밖에 없는 경우 항상 고를 수 있다면 같은 수를 두번 골라야 하므로 차이는 무조건 0
	// 차이의 최소값이 0일 경우 같은 수를 두번 고르면 무조건 최소값이 되므로 0
	if (N == 1 || M == 0) {
		return 0;
	}

	int answer = 2000000001; // 나올 수 있는 최대값보다 큰 값

	int firstNumPtr = 0;
	int secondNumPtr = 1;

	while (true) {
		int difference = A[secondNumPtr] - A[firstNumPtr];
		
		if (difference >= M) {
			answer = min(answer, difference);

			firstNumPtr++;
		}
		else {
			secondNumPtr++;
		}

		if (secondNumPtr == N) {
			break;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		A.push_back(temp);
	}

	sort(A.begin(), A.end());

	cout << solution();

	return 0;
}