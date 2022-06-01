#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<char> dq;
int N, K;

void solution(string number) {
    for (unsigned int i = 0; i < number.length(); i++) {
        while (K && !dq.empty() && dq.back() < number[i]) {
            dq.pop_back();
            K--;
        }
        dq.push_back(number[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    string number;
    cin >> number;

    solution(number);

    for (int i = 0; i < dq.size() - K; i++) {
        cout << dq[i];
    }

    return 0;
}
