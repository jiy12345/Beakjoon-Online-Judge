#include<iostream>
using namespace std;

#define MAX 501

int N, M;

int isComparable[MAX][MAX];

void floydWarshall() {
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (isComparable[i][k] != 0 && isComparable[i][k] == isComparable[k][j])
                    isComparable[i][j] = isComparable[i][k];
}

int solution() {
    int answer = 0;
    floydWarshall();

    bool knowable;
    for (int i = 1; i <= N; i++) {
        knowable = true;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (isComparable[i][j] == 0) {
                knowable = false;
                break;
            }
        }

        answer += knowable;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        isComparable[a][b] = 1;
        isComparable[b][a] = -1;
    }

    cout << solution();
}
