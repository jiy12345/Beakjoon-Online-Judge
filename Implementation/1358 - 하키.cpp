#include<iostream>
using namespace std;

int W, H, X, Y, P, R;

bool IsInLink(int x, int y) {
	if ((x >= X && x <= X + W) && (y >= Y && y <= Y + H))
		return true;
	else if (
		R * R >= (X - x) * (X - x) + (Y + R - y) * (Y + R - y) || 
		R * R >= (X + W - x) * (X + W - x) + (Y + R - y) * (Y + R - y))
		return true;
	return false;
}

int solution() {
	int num_of_players_in_link = 0;
	for (int i = 0; i < P; i++) {
		int x, y;
		cin >> x >> y;
		if (IsInLink(x, y))
			num_of_players_in_link++;
	}

	return num_of_players_in_link;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> W >> H >> X >> Y >> P;
	R = H / 2;
	cout << solution();
}