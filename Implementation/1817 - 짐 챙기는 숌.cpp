#include<iostream>
using namespace std;

// å�� ���ʴ�� ���� ���ۿ� ����.
// => �Էµ� ������� üũ�ϸ� �ȴ�.

// ������ å�� ���԰� �ִ�.
// ��� �ڽ��� ���� ���� �� �ִ� ���Ը� ������.
// 
// N: å�� ���� 0 ~ 50
// M: �ڽ��� ���� �� �մ� �ִ� ���� 0 ~ 1,000
// 
// 1. �Էµ� å�� ���� �ݺ����� ������, �ʿ��� �ڽ��� ������ ����.
//  => ���� �ڽ��� �� ���Ը� üũ�Ѵ�.
//  => ���� �ڽ��� �� ���� + ���� å�� ���԰� �ڽ��� �Ѱ�ġ�� �Ѿ�� ���� �ڽ��� å�� ��´�.
//

int N, M;

int solution() {
	int answer = 0;
	int curBox = M;

	for (int i = 0; i < N; i++) {
		int bookWeight;
		cin >> bookWeight;

		if (curBox + bookWeight > M) {
			answer++;
			curBox = bookWeight;
		}
		else
			curBox += bookWeight;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	cout << solution();

	return 0;
}