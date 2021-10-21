#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: ���� ����

- ���� ���� ����
N: 2~1,000

- ���� ��Ȳ
 �� ��ġ�� ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �־����� ��, �ٷ� ���� ���� ���� ���� ĥ������ �����鼭 ��� ���� ĥ�ϴ� ����� �ּҰ��� ���϶�!


2. Ǯ�� ��ȹ

��������� �����ϵ� �� ��ġ���� Ư�� ���� �������� ���� �ּҰ��� �����س��´�.
Ư�� ��ġ���� Ư�� ���� �������� ���� �ּ� ����� ������ � ���� �����ϵ��� ��� ����

���� �ڼ��� ��ȹ�� ������ ����.
1. 3���� �迭�� ���� ĥ�� �� ��� ����� �Է¹޴´�.
2. BFS�� N��° ������ ��Ģ�� ���� �� ���� �����ϴ� �ڵ带 �����Ѵ�.
 => �� �� �ش� ��ġ���� ����� �� ���� �������� ���� �ּҰ��� �����Ѵ�.
*/

// �� ��ġ���� Ư�� ���� �������� ���� �ּҰ� ������ �迭
int min_nums[1000][3] = { {0, } };
// ���� �Է¹��� �迭
int RGB_cost[1000][3] = { {0, } };

int N; // ���� ��

// 00, 01, 10

// n: � ��ġ�� �������� ������ ����
// RGB: � ���� �����ߴ����� ������ ����
int solution(int n, int RGB) {
	// �̹� ���� �ּҰ��� ���� ��� �״�� ��ȯ
	if (min_nums[n][RGB] != 0) {
		return min_nums[n][RGB];
	}
	else {
		// ������ � ���� �����ߴ��Ŀ� ���� �ּҰ��� ������ ����
		vector<int> previous_min_num;
		for (int i = 0;i < 3;i++) {
			// ���� ���� �ٸ����� ����ϱ�
			if (i != RGB) {
				previous_min_num.push_back(solution(n - 1, i));
			}
		}
		// �� ��ġ�� ���� 
		min_nums[n][RGB] = RGB_cost[n][RGB] + *min_element(previous_min_num.begin(), previous_min_num.end());
		return min_nums[n][RGB];
	}
}

int main() {

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> RGB_cost[i][0] >> RGB_cost[i][1] >> RGB_cost[i][2];
	}

	// ù ��ġ�� �ּҰ����� ù ��ġ�� ��� �״���̹Ƿ� �״�� ����
	for (int i = 0;i < 3;i++) {
		min_nums[0][i] = RGB_cost[0][i];
	}

	// ������ ���� ���� 3���� �� ��� �����ϹǷ� ��� �õ�!
	vector<int> previous_min_num;
	for (int i = 0;i < 3;i++) {
		// 0���� �����ϴ� �ε����̹Ƿ� N-1�� ������
		previous_min_num.push_back(solution(N - 1, i));
	}

	cout<< *min_element(previous_min_num.begin(), previous_min_num.end());
}