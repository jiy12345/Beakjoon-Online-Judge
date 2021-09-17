#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

/*
1. 문제 분석

 - 변수
N: 주어지는 단어의 개수

 - 변수, 값에 대한 제한
단어의 개수는 1~10개이다.
단어는 알파벳 대문자로만 이루어진다.
모든 단어에 포함되어 있는 알파벳은 최대 10개이다.
각 단어의 최대 길이는 8이다
서로 다른 문자는 서로 다른 숫자를 나타낸다.

 - 문제 상황
 첫째 줄에 주어진 단어의 합의 최댓값을 출력한다.

2. 풀이 계획
 => 각 값들을 정확히 출력하는 것이 아니므로, 전체를 합한 최댓값을 각 단어를 단어 그대로 보는 것이 아니라 각 알파벳별로 정리하여 조작이 가능하다!


 따라서 각 알파벳에 해당하는 배열을 만든 후, 자리수 위치에 따라 1, 10, 100, ... 을 각 알파벳의 자리에 넣어준 후 해당 배열을 정렬하여 값을 계산한다!
=> 각 값들을 정확히 출력하지 않아도 되므로, 임의의 순서로 바뀌어도 상관이 없다!

따라서 자세한 과정은 다음과 같다.

1. 각 단어를 받으며, 각 단어의 한 자리씩 해당하는 알파벳의 위치에 자리수를 곱하여 더해준다.
2. 모든 단어를 처리후 받은 배열을 내림차순으로 정리한다.
3. 가장 앞부터 10개의 값에 9부터 0을 각각 곱하여 모두 합한다.

3. 계획 검증
각 값이 나오는 빈도와 자릿수를 모두 고려하여 합한 값이 정렬기준이 되었으므로, 내림차순으로 정렬한 값들에 정렬한 순서대로 매긴다면 최대값을 구할 수 있다!

 */

int get_min_num(string *words, int N) {

	int max_num = 0; // 합한 값을 더할 변수
	int alpha_num[26] = { 0, }; // 각 단어의 가중치를 기록해줄 변수

	for (int i = 0; i < N; i++) {
		int word_length = words[i].length();
		for (int j = 0; j < word_length; j++) {
			// 각 알파벳에 해당하는 배열의 위치에 값 더해주기
			alpha_num[words[i][j] - 65] += pow(10, word_length - (j + 1));
		}
	}

	// 값 정렬하기
	sort(alpha_num, alpha_num + 26, greater<int>());


	for (int i = 0; i < 10; i++) {
		max_num += alpha_num[i] * (9 - i);
	}

	return max_num;
}

int main() {

	int N; // 단어의 개수

	cin >> N;

	string* words = new string[N];

	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}

	cout << get_min_num(words, N);

	return 0;
}