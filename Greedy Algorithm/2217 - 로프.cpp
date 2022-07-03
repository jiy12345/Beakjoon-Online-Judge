#include <iostream>
#include <algorithm>
using namespace std;

int rope[100001];
int N;

long long solution() {
    long long answer = 0;

    sort(rope, rope + N, greater<int>());

    for (int i = 0; i < N; i++) {
        long long sum = rope[i] * (i + 1);
        if (sum > answer)
            answer = sum;
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> rope[i];

    cout << solution();

    return 0;
}
