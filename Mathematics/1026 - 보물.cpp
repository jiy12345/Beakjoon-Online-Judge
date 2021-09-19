#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. 문제 분석

- 변수
N: 숫자의 개수


- 변수 제한
1 <= N <= 50
0 <= A의 원소, B의 원소 <= 100


- 문제 상황
S = A[0]×B[0] + ... + A[N-1]×B[N-1]일 때,
S의 최솟값을 출력하는 프로그램을 작성하라

2. 풀이 계획
B에 있는 수를 재배열하지 말라고는 했으나, 최솟값만을 출력하는 문제이므로 재배열해도 문제는 없을 것 같다.

따라서 B는 내림차순으로, A는 오름차순으로 정렬한 후, 같은 인덱스에 있는 수끼리 곱한 후 합하면 될 듯 하다!

*/

int solution(int N, vector<int> A, vector<int> B) {
	long long answer = 0;

	sort(B.begin(), B.end(), greater<int>());
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