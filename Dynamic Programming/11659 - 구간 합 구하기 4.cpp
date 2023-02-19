#include<iostream>
using namespace std;

int N, M;
int sum_to_index[100001];

int solution(int start_num, int end_num) {
	return sum_to_index[end_num] - sum_to_index[start_num - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int input_num;
	cin >> input_num;
	sum_to_index[1] = input_num;
	for (int i = 2;i <= N;i++) {
		cin >> input_num;
		sum_to_index[i] = sum_to_index[i - 1] + input_num;
	}

	for (int i = 0;i < M;i++) {
		int start_num, end_num;
		cin >> start_num >> end_num;
		cout << solution(start_num, end_num) << '\n';
	}
}