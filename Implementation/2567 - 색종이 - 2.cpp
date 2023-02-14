#include <iostream>
using namespace std;

int N, board[101][101];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void pastePaper(int x, int y) {
    for (int i = x; i < x + 10; i++) {
        for (int j = y; j < y + 10; j++) {
            board[i][j] = 1;
        }
    }
}


int solution() {
    int length = 0;
    int x, y;
    for (int i = 1; i <= N; i++) {
        cin >> x >> y;
        pastePaper(x, y);
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (board[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int next_i = i + dx[k];
                    int next_j = j + dy[k];
                    if (board[next_i][next_j] == 0) length++;
                }
            }
        }
    }

    return length;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cout << solution();
}