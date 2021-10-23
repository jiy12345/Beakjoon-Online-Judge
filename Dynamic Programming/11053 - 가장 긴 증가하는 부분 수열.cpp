#include<iostream>
using namespace std;


int max_lengths[1000] = { 0, };
// 값을 입력받을 배열
int A[1000] = { 0, };

int N; // 수열의 길이

int solution() {
    int answer = 0;
    max_lengths[0] = 1;
    for (int i = 0;i < N;i++) {
        int max_num = 0;
        for (int j = i - 1;j >= 0;j--) {
            if (A[j] < A[i] && max_lengths[j] > max_num) {
                max_num = max_lengths[j];
            }
        }
        max_lengths[i] = max_num + 1;
        answer = max(max_lengths[i], answer);
    }
    return answer;
}

int main() {
    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> A[i];
    }

    cout << solution();
}
