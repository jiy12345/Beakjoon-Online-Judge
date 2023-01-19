#include<iostream>
using namespace std;

int N;
int num_kim;
int num_lim;

int solution() {
	int num_competitors = 2;
	int round_num = 1;

	while (true) {
		if ((num_kim - 1) / num_competitors == (num_lim - 1) / num_competitors) {
			break;
		}
		num_competitors *= 2;
		round_num++;
	}

	return round_num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> num_kim >> num_lim;

	cout << solution();
}