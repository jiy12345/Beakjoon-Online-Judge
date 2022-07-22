#include<iostream>
#include<queue>
using namespace std;

int N;
long long M;
int primeNumbers[10];
long long answer;

void combination(int k, int prevPickedIndex, vector<int> curPickedNum) {
    if (k == curPickedNum.size()) {
        long long divisor = 1;

        for (int pickedNum : curPickedNum)
            divisor *= pickedNum;

        // 짝수 개 => 빼기
        if (k % 2 == 0) answer -= (M / divisor);
        // 홀수 개 => 더하기
        else answer += (M / divisor);

        return;
    }

    for (int i = prevPickedIndex + 1; i < N; i++) {
        curPickedNum.push_back(primeNumbers[i]);
        combination(k, i, curPickedNum);
        curPickedNum.pop_back();
    }
}

long long solution() {
    vector<int>curPickedNum;
    for (int i = 1; i <= N; i++)
        combination(i, -1, curPickedNum);

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> primeNumbers[i];

    cout << solution();
}
