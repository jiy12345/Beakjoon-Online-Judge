#include<iostream>
#include<vector>
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ũ��
A: ������ ���ԵǴ� ����

- ���� ���� ����
N: 1~10
A: -10~10

- ���� ��Ȳ
�����̰� �� ���� A��� �ϸ�, A[i]�� �����̰� i��° �� ���̴�. 
- S[i][j]�� A[i]���� A[j]���� ���� 0���� ũ�� +, 0�̸� 0, 0���� ������ -�̴�. (i<=j) 

�� S �迭�� �־����� ��, �����̰� �� N���� �� A�� ���϶�

2. Ǯ�� ��ȹ

- ��ͷ� �����ϵ�, �� j��° �ܰ迡���� ���� �ܰ踦 ��ģ��.
 1. j���� �۰ų� ���� ��� i�� ���� S[i][j]�� ���� �ܰ�κ��� �Ѿ�� ���� ����Ͽ�, ������ A[j]�� ������ ���Ѵ�.
 2. ������ ������ ���� �ݺ��� �����Ͽ� ����� �����ܰ踦 �����ϵ�, �� �� ������ A[j]�� ���� ������ ���� �����ܰ�� �ѱ��.
 3. j�� N-1�� �� ������ ���ϰ�, �� �� ���� ������(�ƹ��ų� ��� ������)�� ����ϰ� ��͸� �����Ѵ�.

3. ��ȹ ����


*/

int N;
char S[10][10];
vector<int>A;
int curSum[10];

// �ϳ� ã���� ����
bool solution(int cur_j) {
	// ���� ���ϱ�
	int maxNum = +10;
	int minNum = -10;

	for (int i = 0; i <= cur_j; i++) {
		// curSum + A[j] > 0
		if (S[i][cur_j] == '+') {
			// A[j] > -curSum
			minNum = max(minNum, -curSum[i] + 1); // �� ���Ǻ��δ� and�����̹Ƿ� �� ���� ���� ����!
		} // curSum + A[j] = 0
		else if (S[i][cur_j] == '0') {
			// A[j] = -curSum 
			minNum = max(minNum, -curSum[i]);
			maxNum = min(maxNum, -curSum[i]);
		}
		else { // curSum + A[j] < 0
			// A[j] < -curSum
			maxNum = min(maxNum, -curSum[i] - 1); // �� ���Ǻ��δ� and�����̹Ƿ� �� ���� ���� ����!
		}
	}

	//cout << "cur_j: " << cur_j << endl;
	//cout << "maxNum: " << maxNum << endl;
	//cout << "minNum: " << minNum << endl;
	//for (int i = 0; i < A.size(); i++) {
	//	cout << "curSum[" << i << "]: " << curSum[i] << endl;
	//}
	//cout << "A: ";
	//for (int i = 0; i < A.size(); i++) {
	//	cout << A[i] << " ";
	//}
	//cout << endl;
	//cout << endl;

	// ���� ����
	if (cur_j == N - 1) {
		if (maxNum >= minNum) {
			A.push_back(minNum);
			for (int i = 0; i < A.size(); i++) {
				cout << A[i] << " ";
			}

			return true;
		}
		else {
			return false;
		}
	}

	// ������ ���� �ݺ� ����
	for (int i = minNum; i <= maxNum; i++) {
		// ����� �� ������ �߰��Ͽ��� ���� ����
		A.push_back(i);
		for (int j = 0; j < A.size(); j++) {
			curSum[j] += i;
		}
		if (solution(cur_j + 1)) {
			return true;
		}
		for (int j = 0; j < A.size(); j++) {
			curSum[j] -= i;
		}
		A.pop_back();
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			cin >> S[i][j];
		}
	}

	solution(0);
}