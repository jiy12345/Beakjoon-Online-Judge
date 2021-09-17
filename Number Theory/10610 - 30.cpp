#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

void solution(string N) {

	vector<int> num_vector;

	for (int i = 0; i < N.size(); i++) {
		num_vector.push_back(N[i] - 48);
	}

	sort(num_vector.begin(), num_vector.end(), greater<int>());

	// 3의 배수가 아니거나 10의 배수가 아니면 -1 출력
	if (accumulate(num_vector.begin(), num_vector.end(), 0) % 3 != 0 || num_vector[num_vector.size() - 1] != 0) {
		cout << -1;
	}
	else {
		for (int i = 0; i < num_vector.size(); i++) {
			cout << num_vector[i];
		}
	}
}

int main() {
	string N;

	cin >> N;

	solution(N);

	return 0;
}