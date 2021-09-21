#include<iostream>
#include<cmath>
#include<vector>
using namespace std;



/*
1. 문제 분석

- 변수


- 변수 제한 사항
1 <= N <= 4,000,000

 - 문제 상황
자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하라!

2. 풀이 계획
 소수하면 아리스토테네스의 체가 가장 먼저 떠오른다.
=> 소수를 구하는 것 자체는 선형시간 복잡도이므로, 먼저 구해놓으면 될 듯 하지만, 구해놓은 소수가 많아질 수록 합의 경우의 수를 구하는데 많은 시간이 소요될 수 있으므로 최대한 줄이는 것이 좋을 것 같다!

N/2을 넘어간다면 연속된 소수의 합에 활용될 수 없으므로, N/2까지의 소수만 구하면 될것 같다.

다음과 같은 과정을 거치자

1. N/2까지의 소수를 구한다.
2. 구한 소수를 담은 배열을 가장 앞에서부터 참조하며, 참조한 원소를 기준으로 그 뒤의 원소들을 차례대로 모두 더한다.
 => 계속 합해가다 값이 N과 일치하면 경우의 수 변수를 하나 증가시키고, 2번으로 돌아가 다음 원소를 참조한다.
 => 계속 합해가다 값이 N을 초과하면 더이상 합하지 않고 2번으로 돌아가 다음 원소를 참조한다.

3. 계획 검증


*/


int solution(int N) {
	int answer = 0;

	vector<int> prime_num_vector;

	bool* PrimeArray = new bool[N + 1];

	/*  배열초기화: 처음엔 모두 소수로 보고 true값을 줌	*/
	for (int i = 2; i <= N; i++)
		PrimeArray[i] = true;

	for (int i = 2; i * i <= N; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= N; j += i)
				PrimeArray[j] = false;
	}

	for (int i = 2; i <= N; i++) {
		if (PrimeArray[i] == true) {
			prime_num_vector.push_back(i);
		}
	}

	for (int i = 0; i < prime_num_vector.size(); i++) {
		int sum = prime_num_vector[i];
		if (sum == N) {
			answer++;
			break;
		}
		for (int j = i + 1; j < prime_num_vector.size(); j++) {
			sum += prime_num_vector[j];
			if (sum == N) {
				answer++;
				break;
			}
			else if (sum > N) {
				break;
			}
		}
	}

	return answer;
}

int main() {

	int N;

	cin >> N;

	cout << solution(N);

	return 0;
}