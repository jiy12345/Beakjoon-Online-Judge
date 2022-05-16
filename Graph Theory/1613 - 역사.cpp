#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
n: 사건(노드)의 개수
k: 전후 관계(간선)의 개수

s: 사건의 전후 관계를 알고 싶은 사건 쌍의 수

- 변수 제한 사항
사건의 번호는 1 ~ n

n: 1 ~ 400
k: 1 ~ 50,000

s: 1 ~ 50,000

사건의 전후 관계가 모순인 경우는 없다.

- 문제 상황
 


2. 풀이 계획
 다익스트라 알고리즘을 통해 계속해서 최소 시간을 기록하되, 각 단계에서 비용이 초과되는 경로는 선택하지 않도록 한다!

3. 계획 검증
*/

#define MAX 401

int n, k, s;

int isComparable[MAX][MAX];

void floydWarshall() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (isComparable[i][k] != 0 && isComparable[i][k] == isComparable[k][j])
                    isComparable[i][j] = isComparable[i][k];
}

void solution() {
    floydWarshall();

    cin >> s;

    int a, b;
    for (int i = 0; i < s; i++) {
        cin >> a >> b;
        cout << isComparable[a][b] << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    int a, b;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;

        isComparable[a][b] = -1;
        isComparable[b][a] = 1;
    }

    solution();
}
