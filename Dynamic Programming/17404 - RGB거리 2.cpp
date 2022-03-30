#include<iostream>
using namespace std;

/*
1. ���� �м�
- ����
N: ���� ����

- ���� ���� ����
N: 2 ~ 1,000
���� ĥ�ϴ� ���: 1 ~ 1,000

- ���� ��Ȳ
 ������ ���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ϵ�, ������ ��Ģ�� �����Ͽ��� �Ѵٰ� �� ��,

 - 1�� ���� ���� 2��, N�� ���� ���� ���� �ʾƾ� �Ѵ�.
 - N�� ���� ���� N-1��, 1�� ���� ���� ���� �ʾƾ� �Ѵ�.
 - i(2 �� i �� N-1)�� ���� ���� i-1, i+1�� ���� ���� ���� �ʾƾ� �Ѵ�.

 ��� ���� ĥ�ϴ� ����� �ּڰ��� ���Ͽ���.

2. Ǯ�� ��ȹ
 ������ �Ǵ����� ���� ���� ���� ó���� ��������ν�, ����� �޶����ٴ� ���̴�.

 �� ������ ������ �� ó���� ������ ���� �˾ƾ� �Ѵ�.

 ������ ���̹Ƿ� ������ ������ ��� �ٲٵ� ����� ���� ���̴�.

 ���� ù��°�� N-1��°�� �����ϰ� => �̰� �ȵǴ°� ù��°�� �����ϴ��� �������� �����ϴ����� �˾ƾ� �Ѵ�.

 �׷��ٸ� ���� ������ �ϴ� ���� ���� ��������.


3. ��ȹ ����

*/


// �� ��ġ���� Ư�� ���� �������� ���� �ּҰ� ������ �迭
int min_nums[1000][3];
// ���� �Է¹��� �迭
int RGB_cost[1000][3];

int N; // ���� ��

int solution() {

	int answer = 1000 * 1000 + 1; // ���� �� �մ� �� �� �ִ밪

	for (int firstHouseColor = 0; firstHouseColor < 3; firstHouseColor++) // ù ��° ���� ������ �����Ͽ� �ݺ�
	{
		for (int i = 0; i < 3; i++)
		{
			// ù��° ���� ���� �����ϱ� ���� ������ ���� ���õ� �� ������ ������ ���� �ִ밪����
			if (i == firstHouseColor)
				min_nums[0][i] = RGB_cost[0][i]; 
			else
				min_nums[0][i] = 1000 * 1000 + 1;
		}

		// �� ��ġ������ �ִ밪 ���ϱ�
		for (int i = 1; i < N; i++)
		{
			min_nums[i][0] = min(min_nums[i - 1][1], min_nums[i - 1][2]) + RGB_cost[i][0];
			min_nums[i][1] = min(min_nums[i - 1][0], min_nums[i - 1][2]) + RGB_cost[i][1];
			min_nums[i][2] = min(min_nums[i - 1][0], min_nums[i - 1][1]) + RGB_cost[i][2];
		}

		for (int lastHouseColor = 0; lastHouseColor < 3; lastHouseColor++)
		{
			if (lastHouseColor == firstHouseColor) continue; // ù��° ���� ���� ������ ���� ���� ������ �ȵǹǷ� ��� X
			answer = min(answer, min_nums[N - 1][lastHouseColor]); // ������ ����� �ּڰ��� ����
		}

	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> RGB_cost[i][0] >> RGB_cost[i][1] >> RGB_cost[i][2];
	}

	cout << solution();
}