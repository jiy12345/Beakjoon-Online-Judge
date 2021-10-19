#include <iostream>
#include <string>
#include <algorithm>
#include <cstring> //memset
using namespace std;

/*
1. 문제 분석
- 변수
N: 동전의 종류
k: 가치의 합 목표

- 변수 제한 사항
N: 1~50

배열의 각 원소: 1~1,000
- 문제 상황
 수열 P를 배열 A에 적용한 배열 B는
 B[P[i]] = A[i]
 비내림차순: 바로 앞의 원소와 같을 수도 있는 오름차순
 배열 A가 주어졌을 때, 수열 P를 적용한 결과가 비내림차순으로 정렬되도록하는 수열 P를 구하라
2. 풀이 계획
따라서 자세한 계획은 다음과 같다.
1. 배열을 입력받은 후 정렬한다. 매칭한 배열을 활용하기 위해 현재 배열의 상태는 유지한다.
2. 정렬한 내용을 유지하고, 정렬한 내용을 각 인덱스와 매칭하여 맵으로 만든다.
3. 맵을 각 키를 원래 입력된 배열의 순서대로 집어넣는다.
3. 계획 검증
*/


const int MAX = 100 + 1;

int N, M;

string cache[MAX][MAX];



// long long 자료형으로 처리되지 않는 범위의 수를 처리해야 하므로, 문자열로 변환한 후 덧셈을 진행! 
string bigNumberAdd(string num1, string num2) {

    // 각 자리수간의 합을 처리할 변수
    int sum = 0;

    string result;
    //1의 자리부터 더하기 시작한다
    while (!num1.empty() || !num2.empty() || sum) {

        if (!num1.empty()) {
            sum += num1.back() - '0';
            num1.pop_back();
        }

        if (!num2.empty()) {
            sum += num2.back() - '0';
            num2.pop_back();
        }

        //다시 string 형태로 만들어 push_back
        result.push_back((sum % 10) + '0');

        // 합이 10이 넘어 올려야 하는 수 다음 자리 수 계산에 반영!
        sum /= 10;
    }

    //1의 자리부터 result에 넣었으므로 뒤집어주기
    reverse(result.begin(), result.end());

    return result;

}


// 조합의 분할정복
// nCr = n-1Cr + n-1Cr-1
string combination(int n, int r){
    // 기저사례
    if (n == r || r == 0)
        return "1";

    // nCr 계산 결과 기록해놓기
    string& result = cache[n][r];

    if (result != "")

        return result;

    result = bigNumberAdd(combination(n - 1, r - 1), combination(n - 1, r));

    return result;
}



int main() {
    cin >> N >> M;
    cout << combination(N, M) << endl;

    return 0;

}