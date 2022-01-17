#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

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
