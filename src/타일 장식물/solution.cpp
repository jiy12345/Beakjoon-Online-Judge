#include <string>
#include<iostream>

using namespace std;

long long solution(int N);

int main() {
    int N = 80;
    cout << solution(N);
}

long long solution(int N) {
    long before = 1;
    long current = 1;
    long after;
    // ÇÇº¸³ªÄ¡ ¼ö¿­ ±¸ÇÏ±â
    for (int i = 0;i < N - 2;i++) {
        after = before + current;
        before = current;
        current = after;
    }
    after = before + current;
    long long answer = (current * 2) + (after * 2);
    return answer;
}
