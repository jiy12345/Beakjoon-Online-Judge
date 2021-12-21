#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isPrime[1003002];

bool isPalindrome(string cur_num) {
	string cur_num_not_reversed = cur_num;
	reverse(cur_num.begin(), cur_num.end());
	string cur_num_reversed = cur_num;

	if (cur_num_not_reversed == cur_num_reversed) {
		return true;
	}
	else {
		return false;
	}
}

int solution(int N) {
	if (N <= 2) {
		return 2;
	}

	// 에라토스테네스의 체로 소수 구해놓기
	for (int i = 2; i <= 1003001; i++)
		isPrime[i] = true;
	for (int i = 2; i * i <= 1003001; i++)
	{
		if (isPrime[i])
			for (int j = i * i; j <= 1003001; j += i)
				isPrime[j] = false;
	}

	for (int i = N; i <= 1003001; i++) {
		// 팰린드롬 수이며, 소수일 경우 빠져나가기
		if (isPalindrome(to_string(i)) && isPrime[i]) {
			return i;
		}
	}
}

int main() {
	int N;

	cin >> N;

	cout << solution(N);

	return 0;
}
