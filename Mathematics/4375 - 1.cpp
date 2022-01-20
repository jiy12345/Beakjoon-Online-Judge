#include<iostream>
#include<string>
using namespace std;

/*
1. 문제 분석
- 변수
n: 기준이 될 수

- 변수 제한 사항
n: 1~10,000

- 문제 상황
 2와 5로 나누어 떨어지지 않는 정수 n이 주어졌을 때, 1로만 이루어진 n의 배수를 찾아라

2. 풀이 계획
 10씩 곱해가며 나누어 떨어지는지를 검사하면 될 듯 하다.
 
 n이 2와 5로 나누어 떨어지지 않아야 하는 이유는, n이 2나 5로 나누어 떨어질 경우 1의 자리수가 1인 수는 절대 만들 수 없기 때문이다.



3. 계획 검증

*/

int solution(int n) {
    int cnt = 1;
    int ones = 1;

    while (true) {
        ones %= n;
        if (ones == 0) {
            break;
        }

        // 자리수 세기
        cnt++;

        // 1한개 추가
        ones *= 10;
        ones++;

    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;

    while (getline(cin, n)) {
        cout << solution(stoi(n)) << '\n';
    }

    return 0;
}
