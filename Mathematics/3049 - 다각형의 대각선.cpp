#include <iostream>
using namespace std;

int main() {
    int N; 
    cin >> N;
    cout << N * (N - 1) * (N - 2) * (N - 3) / 24;
}