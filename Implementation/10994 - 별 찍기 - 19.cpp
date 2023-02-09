#include<iostream>
using namespace std;

int N;

char star[500][500];

void drawStar(int n, int x, int y) {
    if (n == 1) {
        star[x][y] = '*';
        return;
    }

    int len = 4 * (n - 1) + 1;

    for (int j = y; j < y + len; j++) {
        star[x][j] = '*';
        star[x + len - 1][j] = '*';
    }

    for (int i = x; i < x + len; i++) {
        star[i][y] = '*';
        star[i][y + len - 1] = '*';
    }

    drawStar(n - 1, x + 2, y + 2);
    return;
}

void solution() {
    drawStar(N, 0, 0);
    for (int i = 0; i < 4 * N - 3; i++) {
        for (int j = 0; j < 4 * N - 3; j++) {
            cout << ((star[i][j]) ? star[i][j] : ' ');
        }
        cout << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    solution();
}
