#include<iostream>
#include<vector>
#include<sstream>
#include<deque>
using namespace std;

void solution(string data, string pattern) {
	string stack;
	
	// 전체 문자열을 스택에 하나씩 넣기
	for (int i = 0; i < data.size(); i++) {
		stack += data[i];

		// 패턴 사이즈보다 커졌을 경우
		if (stack.size() >= pattern.size()) {
			// 패턴과 비교
			string temp = stack.substr(stack.size() - pattern.size());
			// 패턴이 발견되었을 경우
			if(temp == pattern) {
				int cnt = 0;
				// 스택의 맨 위에서 패턴이 가진 문자 개수만큼 pop 하기
				while (cnt < pattern.size()) {
					stack.pop_back();
					cnt++;
				}
			}
		}
	}
	if (stack.empty()) { // 패턴매칭이 완전히 이루어져 빈 문자열일 경우
		cout << "FRULA";
	}
	else { // 아닐 경우
		cout << stack;
	}
}

int main() {
	string data, pattern; // data: 전체 문자열, pattern: 폭탄 문자열

	cin >> data;
    	cin >> pattern;

	solution(data, pattern);

	return 0;
}
