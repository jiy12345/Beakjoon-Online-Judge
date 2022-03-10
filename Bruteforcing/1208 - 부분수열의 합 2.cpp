#include<iostream>
#include<map>

using namespace std;

/*
1. 문제 분석
- 변수
N: 수열의 수의 개수
S: 목표로 하는 합

- 변수 제한 사항
N: 1 ~ 40
S: -1,000,000 ~ 1,000,000
수열에 포함된 수: -100,000 ~ 100,000

- 문제 상황
 i번째 수부터 j번째 수까지의 합 A[i] + A[i+1] + … + A[j-1] + A[j]가 M이 되는 경우의 수를 구하여라

2. 풀이 계획

일단 10,000이 입력의 최대 크기이므로, 무작정 처음부터 돌리는 것은 불가능하다.

따라서 다음 순열을 실제 구해야 하는데, 다음 순열이라는 것은 어떻게 표현할까?

=> 정렬되는 과정이라고 볼 수도 있겠다.

3. 계획 검증


*/

enum FIRSTORSECOND { FIRST, SECOND };

int N, S;
int A[41];
int subsum[800000];
long long cnt;

void solution(int curIndex, int sum, int end, FIRSTORSECOND firstOrSecond) {
    if (curIndex == end) {
        // 첫번째 반쪽 배열에 대한 합들의 개수 기록해놓기
        if (firstOrSecond == FIRST) {
            // 하나의 수가 sum 자체일 때도 구해짐
            subsum[sum + 400000]++;

            // 공집합인 경우가 항상 포함되므로, subsum[0]은 1이 된다.
        }
        else { // 두번째 반쪽 배열을 계산할 시 두 수의 반
            // 하나의 수가 sum 자체일 때는
            cnt += subsum[S - sum + 400000];

            
        }
        return;
    }

    // 현재 수를 포함할 경우
    solution(curIndex + 1, sum + A[curIndex], end, firstOrSecond);
    // 현재 수를 포함하지 않을 경우
    solution(curIndex + 1, sum, end, firstOrSecond);
}

void meetInTheMiddle() {
    solution(0, 0, N / 2, FIRST);
    solution(N / 2, 0, N, SECOND);
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    meetInTheMiddle();

    // S가 0인 경우, 
    // 아무것도 뽑지 않았을 때 또한 하나의 경우의 수에 포함되므로 빼주기
    if (!S) cout << cnt - 1;
    else cout << cnt;

    return 0;
}
