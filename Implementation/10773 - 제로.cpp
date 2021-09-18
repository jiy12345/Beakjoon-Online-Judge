#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

/*
1. 문제 분석

 - 변수
K: 주어지는 정수의 개수

 - 변수, 값에 대한 제한
K의 범위 1~100,000 => O(NlogN) 혹은 그보다 효율적인 알고리즘 설계
정수는 0~1,000,000 사이의 값을 가진다.
최종적으로 적어낸 수의 합은 2^31-1보다 작거나 같은 정수 => int형에 저장 가능

 - 문제 상황
받아온 정수가 0일 경우 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다!

2. 풀이 계획
가장 최근에 쓴 수를 지운다는 것이서 FILO(First In Last Out)이 바로 생각났고, stack구조로 구현할 수 있겠다는 생각을 했다.

정수가 0일 경우에 지울 수 있는 수가 보장되므로, 0일 경우 스택이 비어있는지 체크할 필요는 없다.

그런데 c++에는 vector라는 편리한 구조가 있으므로 사용하자.

자세한 구조는 다음과 같다.

1. 입력을 받으며 숫자를 벡터에 입력하고, 0이 입력될 경우 벡터에서 수를 pop 한다.
2. 마지막에 모든 수를 더한다.


3. 계획 검증
각 값이 나오는 빈도와 자릿수를 모두 고려하여 합한 값이 정렬기준이 되었으므로, 내림차순으로 정렬한 값들에 정렬한 순서대로 매긴다면 최대값을 구할 수 있다!

 */

int get_sum(int K) {

	int temp;
	vector<int> num_vector;

	for (int i = 0; i < K; i++) {
		cin >> temp;
		if (temp == 0) {
			num_vector.pop_back();
		}
		else {
			num_vector.push_back(temp);
		}

	}

	return accumulate(num_vector.begin(), num_vector.end(), 0);
}

int main() {

	int K; // 단어의 개수

	cin >> K;

	cout << get_sum(K);

	return 0;
}