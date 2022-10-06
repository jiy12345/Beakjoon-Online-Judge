#include<iostream>
#include<vector>
using namespace std;

vector <int> prime;
int isNotPrime[10001], N;

void makePrime() {
    for (int i = 2; i * i <= 10000; i++) {
        if (isNotPrime[i]) continue;
        for (int j = i + i; j <= 10000; j += i) isNotPrime[j] = 1;
    }

    for (int i = 2; i <= 10000; i++) {
        if (!isNotPrime[i]) prime.push_back(i);
    }
}

int solution() {
    makePrime();

    int answer  = 0;
    for (int i = 0; i < prime.size() - 1; i++) {
        int mul = prime[i] * prime[i + 1];
        if (mul > N) {
            answer = mul; 
            break; 
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    cout << solution();
}