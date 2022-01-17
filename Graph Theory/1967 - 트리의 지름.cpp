#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

/*
1. 문제 분석
- 변수
n: 노드의 개수


- 변수 제한 사항
n: 1~10,000

간선의 가중치: 1~100

- 문제 상황

 트리의 노드와 간선의 가중치들이 주어질 때, 트리의 지름을 구하여라.

2. 풀이 계획
 트리의 지름이 될 수 있는 가능성이 있는 경로들은, 두 리프노드간의 거리이다.

리프노드가 아닐 경우 무조건 자식으로 한번 더 내려가 길어지기 때문이다!

따라서 리프 노드가 아닌 모든 노드에 대해 양측으로 가는 최대거리를 더하면 될 듯 하다.

3. 계획 검증

*/

int n;
bool isVisited[10002];
vector<pair<int, int>> node[10002];

pair<int, int> solution(int curPoint, int curDistance) {
    isVisited[curPoint] = true;

    int maxDistance = curDistance;
    int endPoint = curPoint;

    for (int i = 0; i < node[curPoint].size(); i++) {
        int distance = 0;
        int point = 0;

        int nextPoint = node[curPoint][i].first;
        if (isVisited[nextPoint] == false) {
            // 다음 지점을 nextPoint로 선택하였을 때의 지점과 최대 거리 받기
            pair<int, int> endPointdistance(solution(nextPoint, curDistance + node[curPoint][i].second));

            point = endPointdistance.first;
            distance = endPointdistance.second;
        }

        // 더 긴 경로 발견했다면 변경하기
        if (maxDistance < distance) {
            endPoint = point;
            maxDistance = distance;
        }
    }

    return make_pair(endPoint, maxDistance);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int parent, child, length;
    for (int i = 0; i < n - 1; i++) {
        cin >> parent >> child >> length;
        // 양방향 연결
        node[parent].push_back(make_pair(child, length));
        node[child].push_back(make_pair(parent, length));
    }

    // 루트노드에서 가장 멀리있는 정점 구하기
    int firstEndPoint = solution(1, 0).first;

    // 방문 표시 배열 0으로 초기화
    memset(isVisited, false, sizeof(isVisited));

    // 루트노드에서 가장 멀리있는 정점에서 가장 멀리 떨어진 정점 구하기
    cout << solution(firstEndPoint, 0).second;

    return 0;
}
