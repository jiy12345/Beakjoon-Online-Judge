#include <iostream>
#include <string>
using namespace std;

int N, B, H, W;
int p, a;

void solution() {
	int minCost = B + 1;

	for (int i = 0; i < H; i++) {
		bool isPossible = false;

		cin >> p;

		for (int j = 0; j < W; j++) {
			cin >> a;
			if (a >= N) isPossible = true;
		}

		if (isPossible) {
			minCost = min(minCost, p * N);
		}
	}

	cout << ((minCost == B + 1) ? "stay home" : to_string(minCost)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> B >> H >> W;
	
	solution();
}