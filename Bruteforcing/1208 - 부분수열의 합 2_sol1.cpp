#include<iostream>
#include<map>

using namespace std;

enum FIRSTORSECOND { FIRST, SECOND };

int N, S;
int A[41];
map<int, int> subsum;
long long cnt;

void solution(int curIndex, int sum, int end, FIRSTORSECOND firstOrSecond) {
    if (curIndex == end) {
        // 첫번째 반쪽 배열에 대한 합들의 개수 기록해놓기
        if (firstOrSecond == FIRST) {
            // 하나의 수가 sum 자체일 때도 구해짐
            subsum[sum]++;

            // 공집합인 경우가 항상 포함되므로, subsum[0]은 1이 된다.
        }
        else { // 두번째 반쪽 배열을 계산할 시 두 수의 반
            // 하나의 수가 sum 자체일 때는
            cnt += subsum[S - sum];

            
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
    for (pair<int, int> i : subsum) {
        cout << "sum: " << i.first << ", numOfSum: " << i.second << endl;
    }
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
