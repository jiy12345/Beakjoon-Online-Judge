#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

/*
1. 문제 분석

- 변수

min, max: 범위의 처음과 끝

- 변수 제한 사항
min: 1~1,000,000,000,000
max: min~min+1,000,000

 - 문제 상황
 어떤 정수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 그 수를 제곱 ㄴㄴ수라고 한다.

  min, max가 주어질 때, min과 max 사이 범위에 있는 제곱 ㄴㄴ수가 몇개 있는지 출력하라.

2. 풀이 계획
 에라토스테네스의 체를 활용하되, 각 수의 제곱 수로 진행해야 할 듯 하다!


3. 계획 검증


*/


long long minNum, maxNum;

bool isNN[1000001];

long long solution(long long minNum, long long maxNum) {
	long long answer = maxNum - minNum + 1;

	// 에라토스테네스의 체로 9999까지의 소수 구하기
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