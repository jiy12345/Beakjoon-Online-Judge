#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
A: 곱해질 수
B: 곱해질 횟수
C: 나눌 수

- 변수 제한 사항
A, B, C: 1~2,147,483,647

- 문제 상황
 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

2. 풀이 계획
 각 수가 이미 int형으로 나타낼 수 있는 최대값이 될 수 있으므로, 문제

그 알고리즘은 다음과 같다.

1. arr[k] < arr[k+1]을 만족하는 가장 큰 k를 구한다.
2. k 다음 위치부터 arr[k] < arr[
4. k 다음 위치부터, arr[k+1] ~ arr[end]의 값들을 뒤집는다(좌우반전)


3. 계획 검증

*/

long long solution(long long A, long long B, long long C) {

	long long answer = 1;

	A %= C;

    while (B > 0) {
        // 지수가 홀수일 때
		// 둘로 정확히 나눠지지 않으므로 자기 자신 하나 곱해주기
        if (B % 2 == 1) {
            answer *= A;
			answer %= C;
        }
		A = ((A % C) * (A % C)) % C;
		// B 오른쪽으로 이동 연산
		B >>= 1;
    }

	return answer;
}

int main() {
	long long A, B, C;

	cin >> A >> B >> C;

	cout << solution(A, B, C);

	return 0;
}