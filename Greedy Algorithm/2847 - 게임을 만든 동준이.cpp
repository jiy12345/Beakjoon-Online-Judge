#include<iostream>
using namespace std;

int N;
int level_points[100];

int solution() {
	int points_reduced = 0;
	for (int i = N - 2; i >= 0; i--) {
		if (level_points[i + 1] <= level_points[i]) {
			int point_to_reduce = level_points[i] - level_points[i + 1] + 1;
			points_reduced += point_to_reduce;
			level_points[i] -= point_to_reduce;
		}
	}

	return points_reduced;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> level_points[i];
	}

	cout << solution();

}