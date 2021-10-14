#include<iostream>
using namespace std;

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
		// 2로 나눈 몫과 같음(B /= 2)
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
