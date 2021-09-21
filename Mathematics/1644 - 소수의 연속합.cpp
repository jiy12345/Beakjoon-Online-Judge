#include<iostream>
#include<cmath>
#include<vector>
using namespace std;



/*
1. ���� �м�

- ����


- ���� ���� ����
1 <= N <= 4,000,000

 - ���� ��Ȳ
�ڿ��� N�� ���ӵ� �Ҽ��� ������ ��Ÿ�� �� �ִ� ����� ���� ���ϴ� ���α׷��� �ۼ��϶�!

2. Ǯ�� ��ȹ
 �Ҽ��ϸ� �Ƹ������׳׽��� ü�� ���� ���� ��������.
=> �Ҽ��� ���ϴ� �� ��ü�� �����ð� ���⵵�̹Ƿ�, ���� ���س����� �� �� ������, ���س��� �Ҽ��� ������ ���� ���� ����� ���� ���ϴµ� ���� �ð��� �ҿ�� �� �����Ƿ� �ִ��� ���̴� ���� ���� �� ����!

N/2�� �Ѿ�ٸ� ���ӵ� �Ҽ��� �տ� Ȱ��� �� �����Ƿ�, N/2������ �Ҽ��� ���ϸ� �ɰ� ����.

������ ���� ������ ��ġ��

1. N/2������ �Ҽ��� ���Ѵ�.
2. ���� �Ҽ��� ���� �迭�� ���� �տ������� �����ϸ�, ������ ���Ҹ� �������� �� ���� ���ҵ��� ���ʴ�� ��� ���Ѵ�.
 => ��� ���ذ��� ���� N�� ��ġ�ϸ� ����� �� ������ �ϳ� ������Ű��, 2������ ���ư� ���� ���Ҹ� �����Ѵ�.
 => ��� ���ذ��� ���� N�� �ʰ��ϸ� ���̻� ������ �ʰ� 2������ ���ư� ���� ���Ҹ� �����Ѵ�.

3. ��ȹ ����


*/


int solution(int N) {
	int answer = 0;

	vector<int> prime_num_vector;

	bool* PrimeArray = new bool[N + 1];

	/*  �迭�ʱ�ȭ: ó���� ��� �Ҽ��� ���� true���� ��	*/
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