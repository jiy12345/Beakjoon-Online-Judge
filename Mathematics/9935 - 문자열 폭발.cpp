#include<iostream>
#include<vector>
#include<sstream>
#include<deque>
using namespace std;

/*
1. ���� �м�


- ���� ���� ����
1 <= ���ڿ��� ���� <= 1,000,000
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


// KMP ����
//// �����Լ� ����(���λ�� ���̻� �ִ� ��ġ ���� ��)
//vector<int> makeTable(string pattern) {
//    int patternSize = pattern.size();
//
//    vector<int> table(patternSize, 0);
//
//    int j = 0;
//    for (int i = 1; i < patternSize; i++) {
//
//        // j �ε����� 0�̻��ε�, i��°�� j��° ���ڰ� ��ġ���� �ʴ´ٸ�, 
//        while (j > 0 && pattern[i] != pattern[j]) {
//            j = table[j - 1]; // �� ĭ �ڷ� �� 
//        }
//
//        if (pattern[i] == pattern[j]) {
//            table[i] = ++j;
//        }
//    }
//
//    return table;
//}
//
//int KMP(string data, string pattern) {
//    int index = -1;
//    vector<int> table = makeTable(pattern);
//
//    int parentSize = data.size();
//    int patternSize = pattern.size();
//
//    int j = 0;
//    for (int i = 0; i < parentSize; i++) {
//        while (j > 0 && data[i] != pattern[j]) {
//            j = table[j - 1]; // ��ġ ���� �ʾ��� ��, ���� �ܰ迡 �ִ� ������ �̵� 
//        }
//        if (data[i] == pattern[j]) {
//            if (j == patternSize - 1) {
//                index = (i - patternSize + 1);
//
//                data = data.substr(0, index) + data.substr(index + pattern.size());
//                i = ((index - patternSize)>0)? (index - patternSize) : -1;
//                j = ((table[j] - patternSize) > 0) ? (table[j] - patternSize) : 0;
//                parentSize = data.size();
//
//                //cout << "index: " << index << endl;
//                //cout << "parent size:" << parentSize << endl;
//                //cout << "i: " << i << endl;
//                //cout << endl;
//            }
//            else {
//                j++; // �ܼ��� ��Ī�� �̷������ ������ j�� �������� ��Ī Ȯ�� 
//            }
//        }
//        parentSize = data.size();
//    }
//
//    if (data.empty()) {
//        cout << "FRULA";
//    }
//    else {
//        cout << data;
//    }
//
//    return index;
//}

void solution(string data, string pattern) {
	string stack;

	for (int i = 0; i < data.size(); i++) {
		stack += data[i];

		if (stack.size() >= pattern.size()) {
			string temp = stack.substr(stack.size() - pattern.size());
			if(temp == pattern) {
				int cnt = 0;
				while (cnt < pattern.size()) {
					stack.pop_back();
					cnt++;
				}
			}
		}
	}
	if (stack.empty()) {
		cout << "FRULA";
	}
	else {
		cout << stack;
	}
}

int main() {
	string data, pattern; // ATM�� �� ���ִ� ����� ��

	cin >> data;
    cin >> pattern;

	solution(data, pattern);

	return 0;
}
