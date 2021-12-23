#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

/*
1. ���� �м�

- ����

min, max: ������ ó���� ��

- ���� ���� ����
min: 1~1,000,000,000,000
max: min~min+1,000,000

 - ���� ��Ȳ
 � ���� X�� 1���� ū �������� ������ �������� ���� ��, �� ���� ���� ��������� �Ѵ�.

  min, max�� �־��� ��, min�� max ���� ������ �ִ� ���� �������� � �ִ��� ����϶�.

2. Ǯ�� ��ȹ
 �����佺�׳׽��� ü�� Ȱ���ϵ�, �� ���� ���� ���� �����ؾ� �� �� �ϴ�!


3. ��ȹ ����


*/


long long minNum, maxNum;

bool isNN[1000001];

long long solution(long long minNum, long long maxNum) {
	long long answer = maxNum - minNum + 1;

	// �����佺�׳׽��� ü�� 9999������ �Ҽ� ���ϱ�
	for (long long i = 0; i <= maxNum - minNum; i++)
		isNN[i] = true;

	for (long long i = 2; i * i <= maxNum; i++)
	{	
		long long startNum = ((minNum % (i * i)) == 0) ? minNum : minNum / (i * i) * (i * i) +(i * i);

		//cout << "i: " << i << ", ";
		//cout << "startNum: " << startNum << ", ";
		//cout << "minNum % (i * i): " << minNum % (i * i) << ", ";
		//cout << "minNum / (i * i): " << minNum / (i * i) << endl;

		for (long long j = startNum; j <= maxNum; j += i * i) {
			if (isNN[j - minNum]) {
				isNN[j - minNum] = false;
				answer--;
			}
		}				
	}

	return answer;
}

int main() {
	cin >> minNum >> maxNum;

	 cout << solution(minNum, maxNum);

	return 0;
}