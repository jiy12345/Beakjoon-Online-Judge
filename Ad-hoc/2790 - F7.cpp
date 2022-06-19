#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 300001

int arr[MAX];

int N;

int solution() {
    sort(arr, arr + N, greater<int>());

    int score = arr[0] + 1;
    int result = 1;

    for (int i = 1; i < N; i++) {
        if (arr[i] + N >= score) result++;

        score = max(score, arr[i] + i + 1);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << solution();
}