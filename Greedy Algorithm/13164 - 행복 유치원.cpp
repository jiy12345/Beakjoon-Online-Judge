#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 300000

int N, K;
int height[MAX];

int solution() {
    int answer = 0;

    vector<int> diff(N - 1);
    for (int i = 0; i < N - 1; i++)
        diff[i] = height[i + 1] - height[i];

    sort(diff.begin(), diff.end(), greater<int>());

    for (int i = K - 1; i < diff.size(); i++)
        answer += diff[i];

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> height[i];

    cout << solution() << endl;

    return 0;
}
