#include<iostream>
using namespace std;

long long minNum, maxNum;

bool isNN[1000001];

long long solution(long long minNum, long long maxNum) {
	// 전체 범위의 수의 개수를 일단 구해 놓기
	// 일단 모든 수를 제곱 ㄴㄴ 수로 생각
	long long answer = maxNum - minNum + 1;

	for (long long i = 2; i * i <= maxNum; i++)
	{	
		// 범위 내에서 가장 작은 제곱 수의 배수 구하기
		long long startNum = ((minNum % (i * i)) == 0) ? minNum : minNum / (i * i) * (i * i) +(i * i);

		for (long long j = startNum; j <= maxNum; j += i * i) {
			// 제곱 ㄴㄴ수가 아닌 수를 새로 발견할 때마다 표시
			if (!isNN[j - minNum]) {
				isNN[j - minNum] = true;
				// 전체 수에서 1 빼주기
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
