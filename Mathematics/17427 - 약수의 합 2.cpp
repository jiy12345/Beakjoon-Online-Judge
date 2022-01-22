#include<iostream>
#include<string>
using namespace std;

/*
1. 문제 분석
- 변수
N: 주어지는 자연수

- 변수 제한 사항
N: 1~1,000,000

- 문제 상황

f(A): 자연수 A의 약수의 합

g(x): x보다 작거나 같은 모든 자연수 y의 f(y)를 더한 값

2. 풀이 계획

모든 수의 약수를 구해야 하는데 흠...

3. 계획 검증

*/

int N;

long long solution() {
    long long answer = 0;
    for (int i = 1; i <= N; i++) {
        answer += (N / i) * i;
    }

    return answer;
}

int main() {

    cin >> N;

    cout << solution();

    return 0;
}
