#include<iostream>
#include<math.h>
using namespace std;

int A, B;
int N;

int solution() {
	int answer = abs(A - B);

	cin >> N;
	int Favor;
	for (int i = 0; i < N; i++) {
		cin >> Favor;
		answer = min(answer, abs(B - Favor) + 1);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;
	cout << solution();
}