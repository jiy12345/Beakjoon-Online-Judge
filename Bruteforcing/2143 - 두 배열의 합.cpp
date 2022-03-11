#include<iostream>
#include<unordered_map>
#include<vector>
#include<numeric>

using namespace std;

/*
1. 문제 분석
- 변수
n: 수열 A의 수의 개수
m: 수열 B의 수의 개수
T: 목표가 될 수

- 변수 제한 사항
T: -1,000,000,000 ~ 1,000,000,000
n, m: 1 ~ 1,000
배열의 원소: -1,000,000 ~ 1,000,000


- 문제 상황
 부 배열은 어떠한 배열의 연속된 수들의 합이라고 하며,

 두 배열이 주어질 때 두 배열의 부배열의 합이 T가 되는 모든 부 배열 쌍의 개수를 구하는 프로그램을 작성하라!

2. 풀이 계획

map에 기록하면 될 듯 하고, 

2중 반복문을 돌려 연속합을 구하면 될 듯 하다.

3. 계획 검증


*/


int n, m, T;
vector<int> A(1000, 0);
vector<int> B(1000, 0);
unordered_map<int, int>subSum;

int solution() {
    long long answer = 0;

    // A의 합들 계산
    int prevSum = accumulate(A.begin(), A.begin() + n, 0);

    for (int i = 0; i < n; i++) {
        int curSum = prevSum;
        
        subSum[curSum]++;

        // A에서 한개도 뽑히지 않는 경우는 없어야 하므로 -1
        for (int j = 0; j < n - i - 1; j++) {
            curSum -= A[n - 1 - j];
            subSum[curSum]++;
        }
        prevSum -= A[i];
    }

    prevSum = accumulate(B.begin(), B.begin() + m, 0);
    for (int i = 0; i < m; i++) {
        int curSum = prevSum;

        answer += subSum[T - curSum];

        // B에서 한개도 뽑히지 않는 경우는 없어야 하므로 -1
        for (int j = 0; j < m - i - 1; j++) {
            curSum -= B[m - 1 - j];
            answer += subSum[T - curSum];
        }
        prevSum -= B[i];
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }    

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    cout << solution();

    return 0;
}
