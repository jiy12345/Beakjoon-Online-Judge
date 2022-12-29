#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, num;
vector<int> A, B;

void solution() {
    vector<int> diff_set;
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) {
        if (!binary_search(B.begin(), B.end(), A[i])) {
            diff_set.push_back(A[i]);
        }
    }
    sort(diff_set.begin(), diff_set.end());
    cout << diff_set.size() << '\n';
    for (int element : diff_set) {
        cout << element << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> N >> M;

    A.resize(N);
    B.resize(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    solution();
}