#include <iostream>
using namespace std;

int H, W, X, Y;
int B[600][600];
int A[300][300];

void solution() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i - X >= 0 && j - Y >= 0) {
                A[i][j] = B[i][j] - A[i - X][j - Y];
            }
            else {
                A[i][j] = B[i][j];
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W >> X >> Y;

	for (int i = 0; i < H + X; i++) {
		for (int j = 0; j < W + Y; j++) {
			cin >> B[i][j];
		}
	}

	solution();

	return 0;
}
