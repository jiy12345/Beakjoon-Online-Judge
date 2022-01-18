#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

/*
1. ���� �м�
- ����
V: ����� ����


- ���� ���� ����
n: 2~100,000

������ ����ġ: 1~100

- ���� ��Ȳ

 Ʈ���� ���� ������ ����ġ���� �־��� ��, Ʈ���� ������ ���Ͽ���.

2. Ǯ�� ��ȹ
 Ʈ���� ������ �� �� �ִ� ���ɼ��� �ִ� ��ε���, �� ������尣�� �Ÿ��̴�.

������尡 �ƴ� ��� ������ �ڽ����� �ѹ� �� ������ ������� �����̴�!

���� ���� ��尡 �ƴ� ��� ��忡 ���� �������� ���� �ִ�Ÿ��� ���ϸ� �� �� �ϴ�.

3. ��ȹ ����

*/

int V;
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
            // ���� ������ nextPoint�� �����Ͽ��� ���� ������ �ִ� �Ÿ� �ޱ�
            pair<int, int> endPointdistance(solution(nextPoint, curDistance + node[curPoint][i].second));

            point = endPointdistance.first;
            distance = endPointdistance.second;
        }

        // �� �� ��� �߰��ߴٸ� �����ϱ�
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

    cin >> V;

    int parent, child, distance;
    for (int i = 0; i < V - 1; i++) {
        cin >> parent;

        while (true) {
            cin >> child;
            if (child == -1) {
                break;
            }
            cin >> distance;

            // ����� ����
            node[parent].push_back(make_pair(child, distance));
            node[child].push_back(make_pair(parent, distance));
        }

    }

    // ��Ʈ��忡�� ���� �ָ��ִ� ���� ���ϱ�
    int firstEndPoint = solution(1, 0).first;

    // �湮 ǥ�� �迭 0���� �ʱ�ȭ
    memset(isVisited, false, sizeof(isVisited));

    // ��Ʈ��忡�� ���� �ָ��ִ� �������� ���� �ָ� ������ ���� ���ϱ�
    cout << solution(firstEndPoint, 0).second;

    return 0;
}
