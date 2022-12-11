#include<iostream>
#include<iomanip>
using namespace std;

int N, M, K;



int Combination(int N, int K) {
    int p = 1;
    int c = 1;
    while (K > 0)
    {
        c *= N--;
        p *= K--;
    }
    return c / p;
}

double solution() {
    double answer = 0.0;
    double p = Combination(N, M);
    while (M >= K)
    {
        if (N - M < M - K)
        {
            K++;
            continue;
        }

        double c = Combination(M, K) * Combination(N - M, M - K);

        answer += c / p;
        K++;
    }

    return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
    cout << setprecision(10) << solution();
}