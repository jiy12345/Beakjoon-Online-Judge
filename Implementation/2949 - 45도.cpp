#include<iostream>
using namespace std;

char s[101][101];
char t[101][101];
int R, C, K;

void rotate(int r) {
    int i, j, k;
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (r == 45)t[i + j][R - 1 - i + j] = s[i][j];
            else if (r == 90)t[j][R - 1 - i] = s[i][j];
        }
    }
    if (r == 45) { R += C; C += R; }
    else if (r == 90) { k = R; R = C; C = k; }
    
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            s[i][j] = t[i][j];
            t[i][j] = 0;
        }
    }
}

void solution() {
    for (int i = 0; i < K / 90; i++) rotate(90);
    if (K % 90 / 45)rotate(45);

    for (int i = 0; i < R; i++) {
        int c = 0;
        for (int j = 0; j < C; j++) {
            c = s[i][j] ? j : c;
            s[i][j] = s[i][j] ? s[i][j] : ' ';
        }
        s[i][c + 1] = 0;
        puts(s[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> s[i][j];
    cin >> K;

    solution();
}