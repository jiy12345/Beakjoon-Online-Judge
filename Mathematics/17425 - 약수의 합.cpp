#include<iostream>
#include<algorithm>
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

int N, T;
int X[100000];
long long FY[1000001];
long long FX[1000001];

void solution(int N) {
    // 1은 모든 수의 약수니까 전부 넣어준다.
    fill_n(FX, N + 1, 1);
    /*
    배수 아이디어. (i*1, i*2, i*3....)
    i는 2부터 n까지 i를 약수를 갖는 모든 수다.
    시간복잡도는 NlgN이다.
    j는 i*j까지만 반복한다. 예를 들어 i가 2일 경우 j는 오십만까지만 가면된다.
    2 * 오십만은 백만이니까.
    */
    for (int i = 2; i < N; i++) {
        for (int j = 1; i * j < N+1; j++) {
            FX[i * j] += i;
        }
    }
    for (int i = 1; i <= N; i++) {
        FY[i] = FY[i - 1] + FX[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> X[i];
    }

    int max_num = *max_element(X, X + T);

    cout << max_num;
    solution(max_num);

    for (int i = 0; i < T; i++) {
        cout << "?";
        cout << FY[X[i]] << endl;
    }

    return 0;
}
