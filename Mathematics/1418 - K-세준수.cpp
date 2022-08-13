#include <iostream>
using namespace std;

#define MAX 100001

int arr[MAX];
int N, K;

int solution() {
    int answer = 0;

    for (int i = 2; i <= N; i++) {
        if (arr[i]) continue;
        for (int j = i; j <= N; j += i)
            arr[j] = max(arr[j], i);
    }

    for (int i = 1; i <= N; i++) {
        if (arr[i] <= K) answer++;
    }

    return answer;
}

int main() {
    cin >> N >> K;

    cout << solution();

    return 0;
}