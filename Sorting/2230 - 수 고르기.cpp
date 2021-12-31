#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> A;
int M, N;

int solution() {
	// ���� �ϳ��ۿ� ���� ��� �׻� �� �� �ִٸ� ���� ���� �ι� ���� �ϹǷ� ���̴� ������ 0
	// ������ �ּҰ��� 0�� ��� ���� ���� �ι� ���� ������ �ּҰ��� �ǹǷ� 0
	if (N == 1 || M == 0) {
		return 0;
	}

	int answer = 2000000001; // ���� �� �ִ� �ִ밪���� ū ��

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