#include<iostream>
#include<cstring>
using namespace std;


/*
1. ���� �м�
- ����
T: �׽�Ʈ ���̽��� ��
r: �л��� ��

 - ���� ���� ����
n: 2 ~ 100,000

- ���� ��Ȳ
�л�����(s1, s2, ..., sr)�̶� �� ��, r=1�̰� s1�� s1�� �����ϴ� ��쳪, s1�� s2�� �����ϰ�, s2�� s3�� �����ϰ�,..., sr-1�� sr�� �����ϰ�, sr�� s1�� �����ϴ� ��쿡�� �� ���� �� �� �ִ�.

������Ʈ ���� ������ ���� �л����� ���� ��Ÿ����

2. Ǯ�� ��ȹ
 ���� ����Ʈ ���·� �׷����� ������ ��, ����Ŭ�� �̷� ��� ������, �׷��� ���� ��� ���� ������ �ʴ� ������ ǥ��

 �ϴ� ����Ŭ�� ã�ƾ� �ϴ� ������ �´�.

 ������ �Ǵ� �κ��� �����ϱ�?

����Ŭ üũ�� �湮���� ���� ��� �� ���� ��尡 �ƴ� ����� ��쿡 üũ�ϰ� �ִµ�,

�̷��� �� ��� �ٸ� ��ο��� ����Ŭ�� �������� ��츦 üũ���� ���Ѵ�.

�׷��ٸ� ��� �ؾ��ұ�?

����Ŭ�� �ϼ��� ��� ���� ǥ�����ִ� ���� ���?
 => ����Ŭ�� �ϴ� �ϼ��Ǹ� �ٸ� ������� ���� �̷���� �����Ƿ�, �ƿ� �湮���� ���ϵ��� �ϴ� ���̴�.

�ϴ�

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

#define MAX 100001

int T, n, numIsInTeam;
int graph[MAX];
int prevNode[MAX];

bool isVisited[MAX];
bool searchCompleted[MAX];

void findTeam(int nodeNum) {

	isVisited[nodeNum] = true;

	int next = graph[nodeNum];

	if (!isVisited[next]) findTeam(next);

	//�̹� �湮������ Ž���� ���� ��尡 �ƴ϶�� ����Ŭ
	else if (!searchCompleted[next]) {
		// ���� ���ԵǴ� �ο� ����
		for (int i = next; i != nodeNum; i = graph[i])
			numIsInTeam++;
		numIsInTeam++;
	}

	// ���� ���κ��� ���� ��� ��� Ž�� �Ϸ�
	searchCompleted[nodeNum] = true;
}

int solution() {
	for (int i = 1; i <= n; i++) {
		if (isVisited[i] == false) {
			findTeam(i);
		}
	}

	return n - numIsInTeam;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		numIsInTeam = 0;
		memset(isVisited, false, sizeof(isVisited));
		memset(searchCompleted, false, sizeof(searchCompleted));
		cin >> n;

		for (int student = 1; student <= n; student++) {
			cin >> graph[student];
		}

		cout << solution() << '\n';
	}

	return 0;
}