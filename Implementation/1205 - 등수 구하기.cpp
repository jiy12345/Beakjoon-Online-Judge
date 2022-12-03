#include<iostream>
using namespace std;

int N, cur_point, P;

int solution() {
	int cur_rank = 1;
	int num_of_ranked = 0;
	for (num_of_ranked; num_of_ranked < N; num_of_ranked++) {
		int ranked_point;
		cin >> ranked_point;
		if (ranked_point > cur_point)
			cur_rank++;
		if (ranked_point < cur_point)
			break;
	}

	return (num_of_ranked < P) ? cur_rank : -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> cur_point >> P;
	cout << solution();
}