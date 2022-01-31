#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N, M: N���� �ڿ��� �߿��� M���� �� ���������� �Է��� �Ǵ� ��

- ���� ���� ����
N, M: 1~8

- ���� ��Ȳ
N���� �ڿ��� �߿��� M���� �� ������ ��� ����Ѵ�.
�ߺ��Ǵ� ������ ������ ��µǼ��� �ȵȴ�.
������ ���������� �����ϴ� ������ ��µǾ�� �Ѵ�.

2. Ǯ�� ��ȹ
 �������� ���������̴�. ��ͷ� �����ϸ� �ɵ� �ϴ�.

 ���չ����� ���� �̹� ������ �� ���ķθ� �����ϹǷ� �����ߴ��� ���θ� ���� �ʿ䰡 �����µ�, ������ ��� �ұ�?


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int M, N;
int sequence[8];
bool isPicked[8];
vector<int>subSequence;

void solution() {
	int curSize = subSequence.size();
	if (curSize == M) {
		for (int i = 0; i < curSize; i++) {
			cout << subSequence[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (isPicked[i] == false) {
			subSequence.push_back(sequence[i]);
			isPicked[i] = true;
			solution();
			subSequence.pop_back();
			isPicked[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		sequence[i] = i + 1;
	}

	solution();
}