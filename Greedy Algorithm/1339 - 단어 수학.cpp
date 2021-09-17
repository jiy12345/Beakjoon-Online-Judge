#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

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

	// 빈도와 자리수를 고려했을 때 가장 우선순위가 높은 알파벳부터 숫자 매기기
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
