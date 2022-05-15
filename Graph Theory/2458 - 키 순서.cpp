#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 물건의 개수
M: 측정된 물건 쌍의 개수

- 변수 제한 사항
N: 5 ~ 100
M: 0 ~ 2000

- 문제 상황



2. 풀이 계획
 다익스트라 알고리즘을 통해 계속해서 최소 시간을 기록하되, 각 단계에서 비용이 초과되는 경로는 선택하지 않도록 한다!

3. 계획 검증
*/

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

        answer += knowable ? 1 : 0;
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
