#include<iostream>
#include<string>
using namespace std;

int N, k;

int solution() {
    int answer = 0;
    int digit = 1;
    int tenSquared = 1;

    while (k > digit * tenSquared * 9) {
        k -= (digit * tenSquared * 9);
        answer = answer + tenSquared * 9;
        digit++;
        tenSquared *= 10;
    }


    // 몇번째 숫자인지 구하기
    answer = (answer + 1) + (k - 1) / digit;

    //cout << answer << endl;

    return (answer > N) ? -1 : (to_string(answer)[(k - 1) % digit] - '0');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> k;

	cout << solution();
}
