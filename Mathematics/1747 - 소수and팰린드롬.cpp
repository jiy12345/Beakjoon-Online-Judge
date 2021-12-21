#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
1. 문제 분석

- 변수
N: 기준이 될 수

- 변수 제한 사항
N: 1~1,000,000

 - 문제 상황
 어떤 수 N에 대해, N보다 크거나 같고, 소수이면서 팰린드롬인 수 중에 가장 작은 수를 구하여라

2. 풀이 계획
 소수를 구하기 위해서는 계속해서 소수를 구하며 vector에 추가하고, N이상일 때부터는 펠린드롬 수인지도 체크하여 빠져나가면 될 듯 하다!


3. 계획 검증


*/

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

	for (int i = 2; i <= 1003001; i++)
		isPrime[i] = true;


	for (int i = 2; i * i <= 1003001; i++)
	{
		if (isPrime[i])
			for (int j = i * i; j <= 1003001; j += i)
				isPrime[j] = false;
	}

	for (int i = N; i <= 1003001; i++) {
		// 팰린드롬 수일 경우 빠져나가기
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