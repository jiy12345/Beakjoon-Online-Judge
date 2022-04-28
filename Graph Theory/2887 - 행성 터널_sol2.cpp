#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: �༺�� ��
x, y, z: �༺�� ��ġ�� 3���� ��ǥ

- ���� ���� ����
N: 1 ~ 100,000
x, y, z: -1,000,000,000 ~ 1,000,000,000

�� ��ġ�� �༺�� �� �� �̻� �ִ� ���� ����.

- ���� ��Ȳ
 N���� �༺�� ��ġ�� �־����� ��, �ͳ��� �� N - 1�� �Ǽ��Ͽ� ��� �༺�� ���� ����ǰ� �ϴµ� �ʿ��� �ּ� ����� ���ϴ� ���α׷��� �ۼ��϶�

�� �༺ A(xA, yA, zA)�� B(xB, yB, zB)��
�ͳη� ������ �� ��� ����� min(|xA-xB|, |yA-yB|, |zA-zB|)�̴�.

2. Ǯ�� ��ȹ
 ��� �༺���� �Ÿ��� ���ϸ� ���ϱ�� �ϰ�����, �׷��� �� ���

 4 x 100,000 x 100,000 = 40,000,000,000����Ʈ = 40�Ⱑ ����Ʈ�� �����Ƿ� �޸𸮰� �ʰ��� ���̴�.

 ���� �ð� ���⵵�� ���� �ð� ���� ������ �� �� ���̴�.

 �׷��ٸ� ��� �ؾ��ұ�?



 �Ÿ� ��� ���� ���캸��

 min(|xA-xB|, |yA-yB|, |zA-zB|)


 ũ�罺Į �˰����� �����ϱ� ���ؼ��� �� ��Ȳ������ �ּҰ��� ���� ������ ���ؾ� �Ѵ�.

 �� ��Ȳ���� �ּҺ���� ���� ������ �����ϱ� ���ؼ��� � �������� ����س��� �ұ�?

 �ϴ� �� ��ġ���� ����� �� �ִ� �������� ���� �� ���� ���� ����� ��� ������ �����ؾ� �ϴ� ���� �´�.

 �׷��� �� ������ �����Ϸ� �� �� �̹� ����Ǿ� �ִ� �������� �����̸� �����ϸ� �ȵǹǷ�, �Ѿ�� �Ѵ�.

 ���� ��ü �׷�� ������� ���� ���� � ���͵� ����Ŭ�� �̷��� �ʱ� ������ ���� �ּ� ������ �����ϸ� �ȴ�.

 ���� �� ��忡�� ���� ����� ���� ������ �����ϴ� ����

3. ��ȹ ����
*/

#define MAX 100000

int N;
// �� ��ǥ���� �����Ͽ� ����
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;

// ����ġ, ��� �༺, ���� �༺ ������ ����
vector<vector<int>> possibleLinks;
int Parent[MAX];


int findParent(int x) {
	if (Parent[x] == x) return x;
	else return Parent[x] = findParent(Parent[x]);
}

void Union(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x != y) Parent[y] = x;
}

bool isSameParent(int x, int y) {
	return findParent(x) == findParent(y);
}

void getPossibleLinks() {
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N - 1; i++) {
		//                      �߻��ϴ� ���                      ��� �༺    ���� �༺
		possibleLinks.push_back({ abs(X[i].first - X[i + 1].first), X[i].second, X[i + 1].second });
		possibleLinks.push_back({ abs(Y[i].first - Y[i + 1].first), Y[i].second, Y[i + 1].second });
		possibleLinks.push_back({ abs(Z[i].first - Z[i + 1].first), Z[i].second, Z[i + 1].second });
	}

	sort(possibleLinks.begin(), possibleLinks.end());
}

int kruskal() {
	int answer = 0;

	for (int i = 0; i < N; i++) {
		Parent[i] = i;
	}

	for (vector<int> cur_link : possibleLinks) {
		if (isSameParent(cur_link[1], cur_link[2]) == false) {
			Union(cur_link[1], cur_link[2]);
			answer += cur_link[0];
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		// �� ��ǥ���� ����
		X.push_back({ x, i });
		Y.push_back({ y, i });
		Z.push_back({ z, i });
	}

	getPossibleLinks();

	cout << kruskal();
}