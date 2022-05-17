#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
N: 도시의 개수

- 변수 제한 사항

s: 1 ~ 50,000

사건의 전후 관계가 모순인 경우는 없다.

- 문제 상황



2. 풀이 계획
 다익스트라 알고리즘을 통해 계속해서 최소 시간을 기록하되, 각 단계에서 비용이 초과되는 경로는 선택하지 않도록 한다!

3. 계획 검증
*/

#define MAX 21

int N;
int graph[MAX][MAX];
// true: 길이 있음
// false: 길이 없음
// 일단 모든 노드간의 길이 있다고 가정
bool road[MAX][MAX];

bool floydWarshall(void) {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (i == j || j == k || i == k)
                    continue;
                // 플로이드가 성립하지 않는 경우
                // 즉 현재 측정된 거리가 최단 거리가 아닌 경우!
                else if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    return false;
                }
                // i -> j로 가는 간선은 i -> k, k -> j 간선 두개로 대체될 수 있으며,
                // 이럴 경우 간선의 개수를 줄일 수 있음
                else if (graph[i][j] == graph[i][k] + graph[k][j])
                    road[i][j] = true;
            }
    return true;
}

int solution() {
    int result = 0;

    if(!floydWarshall()) return -1;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!road[i][j])
                result += graph[i][j];

    return result / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    cout << solution();
}
