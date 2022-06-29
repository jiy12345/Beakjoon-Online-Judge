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

void permutation() {
	int curSize = subSequence.size();
	if (curSize == M) {
		for (int i = 0; i < curSize; i++) {
			cout << subSequence[i] << " ";
		}
		cout << '\n';
		return;
	}

	int isUsed = 0;
	for (int i = 0; i < N; i++) {
		if (isPicked[i] == false &&sequence[i] != isUsed) {
			subSequence.push_back(sequence[i]);
			isUsed = sequence[i];
			isPicked[i] = true;
			permutation();
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
		cin >> sequence[i];
	}

	sort(sequence, sequence + N);

	permutation();
}