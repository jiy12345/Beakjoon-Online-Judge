#include <iostream>
#include <string>
#include <algorithm>
#include <cstring> //memset
using namespace std;

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
