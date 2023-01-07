#include<iostream>
#include<utility>
using namespace std;

int n, m, t;

void solution() {
	int max_num_of_n = t / n;
	int max_num_of_m = t / m;
	
	int num_of_n, num_of_m;
	pair<int, int> cur_optimal = { 0, t };


	for(num_of_n = 0; num_of_n <= max_num_of_n; num_of_n++) {
		for (num_of_m = 0; num_of_m <= max_num_of_m; num_of_m++) {
			int cur_cola_time = t - (num_of_n * n + num_of_m * m);
			if (cur_cola_time < 0) break;

			int cur_num_of_burger = num_of_n + num_of_m;
			if (cur_optimal.second > cur_cola_time) {
				cur_optimal.first = cur_num_of_burger;
				cur_optimal.second = cur_cola_time;
			}
			else if (cur_optimal.second == cur_cola_time) {
				if (cur_optimal.first < cur_num_of_burger) {
					cur_optimal.first = cur_num_of_burger;
					cur_optimal.second = cur_cola_time;
				}
			}
		}
	}

	cout << cur_optimal.first << ' ' << cur_optimal.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> t;
	solution();
}