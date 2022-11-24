#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> numOfQuot;

int solution() {
    sort(numOfQuot.begin(), numOfQuot.end());

    int maxNum = -1;
    for (int k = 0; k <= n; k++)
        for (int i = 0; i < n; i++)
            if (numOfQuot[i] >= k && k <= n - i && n - k <= i + 1)
                maxNum = k;

    return maxNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

    numOfQuot.resize(n);
    for (int i = 0; i < n; i++)
        cin >> numOfQuot[i];

    cout << solution();
}