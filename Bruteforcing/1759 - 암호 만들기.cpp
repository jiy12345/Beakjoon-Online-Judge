#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string vowel = "aeiou";

/*
1. 문제 분석

- 변수
L: 암호의 길이
C: 사용된 문자의 길이

- 변수 제한
3 <= L <= C <= 11

- 문제 상황
알파벳은 암호 내에서 항상 증가하는 순서로 배열되어야 한다.
암호는 최소 한 개의 모음과 두 개의 자음으로 구성되어 있어야 한다.
이 때, 가능한 모든 암호를 출력한다.

2. 풀이 계획
하나의 선택: 알파벳 하나 선택

- 기저 사례: L개의 알파벳 선택

일단 증가하는 순서이므로 정렬이 이루어져야 할 것 같다.

=> 현재 단계에서 가능한 알파벳은 이전단계 다음 알파벳부터 C-뽑아야할 알파벳(L-cypher.size)

*/

void solution(int L, int C, vector<char> alpha, string cypher, int cur_index, int num_vowel, int num_consonent) {
	int cur_size = cypher.size();
	if (cur_size == L) {
		// 조건을 만족시킬 경우에만 출력
		if (num_vowel >= 1 && num_consonent >= 2) {
			cout << cypher << endl;
		}
		return;
	}

	for (int i = cur_index;i < C - (L - cur_size) + 1;i++) {
		if (vowel.find(alpha[i]) == string::npos) { // 자음일 경우
			solution(L, C, alpha, cypher + alpha[i], cur_index + (i - cur_index) + 1, num_vowel, num_consonent + 1);
		}
		else { // 모음일 경우
			solution(L, C, alpha, cypher + alpha[i], cur_index + (i - cur_index) + 1, num_vowel + 1, num_consonent);
		}
	}
	;
}

int main() {
	int L, C;
	char temp;
	cin >> L >> C;

	vector<char> alpha;

	for (int i = 0;i < C;i++) {
		cin >> temp;
		alpha.push_back(temp);
	}

	sort(alpha.begin(), alpha.end());

	solution(L, C, alpha, "", 0, 0, 0);

	return 0;
}