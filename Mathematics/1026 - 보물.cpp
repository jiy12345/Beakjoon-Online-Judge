#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(int N, vector<int> A, vector<int> B) {
	long long answer = 0;

	// B 배열은 내림차순 정렬
	sort(B.begin(), B.end(), greater<int>());
	// A 배열은 오름차순 정렬
	sort(A.begin(), A.end());

	for (int i = 0;i < N;i++) {
		answer += A[i] * B[i];
	}

	return answer;
}

int main() {
	int N, temp;
	vector<int> A, B;

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> temp;
		A.push_back(temp);
	}	
	for (int i = 0;i < N;i++) {
		cin >> temp;
		B.push_back(temp);
	}

	cout << solution(N, A, B);

	return 0;
}
