#include<iostream>
#include<vector>
using namespace std;

// 값을 입력받을 배열
int A[1000000] = { 0, };

int N; // 수열의 길이

int solution() {
    int answer = 0;

    vector<int> LIS;

    LIS.push_back(A[0]);

    for (int i = 1; i < N; i++) {
        // 현 위치의 수가 현재 기록중인 LIS의 모든 수보다 큰 수일 경우
        if (LIS.back() < A[i]) {
            LIS.push_back(A[i]);
        }
        else { // 현 위치의 수보다 더 큰 수가 LIS에 있을 경우
            auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);
            *it = A[i];
        }
    }

    answer = LIS.size();

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solution();
}
