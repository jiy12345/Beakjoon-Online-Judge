#include<iostream>
#include<string>
using namespace std;

int N;

long long solution() {
    long long answer = 0;
    for (int i = 1; i <= N; i++) {
        answer += (N / i) * i;
    }

    return answer;
}

int main() {

    cin >> N;

    cout << solution();

    return 0;
}
