#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int get_sum(int K) {

	int temp;
	vector<int> num_vector;

	for (int i = 0; i < K; i++) {
		cin >> temp;
		if (temp == 0) { // 0이 입력되었을 경우 마지막 수 제거
			num_vector.pop_back();
		}
		else { // 0 이외의 수는 push
			num_vector.push_back(temp);
		}

	}
	// 벡터의 모든 값 더한 값 리턴
	return accumulate(num_vector.begin(), num_vector.end(), 0);
}

int main() {

	int K; // 주어지는 정수의 개수

	cin >> K;

	cout << get_sum(K);

	return 0;
}
