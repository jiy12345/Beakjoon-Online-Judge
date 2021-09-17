#include<iostream>
#include<vector>
#include<sstream>
#include<deque>
using namespace std;

/*
1. ���� �м�

 - ����
T: �׽�Ʈ ���̽��� ����
p: �� �׽�Ʈ ���̽��� ������ �Լ�
n: �迭�� �ִ� ���� ����


- ���� ���� ����
1 <= T <= 100
1 <= pd�� ���� <= 100,000   => ���� �Ź� ������ �Ϳ��� ������ �־�δ�1
1 <= n <= 10,000

p�� ������ �հ� nd�� ���� 700,000�� ���� ����

 - ���� ��Ȳ
AC���� R�� �迭 ������ ������ ������, D�� ù��° ���ڸ� ������! �迭�� ����ִµ� D�� ����ϸ� ������ �߻��Ѵ�!

2. Ǯ�� ��ȹ
�Ź� �������� �ݺ��� �����ϸ� ����� ���� �ɸ����̴�!

���� is_reversed ������ �����Ͽ� ������ �������� �ȹٷ� �� �������� �� ǥ���ϰ�

���� �ϳ� �������� ������ ���¶�� �տ��� �ϳ��� ������, �������� ���� ���¶�� �ڿ��� �ϳ��� ������!
 => �� �ڿ��� ��� ������ �̷�����Ƿ� deque�� ����ϴ� ���� ȿ������ �� �ϴ�!
���������� ������ ���¶�� ����� ����Ѵ�!

1. �׽�Ʈ ���̽� ������ �Է¹޴´�.
2. �׽�Ʈ ���̽� ������ ũ�⸸ŭ �ݺ����� ������, AC�� �迭�� �Է¹޴´�.
3. �迭�� �Է¹��� ����  2n+1(���ȣ�� ��ǥ�� �����Ͽ�) ���� ���ڸ� �о� ������ ���Ϳ� �����ϵ��� �Ѵ�.


������ ���� ������ ��ġ��


3. ��ȹ ����

*/

void solution(int T) {

	// 1. ���� �� ���Ϳ� �ޱ�
	for (int i = 0; i < T; i++) {
		bool is_reversed = false; // true�� ������ ��!
		int j;

		// AC �Է¹ޱ�
		string AC;
		cin >> AC;

		deque<int> num_array;

		int n;
		cin >> n;

		string num_array_string;
		cin >> num_array_string;

		num_array_string = num_array_string.substr(1, num_array_string.size() - 2); // ���ȣ ����
		
		stringstream sstream(num_array_string);
		string word;


		if (!num_array_string.empty()) {
			while (getline(sstream, word, ','))
			{
				num_array.push_back(stoi(word));
			}
		}


		for (j = 0; j < AC.size(); j++) {
			if (AC[j] == 'R') {
				is_reversed = !is_reversed;
			}
			else if(AC[j] == 'D') {
				if (num_array.empty()) { // D�� ���Դµ� �迭�� ������� ��� error
					cout << "error" << endl;
					break;
				}
				if (is_reversed) { // ������ ������ ���
					//cout << "pop_front" << endl;
					num_array.pop_back();
				}
				else { // �ȹٸ� ������ ���
					//cout << "pop_back" << endl;
					num_array.pop_front();
				}
			}
		}

		if (j != AC.size()) { // �ݺ����� ������ ���� �ʾ��� ��� = error�� �߰��� �߻����� ��� => ������� ����
			continue;
		}


		int array_size = num_array.size();

		if (is_reversed) {
			cout << "[";
			for (j = 0; j < array_size; j++) {
				if (j == array_size - 1) {
					cout << num_array[array_size - (j + 1)];
					break;
				}
				else {
					cout << num_array[array_size - (j + 1)]<<",";
				}
			}
			cout << "]" << endl;
		}
		else {
			cout << "[";
			for (j = 0; j < array_size; j++) {
				if (j == array_size - 1) {
					cout << num_array[j];
					break;
				}
				else {
					cout << num_array[j] << ",";
				}
			}
			cout << "]" << endl;
		}
	}
}

int main() {
	int T; // ATM�� �� ���ִ� ����� ��

	cin >> T;

	solution(T);

	return 0;
}