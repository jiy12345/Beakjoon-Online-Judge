#include<iostream>
#include<algorithm>
using namespace std;

int T, W, N;
pair<int, int> spots[1000];

int solution() {
	int total_distance = 0;

	int cur_amount = 0;
	int cur_location = 0;
	for (int spot_index = 0; spot_index < N; spot_index++) {
		total_distance += spots[spot_index].first - cur_location;
		cur_amount += spots[spot_index].second;
		if (cur_amount < W) {
			cur_location = spots[spot_index].first;
		}
		else if(cur_amount == W) {
			total_distance += spots[spot_index].first;
			cur_location = 0;
			cur_amount = 0;
		}
		else {
			total_distance += spots[spot_index].first * 2;
			cur_location = spots[spot_index].first;
			cur_amount = spots[spot_index].second;
		}
	}

	total_distance += cur_location;

	return total_distance;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> W >> N;

		for (int j = 0; j < N; j++) {
			cin >> spots[j].first >> spots[j].second;
		}

		cout << solution() << '\n';
	}
}