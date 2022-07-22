#include<iostream>
#include<queue>
using namespace std;

/*
1. 문제 분석
- 변수
N: 소수의 개수
M: 자연수의 최대값​

- 변수 제한 사항
N: 1 ~ 10
M: 1 ~ 10^12


- 문제 상황
 첫째 줄에 M 이하의 자연수 중에서 N개의 소수 중 적어도 하나로 나누어 떨어지는 수의 개수를 출력한다.

2. 풀이 계획
합집합으로 생각하면 될 것 같다.

1개만 뽑았을 때를 더하고,
2개씩만 뽑았을 때는 빼고,
3개씩만 뽑았을 때는 더하고,...
​

3. 계획 검증

 1. 알고리즘 측면

 알고리즘 측면에소 크게 문제가 될 부분은 보이지 않았다.

​

 2. 시간복잡도 측면

 시간 복잡도 측면에서는 좌표를 정렬하는 부분이 시간복잡도가 가장 높으며, C++의 sort 함수는 O(NlogN)의 시간복잡도를 보이므로, 10,000의 크기에 대해서는 문제 없이 동작할 듯 하다!

​

 3. 공간복잡도 측면

*/

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