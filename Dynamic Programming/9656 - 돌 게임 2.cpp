#include<iostream>
using namespace std;

#define SK true;
#define CY false;

int N;
bool dp[1001];

string solution()
{
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for (int i = 4; i <= N; i++)
    {
        if (dp[i - 1] == 0 || dp[i - 3] == 0) dp[i] = 1;
        else dp[i] = 0;
    }

    if (dp[N] == 1) return "SK";
    else return "CY";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cout << solution();
}