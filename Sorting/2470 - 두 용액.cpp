#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: ��ü ����� ��

- ���� ���� ����
 N: 2~100,000

 �� ����� Ư����: -1,000,000,000~1,000,000,000

- ���� ��Ȳ
�� ����� Ư�������� �־��� ��, �� ����� ȥ���Ͽ��� �� Ư������ 0�� ���� ����� ����� ������ �� ����� Ư������ ����Ѵ�.

����ؾ� �ϴ� �� ����� Ư������ ������������ ����Ѵ�.

2. Ǯ�� ��ȹ

 ������ ���� 3���� ��Ȳ�� ���� �� �ִ�.

1. 0�� ������ ����� �����ϴ� ���
 => ���� ���� �� ���� ����ϸ� �ȴ�.

2. 0�� ������ ������ �����ϴ� ���
 => ���� ���� �� ���� ����ϸ� �ȴ�.

3. ������ ����� �����ִ� ���
 �ΰ��� �����͸� ����Ͽ� �� ���� ������ ���� ū ����, �� ���� ����� ���� ���� ���� ����Ű�� �ϰ�, 
 �� ���� ���� ����� ���� ������ �۾����� ������
 �� ���� ���� ������ ���� ����� Ŀ���� ������ �̵��ϵ��� �Ͽ� ��� ���� Ž���� �� �� ����� ȥ���Ͽ��� ���� Ư������ ���� �۾��� ���� �� ����� Ư������ ����Ѵ�!

3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

int N;


vector<int> solutions; // ��׵�


void solution() {
	sort(solutions.begin(), solutions.end());

    int answer[2] = {0, 0};

    int leftPtr = 0; 
    int rightPtr = N - 1;
    int min = 2000000000;
    while (leftPtr < rightPtr) {
        int sum = solutions[leftPtr] + solutions[rightPtr];

        // ������ �ʿ��� ���
        if (min > abs(sum)) {
            min = abs(sum);
            answer[0] = solutions[leftPtr];
            answer[1] = solutions[rightPtr];

            if (sum == 0)
                break;
        }

        if (sum < 0)
            leftPtr++;
        else
            rightPtr--;
    }

    cout << answer[0] << " " << answer[1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		solutions.push_back(temp);
	}

	solution();
}