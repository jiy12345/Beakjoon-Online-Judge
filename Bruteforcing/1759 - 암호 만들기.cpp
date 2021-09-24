#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string vowel = "aeiou";

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

	// 입력된 알파벳 오름차순으로 정렬
	sort(alpha.begin(), alpha.end());

	solution(L, C, alpha, "", 0, 0, 0);

	return 0;
}
