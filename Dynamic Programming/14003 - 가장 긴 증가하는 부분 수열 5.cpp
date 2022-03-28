#include<iostream>
#include<vector>
using namespace std;

// 값을 입력받을 배열
int A[1000000];
int index[1000000];

int N; // 수열의 길이

void solution() {

    vector<int> LIS;

    LIS.push_back(A[0]);
    index[0] = 1;

    for (int i = 1; i < N; i++) {
        // 현 위치의 수가 현재 기록중인 LIS의 모든 수보다 큰 수일 경우
        if (LIS.back() < A[i]) {
            LIS.push_back(A[i]);
            index[i] = LIS.size();
        }
        else { // 현 위치의 수보다 더 큰 수가 LIS에 있을 경우
            auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);
            *it = A[i];
            index[i] = it - LIS.begin() + 1;
        }
    }

    cout << LIS.size() << '\n';

    vector<int> answer(LIS.size());
    int cnt = LIS.size();
    for (int i = N - 1; i >= 0; i--) {
        if (index[i] == cnt) {
            answer[cnt - 1] = A[i];
            cnt--;
        }
    }

    for (int i = 0; i < LIS.size(); i++) {
        cout << answer[i] << " ";
    }
}

class E {
public:
    int e[30];

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //cin >> N;

    //for (int i = 0; i < N; i++) {
    //    cin >> A[i];
    //}

    E e;
    
    e.e[3] = 10;

    E f;
    f = e;

    cout << f.e[3];

    //solution();
}
