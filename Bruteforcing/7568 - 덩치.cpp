#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. ���� �м�
- ����
N: ����� ��
x, y: �� ����� Ű�� ������

- ���� ���� ����
N: 2~50
x, y: 10~200

- ���� ��Ȳ
�� ����� ��ġ ����� ���Ͽ� �� ������� ����϶�

2. Ǯ�� ��ȹy1
�ϴ� ���� �Է��� ���� ��, �����Ը� ���ذ����� ��� ������ ��, 

�� ����� ����� ����� ���� �ٽ� ��ġ �������� �����ϸ� �� �� �ϴ�!

3. ��ȹ ����
*/

vector<vector<int>> people;
int N;

// ������ �������� �����ϱ� ���� ���Լ�
bool compare1(vector<int>person1, vector<int>person2) {
	return person1[0] > person2[0];
}

// ���� �������� �ٽ� �����ϱ� ���� ���Լ�
bool compare2(vector<int>person1, vector<int>person2) {
	return person1[2] > person2[2];
}


void solution() {
	// ���� �� ����
	sort(people.begin(), people.end());

	// ù ����� ������
	int cur_min = people[0][1];

	for (int i = 0;i < N;i++) {

		/*cout << people[i][0] << people[i][1] << people[i][2] << endl;*/
	}
}

int main() {
	
	cin >> N;
	for (int i = 0;i < N;i++) {
		int x, y;
		cin >> x >> y;
		people.push_back({ x,y,i });
	}

	solution();
}