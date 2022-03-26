#include<iostream>
#include<vector>
using namespace std;

int dp[1000] = { 0, };

vector<int> LIS[1000];

// 값을 입력받을 배열
int A[1000] = { 0, };

int N; // 수열의 길이

// 가장 긴 수열을 저장하고 있는 인덱스
int cur_max_index;
int cur_max_size;

int solution() {
    int answer = 0;
    dp[0] = 1;
    LIS[0].push_back(A[0]);

    if (N == 1) {
        return 1;
    }

    for (int i = 1;i < N;i++) {
        dp[i] = 1;
        for (int j = i - 1;j >= 0;j--) {
            if (A[j] < A[i]) {
                if (dp[i] < dp[j] + 1) {
                    // 수열의 길이 저장
                    dp[i] = dp[j] + 1;

                    LIS[i].clear();
                    // 이전에 구해진 수열을 이용하여 구하기
                    for (int k = 0;k < LIS[j].size();k++) {
                        LIS[i].push_back(LIS[j][k]);
                    }


                    if (LIS[i].size() > cur_max_size) {
                        cur_max_size = LIS[i].size();
                        cur_max_index = i;
                    }
                }
            }
        }
        LIS[i].push_back(A[i]);
        answer = max(dp[i], answer);
    }
    return answer;
}

int main() {
    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> A[i];
    }

    cout << solution() << '\n';

    for (int i = 0;i < LIS[cur_max_index].size();i++) {
        cout << LIS[cur_max_index][i] << " ";
    }
}
