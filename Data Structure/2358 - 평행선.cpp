#include<iostream>
#include<unordered_map>
using namespace std;

int n;
unordered_map<int, int> x_coords;
unordered_map<int, int> y_coords;

int solution() {
	int num_parallel_lines = 0;

	for (auto coord_info : x_coords) {
		if (coord_info.second >= 2) {
			num_parallel_lines++;
		}
	}

	for (auto coord_info : y_coords) {
		if (coord_info.second >= 2) {
			num_parallel_lines++;
		}
	}

	return num_parallel_lines;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int x_coord, y_coord;
	for (int i = 0; i < n; i++) {
		cin >> x_coord >> y_coord;
		x_coords[x_coord]++;
		y_coords[y_coord]++;
	}

	cout << solution();
}