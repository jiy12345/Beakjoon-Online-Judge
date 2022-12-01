#include<iostream>
using namespace std;

int M, N;

int solution() {
	int min_six_strings = 1000;
	int min_one_string = 1000;

	int six_strings, one_string;
	for (int i = 0; i < M; i++) {
		cin >> six_strings >> one_string;
		min_six_strings = min(min_six_strings, six_strings);
		min_one_string = min(min_one_string, one_string);
	}

	int num_of_sets = N / 6;
	int num_of_single_strings = N % 6;

	int answer = min_six_strings * num_of_sets +
		min(min_six_strings, num_of_single_strings * min_one_string);

	answer = min(answer, N * min_one_string);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	cout << solution();
}