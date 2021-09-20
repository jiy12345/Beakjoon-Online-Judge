#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<map>
#include<string>
using namespace std;



/*
1. 문제 분석

- 변수 제한 사항
종 이름의 길이 <= 30
입력된 종의 종류 수 <= 10,000
입력된 나무의 총 그루 수 <= 1,000,000

 - 문제 상황
 주어진 각 종의 이름을 사전순으로 출력하고, 그 종이 차지하는 비율을 백분율로 소수점 4째자리까지 반올림해 함께 출력

2. 풀이 계획
이름(문자열) 과 개수의 연결이므로 맵 자료형이 바로 떠올랐다.

다음과 같은 과정을 거치자

1. 문자열을 입력받으며, 해당 문자열에 해당하는 값을 1 증가시킨다.
2. 맵의 모든 값들의 합을 구한다.
3. 각 키와 맵의 각 값들을 2번에서 구한 합으로 나눈 값을 출력한다.

3. 계획 검증


*/

void solution() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string temp = "";

	map<string, int> trees;

	while(getline(cin, temp)) {
		trees[temp]++;
	}

	float sum = 0;
	map<string, int>::iterator it;
	for (it = trees.begin(); it != trees.end(); ++it) {
		sum+=it->second;
	}

	cout << fixed;
	cout.precision(4);
	for (it = trees.begin(); it != trees.end(); ++it) {
		cout << it->first << " " << it->second / sum * 100 << "\n";
	}

}

int main() {


	solution();

	return 0;
}