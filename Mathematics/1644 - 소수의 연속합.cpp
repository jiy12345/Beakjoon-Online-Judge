#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int solution(int N) {
	int answer = 0;

	vector<int> prime_num_vector;

	bool* PrimeArray = new bool[N + 1]; // 소수 판정을 위한 배열 true: 소수/ false: 소수 아님

	// 처음에는 모든 수를 소수로 보고 true로 초기화
	for (int i = 2; i <= N; i++)
		PrimeArray[i] = true;

	// i * i <= N인 소수들 까지만 판단하면 된다고 알려져 잇음
	for (int i = 2; i * i <= N; i++)
	{
		if (PrimeArray[i]) // 현재 소수로 판단되어 있는 수에 대해
			for (int j = i * i; j <= N; j += i) // 해당 소수의 배수들은 모두 소수가 아닌 것으로 표시
				PrimeArray[j] = false;
	}

	for (int i = 2; i <= N; i++) { // bool형으로 표시된 소수들을 모두 vector에 담기
		if (PrimeArray[i] == true) {
			prime_num_vector.push_back(i);
		}
	}

	for (int i = 0; i < prime_num_vector.size(); i++) {
		int sum = prime_num_vector[i];
		for (int j = i + 1; j < prime_num_vector.size(); j++) {
			sum += prime_num_vector[j];
			if (sum >= N) { // 현재까지 합한 수가 N이상일 경우 빠져나가기
				break;
			}
		}
		if (sum == N) { // 합이 N과 같다면 경우의 수 변수 +1
			answer++;
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
