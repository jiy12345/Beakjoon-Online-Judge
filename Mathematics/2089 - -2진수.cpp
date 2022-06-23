#include <iostream>
#include <algorithm>
using namespace std;

string solution(int n) {
    if (n == 0) {
        return "0";
    }

    string result;
    while (n != 0) {
        if (n % -2 == 0) {
            result += "0";
            n /= -2;
        }
        else {
            result += "1";
            n = (n - 1) / -2;
        }
    }
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    cout << solution(n) << '\n';

    return 0;
}