#include<iostream>
#include<vector>
using namespace std;

int n;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;

        a = b;
        b = r;
    }
    return a;
}

long long solution(vector<int> numbers) {
    long long answer = 0;

    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) 
            answer += gcd(numbers[i], numbers[j]);

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> numbers(n);

        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        cout << solution(numbers) << '\n';
    }

    return 0;
}