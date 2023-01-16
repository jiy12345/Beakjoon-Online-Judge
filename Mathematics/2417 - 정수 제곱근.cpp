#include<iostream>
#include<cmath>
using namespace std;

unsigned long long input_number;

unsigned long long solution() {
    if (input_number == 0) return 0;
    unsigned long long left = 1;
    unsigned long long right = sqrt(input_number) + 1;

    while (left <= right) {
        unsigned long long mid = (left + right) / 2;
        if (mid * mid < input_number) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}
int main() {
    cin >> input_number;
    cout << solution();
}