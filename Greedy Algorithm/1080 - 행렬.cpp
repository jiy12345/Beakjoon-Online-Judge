#include <iostream>
using namespace std;

int N, M;
char matrix[50][50];

int solution() {
    if (N < 3 || M < 3) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j]) {
                    return -1;
                }
            }
        }
        return 0;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j]) {
                if (i < N - 2 && j < M - 2) {
                    for (int x = i; x < i + 3; x++) {
                        for (int y = j; y < j + 3; y++) {
                            matrix[x][y] = !matrix[x][y];
                        }
                    }
                    cnt++;
                }
                else {
                    if (matrix[i][j]) {
                        return -1;
                    }
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];

    char num;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> num;

            if (matrix[i][j] != num) matrix[i][j] = 1;
            else matrix[i][j] = 0;
        }
    }

    cout << solution();

    return 0;
}

