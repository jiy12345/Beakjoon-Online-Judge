#include <iostream>
#include <algorithm>
using namespace std;

int N, B;

string solution() {
    string B_num;

    while (N != 0) {
        int tmp = N % B;
        if (tmp > 9) {
            tmp = tmp - 10 + 'A';
            B_num += tmp;
        }
        else {
            B_num += ('0' + tmp);
        }
        N /= B;
    }
    reverse(B_num.begin(), B_num.end());

    return B_num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> B;

    cout << solution() << '\n';

    return 0;
}